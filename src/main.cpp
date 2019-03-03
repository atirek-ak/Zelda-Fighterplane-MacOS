#include "main.h"
#include "timer.h"
#include "ball.h"
#include "sea.h"
#include "smoke.h"
#include "target.h"
#include "cannonball.h"
#include "missile.h"
#include "dashboard.h"
#include "volcano.h"
#include "speedometer.h"
#include "fuel.h"
#include "altitude.h"
#include "fuelcan.h"
#include "parachute.h"
#include "compass.h"
#include "bomb.h"
#include "arrow.h"

using namespace std;

GLMatrices Matrices, Matrices1;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;
Bomb bomb1;
Sea sea1;
Dashboard dashboard1;
Fuelcan fuelcan1[5];
Speedometer speedometer1;
Compass compass1;
Altitude altitude1;
Fuel fuel1;
Parachute parachute1[5];
Cannonball cannonball1[5];
Missile missile1;
Volcano volcano1[5];
Smoke smoke1[5];
Target target1[5];
Arrow arrow1;

float mouse_x_rad = 0, mouse_y_rad = 0;
double ini_cur_x = 0, ini_cur_y = 0;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
float set_eye[3],set_target[3],set_up[3];
string camera_view="follow-cam";
int pause_time, hover=0;
int active =0, score=0;
double x_unit,y_unit,z_unit;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye ( set_eye[0] , set_eye[1], set_eye[2] );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (set_target[0], set_target[1], set_target[2]);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (set_up[0], set_up[1], set_up[2]);

    //2nd Cam
    glm::vec3 eye2 ( 0 , 0, 0.1 );
    glm::vec3 target2 ( 0 , 0, 0 );
    glm::vec3 up2 ( 0 , 1, 0 );

    Matrices1.view = glm::lookAt(eye2, target2, up2);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY ball1

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    glm::mat4 VP1 = Matrices1.projection * Matrices1.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model
    glm::mat4 MVP2;

    // Scene render
    sea1.draw(VP);
    glm::vec3 arrow_coords = ball1.position;
    glm::vec3 unit_vector;
     unit_vector.x = x_unit;
     unit_vector.y = y_unit;
     unit_vector.z = z_unit;
    arrow_coords.y += 1;
    arrow1.draw(VP, arrow_coords, unit_vector);
    dashboard1.draw(VP1);
    speedometer1.draw(VP1);
    compass1.draw(VP1);
    altitude1.draw(VP1);
    fuel1.draw(VP1);
    bomb1.draw(VP);
    missile1.draw(VP);
    ball1.draw(VP);
    for(int i=0;i<5;i++)
    {
        fuelcan1[i].draw(VP);
        target1[i].draw(VP);
        smoke1[i].draw(VP);
        parachute1[i].draw(VP);
        cannonball1[i].draw(VP);
        volcano1[i].draw(VP);
    }
}

void tick_input(GLFWwindow *window) {
    int a  = glfwGetKey(window, GLFW_KEY_A);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int q  = glfwGetKey(window, GLFW_KEY_Q);
    int e = glfwGetKey(window, GLFW_KEY_E);
    int w = glfwGetKey(window, GLFW_KEY_W);
    int two = glfwGetKey(window, GLFW_KEY_2);
    int s = glfwGetKey(window, GLFW_KEY_S);
    int r = glfwGetKey(window, GLFW_KEY_R);
    int l = glfwGetKey(window, GLFW_KEY_L);
    int f = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1);
    int b = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);


    
    if (a) {
        ball1.roll(1.0f);
    }
    else if (d) {
        ball1.roll(-1.0f);
    }
    else if (q) {
        ball1.yaw(1.0f);
    }
    else if (e) {
        ball1.yaw(-1.0f);
    }
    else if (two) {
        ball1.pitch(-1.0f);
     }
     else if(w){
        ball1.axis_speed += 0.05f;   
        //set_eye[0] -=ball1.Iden[2][0];
        //set_eye[1] -=ball1.Iden[2][1];
        //set_eye[2] -=ball1.Iden[2][2];
        //set_target[0] -=ball1.Iden[2][0];
		//set_target[1] -=ball1.Iden[2][1];
		//set_target[2] -=ball1.Iden[2][2];
    }
    else if (s) {
        ball1.pitch(1.0f);
    }
    else if(f){
        if(!missile1.spawn)
            missile_spawn();
    }
    else if(b)
    {
        if(!bomb1.spawn)
        {
            bomb1.spawn = 1;
            bomb1.position.x = ball1.position.x - 1.5 * ball1.Iden[1][0] + 1.5 * ball1.Iden[2][0];
            bomb1.position.y = ball1.position.y - 1.5 * ball1.Iden[1][1] + 1.5 * ball1.Iden[2][1];
            bomb1.position.z = ball1.position.z - 1.5 * ball1.Iden[1][2] + 1.5 * ball1.Iden[2][2];
        }
    }
    else if(r){
        ball1.control = 0;
        ball1.barrel_roll = 221;
    }
    else if(l){
        ball1.control = 0;
        ball1.loop = 223;
        ball1.axis_speed = 2.0f;
        ball1.speed = 0;
        hover = 1;
    }
    else if(space){
    	if(ball1.speed<0)
	    	ball1.speed += 0.05f;
	    else
	    	ball1.speed+=0.1f;
    }

}

void missile_spawn(){
    missile1.position.x = ball1.position.x - 1.5 * ball1.Iden[1][0] - 0.5 * ball1.Iden[2][0]; 
    missile1.position.y = ball1.position.y - 1.5 * ball1.Iden[1][1] - 0.5 * ball1.Iden[2][1]; 
    missile1.position.z = ball1.position.z - 1.5 * ball1.Iden[1][2] - 0.5 * ball1.Iden[2][2]; 
    missile1.Iden = ball1.Iden;
    missile1.spawn = 1;
}

void update_camera_coords()
{
	if(camera_view=="follow-cam")
		{
			//set_camera_coords(0,0,-1,0,0,-2,0,1,0);
    		//set_camera_coords(ball1.position.x + 0,ball1.position.y + 0,ball1.position.z - (1),ball1.position.x + 0,ball1.position.y + 0,ball1.position.z - 2,ball1.position.x + 0,ball1.position.y + 1,ball1.position.z + 0);
			set_eye[0] = ball1.position.x + 2 * ball1.Iden[1][0] + 10 * ball1.Iden[2][0]; 
			set_eye[1] = ball1.position.y + 2 * ball1.Iden[1][1] + 10 * ball1.Iden[2][1]; 
			set_eye[2] = ball1.position.z + 2 * ball1.Iden[1][2] + 10 * ball1.Iden[2][2]; 
			set_target[0] = ball1.position.x;
			set_target[1] = ball1.position.y;
			set_target[2] = ball1.position.z;
			set_up[0] = ball1.Iden[1][0] ;
			set_up[1] = ball1.Iden[1][1] ;
			set_up[2] = ball1.Iden[1][2] ;
		}
		else if(camera_view=="ball1-view")
		{
			//set_camera_coords(0,30,1.5,0,0,0,0,30,-1);
    		//set_camera_coords(ball1.position.x + 0,ball1.position.y + 30,ball1.position.z + 1.5,ball1.position.x + 0,ball1.position.y + 0,ball1.position.z + 0,ball1.position.x + 0,ball1.position.y + 30,ball1.position.z - 1);
			set_eye[0] = ball1.position.x - 1 * ball1.Iden[2][0]; 
			set_eye[1] = ball1.position.y - 1 * ball1.Iden[2][1]; 
			set_eye[2] = ball1.position.z - 1 * ball1.Iden[2][2]; 
			set_target[0] = ball1.position.x - 2 * ball1.Iden[2][0];
			set_target[1] = ball1.position.y - 2 * ball1.Iden[2][1];
			set_target[2] = ball1.position.z - 2 * ball1.Iden[2][2];
			set_up[0] = ball1.Iden[1][0] ;
			set_up[1] = ball1.Iden[1][1] ;
			set_up[2] = ball1.Iden[1][2] ;
		}
		else if(camera_view=="top-view")
		{
			set_eye[0] = ball1.position.x + 30 * ball1.Iden[1][0]; 
			set_eye[1] = ball1.position.y + 30 * ball1.Iden[1][1];
			set_eye[2] = ball1.position.z + 30 * ball1.Iden[1][2];
			set_target[0] = ball1.position.x;
			set_target[1] = ball1.position.y;
			set_target[2] = ball1.position.z;
			set_up[0] = -ball1.Iden[2][0];
			set_up[1] = -ball1.Iden[2][1];
			set_up[2] = -ball1.Iden[2][2];
		}
		else if(camera_view=="tower-view")
		{
			//set_camera_coords(0,2,10,0,0,0,0,1,0);
    		set_eye[0] = ball1.position.x + 10 * (ball1.Iden[0][0] + ball1.Iden[1][0] + ball1.Iden[2][0]);
            set_eye[1] = ball1.position.y + 10 * (ball1.Iden[0][1] + ball1.Iden[1][1] + ball1.Iden[2][1]);
            set_eye[2] = ball1.position.z + 10 * (ball1.Iden[0][2] + ball1.Iden[1][2] + ball1.Iden[2][2]);
            set_target[0] = ball1.position.x;
            set_target[1] = ball1.position.y;
            set_target[2] = ball1.position.z;
            set_up[0] = (ball1.Iden[0][0] + ball1.Iden[1][0] - ball1.Iden[2][0]);
            set_up[1] = (ball1.Iden[0][1] + ball1.Iden[1][1] - ball1.Iden[2][1]);
            set_up[2] = (ball1.Iden[0][2] + ball1.Iden[1][2] - ball1.Iden[2][2]);
		}
        else if(camera_view == "helicopter")
        {
            glm::vec4 eye1 = glm::vec4(ball1.position.x+20*ball1.Iden[2][0]+4*ball1.Iden[1][0],ball1.position.y+20*ball1.Iden[2][1]+4*ball1.Iden[1][1],ball1.position.z+20*ball1.Iden[2][2]+4*ball1.Iden[1][2],1);
            glm::vec3 target = glm::vec3(ball1.position.x - ball1.Iden[2][0],ball1.position.y  - ball1.Iden[2][1] ,ball1.position.z - ball1.Iden[2][2]);
            glm::vec4 eye2 = glm::translate(target)*glm::rotate(-mouse_x_rad,glm::vec3(0,1,0))*glm::translate(-target)*eye1;
            glm::vec3 eye = glm::vec3(eye2);
            glm::vec3 y_rot_vec = glm::vec3( set_eye[2]-set_target[2],0,set_eye[0]-set_target[0]);
            eye = glm::vec3(glm::translate(target)*glm::rotate(-mouse_y_rad,glm::vec3(y_rot_vec[0],y_rot_vec[1],y_rot_vec[2]))*glm::translate(-target)*eye2);
            set_eye[0] = eye[0];
            set_eye[1] = eye[1];
            set_eye[2] = eye[2];
            set_target[0] = ball1.position.x;
            set_target[1] = ball1.position.y;
            set_target[2] = ball1.position.z;
            set_up[0] = 0;
            set_up[1] = 1;
            set_up[2] = 0;
        }
}

//Change Camera View
void change_camera_view(GLFWwindow *window)
{
	int c = glfwGetKey(window,GLFW_KEY_C);
    int k = glfwGetKey(window, GLFW_KEY_K);

	if(pause_time==15)
	{
		pause_time=0;
	}
	else if(pause_time)
	{
		pause_time+=1;
		return;
	}


	if(c)
	{
		if(camera_view=="follow-cam")
		{
			camera_view="ball1-view";
			//set_camera_coords(0,0,-1,0,0,-2,0,1,0);
			set_eye[0] = ball1.position.x - 1 * ball1.Iden[2][0]; 
            set_eye[1] = ball1.position.y - 1 * ball1.Iden[2][1]; 
            set_eye[2] = ball1.position.z - 1 * ball1.Iden[2][2]; 
            set_target[0] = ball1.position.x - 2 * ball1.Iden[2][0];
            set_target[1] = ball1.position.y - 2 * ball1.Iden[2][1];
            set_target[2] = ball1.position.z - 2 * ball1.Iden[2][2];
            set_up[0] = ball1.Iden[1][0] ;
            set_up[1] = ball1.Iden[1][1] ;
            set_up[2] = ball1.Iden[1][2] ;
            pause_time =1;
		}
		else if(camera_view=="ball1-view")
		{
			camera_view="top-view";
			//set_camera_coords(0,30,1.5,0,0,0,0,30,-1);
            set_eye[0] = ball1.position.x + 30 * ball1.Iden[1][0]; 
            set_eye[1] = ball1.position.y + 30 * ball1.Iden[1][1];
            set_eye[2] = ball1.position.z + 30 * ball1.Iden[1][2];
            set_target[0] = ball1.position.x;
            set_target[1] = ball1.position.y;
            set_target[2] = ball1.position.z;
            set_up[0] = -ball1.Iden[2][0];
            set_up[1] = -ball1.Iden[2][1];
            set_up[2] = -ball1.Iden[2][2];
			pause_time=1;
		}
		else if(camera_view=="top-view")
		{
			camera_view="tower-view";
			//set_camera_coords(10,10,10,0,0,0,11,11,9);
            set_eye[0] = ball1.position.x + 10 * (ball1.Iden[0][0] + ball1.Iden[1][0] + ball1.Iden[2][0]);
            set_eye[1] = ball1.position.y + 10 * (ball1.Iden[0][1] + ball1.Iden[1][1] + ball1.Iden[2][1]);
            set_eye[2] = ball1.position.z + 10 * (ball1.Iden[0][2] + ball1.Iden[1][2] + ball1.Iden[2][2]);
            set_target[0] = ball1.position.x;
            set_target[1] = ball1.position.y;
            set_target[2] = ball1.position.z;
            set_up[0] = (ball1.Iden[0][0] + ball1.Iden[1][0] - ball1.Iden[2][0]);
            set_up[1] = (ball1.Iden[0][1] + ball1.Iden[1][1] - ball1.Iden[2][1]);
            set_up[2] = (ball1.Iden[0][2] + ball1.Iden[1][2] - ball1.Iden[2][2]);

			pause_time=1;
		}
		else if(camera_view=="tower-view")
		{
			camera_view="helicopter";
			//set_camera_coords(0,2,10,0,0,0,0,1,0);
			glm::vec4 eye1 = glm::vec4(ball1.position.x+20*ball1.Iden[2][0]+4*ball1.Iden[1][0],ball1.position.y+20*ball1.Iden[2][1]+4*ball1.Iden[1][1],ball1.position.z+20*ball1.Iden[2][2]+4*ball1.Iden[1][2],1);
            glm::vec3 target = glm::vec3(ball1.position.x - ball1.Iden[2][0],ball1.position.y  - ball1.Iden[2][1] ,ball1.position.z - ball1.Iden[2][2]);
            glm::vec4 eye2 = glm::translate(target)*glm::rotate(-mouse_x_rad,glm::vec3(0,1,0))*glm::translate(-target)*eye1;
            glm::vec3 eye = glm::vec3(eye2);
            glm::vec3 y_rot_vec = glm::vec3( set_eye[2]-set_target[2],0,set_eye[0]-set_target[0]);
            eye = glm::vec3(glm::translate(target)*glm::rotate(-mouse_y_rad,glm::vec3(y_rot_vec[0],y_rot_vec[1],y_rot_vec[2]))*glm::translate(-target)*eye2);
            set_eye[0] = eye[0];
            set_eye[1] = eye[1];
            set_eye[2] = eye[2];
            set_target[0] = ball1.position.x;
            set_target[1] = ball1.position.y;
            set_target[2] = ball1.position.z;
            set_up[0] = 0;
            set_up[1] = 1;
            set_up[2] = 0;
            pause_time =1;
		}
        else if(camera_view == "helicopter")
        {
            camera_view="follow-cam";
            set_eye[0] = ball1.position.x + 2 * ball1.Iden[1][0] + 10 * ball1.Iden[2][0]; 
            set_eye[1] = ball1.position.y + 2 * ball1.Iden[1][1] + 10 * ball1.Iden[2][1]; 
            set_eye[2] = ball1.position.z + 2 * ball1.Iden[1][2] + 10 * ball1.Iden[2][2]; 
            set_target[0] = ball1.position.x;
            set_target[1] = ball1.position.y;
            set_target[2] = ball1.position.z;
            set_up[0] = ball1.Iden[1][0] ;
            set_up[1] = ball1.Iden[1][1] ;
            set_up[2] = ball1.Iden[1][2] ;
            pause_time=1;
        }
	}
	else if(k)
    {
    	hover=1-hover;
		pause_time=1;
    }
}

void tick_elements() {
    //Score
    score += 1;
    ostringstream str1;
    str1<<"Score: "<<int(score);
    string str = "Score:" + to_string(score);
    glfwSetWindowTitle(window, str1.str().c_str() );
    // cout << score << endl;
    //Sea
    sea1.set_position(ball1.position.x, 0, ball1.position.z);

    //Cannonball
    if(cannonball1[active].position.y<90)
        cannonball1[active].position.y+=0.33f;
    else
        cannonball1[active].position.y=-9.99f;

    //Ball
    if(ball1.position.y>80)
    {
        ball1.control=0;
        if(ball1.axis_speed>0)
            ball1.axis_speed -= 0.3f;
        if(ball1.speed>0)
            ball1.speed -= 0.3f;
        else
            ball1.speed-= 0.05f;
    }
    else
        ball1.control = 1;

    if(ball1.axis_speed > 0)
        ball1.axis_speed -= 0.005f;
    else if(ball1.axis_speed < 0)
        ball1.axis_speed = 0;
    ball1.position.x -=ball1.axis_speed * ball1.Iden[2][0]/5;
    ball1.position.y -=ball1.axis_speed * ball1.Iden[2][1]/5;
    ball1.position.z -=ball1.axis_speed * ball1.Iden[2][2]/5;

    if(ball1.axis_speed > 5)
        ball1.axis_speed = 5;

    ball1.fuel -= 0.02;
    if(ball1.fuel <= 0)
        quit(window);

    if(ball1.barrel_roll)
    {
        ball1.barrel_roll--;
        ball1.roll(-1.0f);
        if(!ball1.barrel_roll)
        {
            ball1.control=1;
        }
    }
    if(ball1.loop)
    {
        ball1.loop--;
        ball1.pitch(1.0f);
        if(!ball1.loop)
        {
            hover = 0;
            ball1.control=1;
        }
    }



    //Missile
    if(missile1.spawn)
    {
        missile1.position.x -= 0.4 *  missile1.Iden[2][0];
        missile1.position.y -= 0.4 *  missile1.Iden[2][1];
        missile1.position.z -= 0.4 *  missile1.Iden[2][2];
        missile1.spawntime += 1;
        if(missile1.spawntime>= 180)
        {
            missile1.spawn =0;
            missile1.spawntime = 0;
            missile1.position. y = -15;
        }
    }

    //Bomb
    if(bomb1.spawn)
    {
        bomb1.position.y -= 0.25f;
        if(bomb1.position.y < -10.0f)
        {
            bomb1.position.y = -15.05f;
            bomb1.spawn = 0;
        }
    }

    //Speedometer
    speedometer1 = Speedometer(-3.5, -3.5, 0, ball1.axis_speed);

    //Compass
    compass1 = Compass(-0.5,-3.5,0,-glm::vec3(ball1.Iden[2]));

    //Altitude
    altitude1 = Altitude(-2.5,-3.5,0,ball1.position.y);

    //Fuel 
    fuel1 = Fuel(-1.5,-3.5,0, ball1.fuel);

    //Arrow
    double a1 = target1[active].position.x;
    double a2 = target1[active].position.y;
    double a3 = target1[active].position.z;
    double b1 = arrow1.position.x;
    double b2 = arrow1.position.y;
    double b3 = arrow1.position.z;

    double a = sqrt((a1-b1)*(a1-b1) + (a2-b2)*(a2-b2) + (a3-b3)*(a3-b3));

     x_unit = (a1-b1)/a; 
     y_unit = (a2-b2)/a; 
     z_unit = (a3-b3)/a; 
    //glm::vec3 (a,b,c);
}

void gravity()
{
	if(hover)
		ball1.speed=0;
	ball1.position.y += ball1.speed/10;
	ball1.speed -= 1/300.0f;
}

void check_above_volcano()
{
    double x = ball1.position.x + 2 * ball1.Iden[2][0];
    double y = ball1.position.y + 2 * ball1.Iden[2][1];
    double z = ball1.position.z + 2 * ball1.Iden[2][2];
    for(int i=0;i<5;i++)
    {
        //Volcano
        if(calculate(x,volcano1[i].position.x,y,volcano1[i].position.y,z,volcano1[i].position.z,10.0))
        {
            //cout << "Plane `was directly above volcano" << endl;
            quit(window);
        }

        //Fuelcan
        if(calculate(x,fuelcan1[i].position.x + 0.25f,y,fuelcan1[i].position.y + 1.0f,z,fuelcan1[i].position.z + 0.5f,2.5f))
        {
            ball1.fuel +=40;
            if(ball1.fuel > 100)
                ball1.fuel = 100;
            fuelcan1[i].position.y = -50.0f;
        }

        //Smoke Ring
        if(abs(y-smoke1[i].position.y) < 0.4 && calculate(x,smoke1[i].position.x,0,0,z,smoke1[i].position.z,5.3))
        {
            score +=10000;
            smoke1[i].position.y = -100;
        }

        //Parachute
        if(calculate(x,parachute1[i].position.x,y,parachute1[i].position.y,z,parachute1[i].position.z,3))
            quit(window);
    }
    //Sea
    if(calculate(x,x,y,-10,z,z,2.0))
        quit(window);

    double x1 = cannonball1[active].position.x;
    double y1 = cannonball1[active].position.y;
    double z1 = cannonball1[active].position.z;

    if(calculate(x,x1+9,y,y1,z,z1,2.0f) || calculate(x,x1-9,y,y1,z,z1,2.0f) || calculate(x,x1,y,y1,z,z1+9,2.0f) || calculate(x,x1,y,y1,z,z1-9,2.0f))
        quit(window);

    //Missile
    x = missile1.position.x;
    y = missile1.position.y;
    z = missile1.position.z;
    for(int i=0;i<5;i++)
    {
    if(calculate(x,volcano1[i].position.x,y,volcano1[i].position.y,z,volcano1[i].position.z,10.0))
    {
        missile1.spawn =0;
        missile1.spawntime = 0;
        missile1.position. y = -15;
    }
        if(calculate(x,target1[i].position.x,z,target1[i].position.z,0,0,8.0) && abs(y)-10<0.5 && active==i)
        {
            active++;
            target1[i].position.y = -100;
            cannonball1[i].position.y = -100;
            if(active == 5)
                quit(window);
            missile1.spawn =0;
            missile1.spawntime = 0;
            missile1.position. y = -15;
        }

        if(calculate(x,parachute1[i].position.x,y,parachute1[i].position.y,z,parachute1[i].position.z,2))
        {
            missile1.spawn =0;
            missile1.spawntime = 0;
            missile1.position. y = -15;
            parachute1[i].position.y = -100;
            score += 1000;
        }

    }

    //Bomb
    x = bomb1.position.x;
    y = bomb1.position.y;
    z = bomb1.position.z;

    for(int i=0;i<5;i++)
    {
    if(calculate(x,volcano1[i].position.x,y,volcano1[i].position.y,z,volcano1[i].position.z,10.0))
    {
        bomb1.spawn =0;
        bomb1.position. y = -15;
    }
        if(calculate(x,target1[i].position.x,z,target1[i].position.z,0,0,8.0) && abs(y)-10<0.3 && active==i)
        {
            active++;
            target1[i].position.y = -100;
            cannonball1[i].position.y = -100;
            if(active == 5)
                quit(window);
            bomb1.spawn =0;
            bomb1.position. y = -15;
        }
    }

}

int calculate(double x1,double x2,double y1,double y2,double z1,double z2, double r)
{
    if(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))<=r)
        return 1;
    else
        return 0;
}



/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    ball1       = Ball(0, 10);
    sea1 = Sea(0,0);
    dashboard1 = Dashboard(-3.5,-3.5,0);
    speedometer1 = Speedometer(-3.5,-3.5,0,0);
    compass1 = Compass(-0.5,-3.5,0,-glm::vec3(ball1.Iden[2]));
    altitude1 = Altitude(-2.5f,-3.5f,0,0);
    fuel1 = Fuel(-1.5f,-3.5f,0,100);
    arrow1 = Arrow(0,0,0);
    bomb1 = Bomb(10,-15,0);
    missile1 = Missile(0,-15,0);

    //Parachutes
    parachute1[0] = Parachute(70,40,0);
    parachute1[1] = Parachute(-40,50,90);
    parachute1[2] = Parachute(-60,57,10);
    parachute1[3] = Parachute(0,46,90);
    parachute1[4] = Parachute(20,20,-40);


    //Fuel Cans
    fuelcan1[0] = Fuelcan(80,10,0);
    fuelcan1[1] = Fuelcan(-50,20,100);
    fuelcan1[2] = Fuelcan(-80,0,20);
    fuelcan1[3] = Fuelcan(0,15,110);
    fuelcan1[4] = Fuelcan(30,20,-50);

    
    //Smoke Rings
    smoke1[0] = Smoke(10,0,0);
    smoke1[1] = Smoke(50,10,-30);
    smoke1[2] = Smoke(30,60,70);
    smoke1[3] = Smoke(40,20,0);
    smoke1[4] = Smoke(-50,30,50);

    //Volcano
    volcano1[0] = Volcano(70,-10,0);
    volcano1[1] = Volcano(40,-10,0);
    volcano1[2] = Volcano(-85,-10,80);
    volcano1[3] = Volcano(0,-10,70);
    volcano1[4] = Volcano(30,-10,-50);

    //Target
    cannonball1[0] = Cannonball(100,-9.99,0);
    target1[0] = Target(100, -9.99, 0);
    cannonball1[1] = Cannonball(-70,-9.99,100);
    target1[1] = Target(-70, -9.99, 100);
    cannonball1[2] = Cannonball(-100,-9.99,0);
    target1[2] = Target(-100, -9.99, 0);
    cannonball1[3] = Cannonball(0,-9.99,90);
    target1[3] = Target(0, -9.99, 90);
    cannonball1[4] = Cannonball(50,-9.99,-50);
    target1[4] = Target(50, -9.99, -50);

    //set initial camera coordinates
    set_camera_coords(ball1.position.x + 0,ball1.position.y + 2,ball1.position.z + 10,ball1.position.x + 0,ball1.position.y + 0,ball1.position.z + 0,ball1.position.x + 0,ball1.position.y + 1,ball1.position.z + 0);
    
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");
    Matrices1.MatrixID = glGetUniformLocation(programID, "MVP2");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 1000;
    int height = 1000;

    window = initGLFW(width, height);

    initGL (window, width, height);


    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            if(ball1.control)
                tick_input(window);
			update_camera_coords();
            change_camera_view(window);
            gravity();
            check_above_volcano();
            //cout << "1" << endl;
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

void set_camera_coords(float eye1, float eye2, float eye3, float target1, float target2, float target3, float up1, float up2, float up3)
{
	set_eye[0] = eye1;
    set_eye[1] = eye2;
    set_eye[2] = eye3;
    set_target[0] = target1;
    set_target[1] = target2;
    set_target[2] = target3;
    set_up[0] = up1;
    set_up[1] = up2;
    set_up[2] = up3;
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(45.0f, 1.0f, 1.0f, 100.0f);
    Matrices1.projection = glm::ortho(left, right,bottom, top);

}
