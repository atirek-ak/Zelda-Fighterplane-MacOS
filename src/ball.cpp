#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rot_yaw = 0;
    this->rot_pitch = 0;
    this->rot_roll = 0;
    this->speed = 0;
    this->axis_speed = 0;
    this->Iden = glm::mat4(1.0f);
    this->control=1;
    this->fuel = 100;
    this->barrel_roll=0;
    this->loop=0;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100*9];

    float angle = 0;
    float rot_angle = 2*M_PI/100;

    for(int i=0;i<100;i++){
        vertex_buffer_data[9*i]=0.0;
        vertex_buffer_data[9*i+1]=0.0;
        vertex_buffer_data[9*i+2]=0.0;

        vertex_buffer_data[9*i+3]=0.5*cos(angle);
        vertex_buffer_data[9*i+4]=0.5*sin(angle);
        vertex_buffer_data[9*i+5]=0.3;

        vertex_buffer_data[9*i+6]=0.5*cos(angle+rot_angle);
        vertex_buffer_data[9*i+7]=0.5*sin(angle+rot_angle);
        vertex_buffer_data[9*i+8]=0.3;
    
        angle+=rot_angle;

    }
    GLfloat vertex_buffer_data1[200*9];
    angle=0;

    for(int i=0;i<100;i++){
        vertex_buffer_data1[18*i]=0.5*cos(angle);
        vertex_buffer_data1[18*i+1]=0.5*sin(angle);
        vertex_buffer_data1[18*i+2]=0.3;

        vertex_buffer_data1[18*i+3]=0.5*cos(angle);
        vertex_buffer_data1[18*i+4]=0.5*sin(angle);
        vertex_buffer_data1[18*i+5]=4;

        vertex_buffer_data1[18*i+6]=0.5*cos(angle+rot_angle);
        vertex_buffer_data1[18*i+7]=0.5*sin(angle+rot_angle);
        vertex_buffer_data1[18*i+8]=0.3;

        vertex_buffer_data1[18*i+9]=0.5*cos(angle+rot_angle);
        vertex_buffer_data1[18*i+10]=0.5*sin(angle+rot_angle);
        vertex_buffer_data1[18*i+11]=0.3;

        vertex_buffer_data1[18*i+12]=0.5*cos(angle+rot_angle);
        vertex_buffer_data1[18*i+13]=0.5*sin(angle+rot_angle);
        vertex_buffer_data1[18*i+14]=4;

        vertex_buffer_data1[18*i+15]=0.5*cos(angle);
        vertex_buffer_data1[18*i+16]=0.5*sin(angle);
        vertex_buffer_data1[18*i+17]=4;

        angle+=rot_angle;

    }

    GLfloat vertex_buffer_data2[]={
        0.5, 0, 1.5,
        0.5, 0, 3,
        3, 0, 1.7,

        -0.5, 0, 1.5,
        -0.5, 0, 3,
        -3, 0, 1.7,

    };
  

    this->object = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data, COLOR_RED, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 200*3, vertex_buffer_data1, COLOR_RED, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
}


void Ball::roll(float rot){
    glm::mat4 rot_mat = glm::rotate(rot/36, glm::vec3(this->Iden[2][0],this->Iden[2][1],this->Iden[2][2]) );
    //std::cout << Iden[0][0] << "," << Iden[0][1] << "," << Iden[0][2] << std::endl;
    this->Iden = rot_mat * this->Iden ;
}

void Ball::yaw(float rot){
    glm::mat4 rot_mat = glm::rotate(rot/36, glm::vec3(this->Iden[1][0],this->Iden[1][1],this->Iden[1][2]) );
    this->Iden = rot_mat * this->Iden ;
}

void Ball::pitch(float rot){
    glm::mat4 rot_mat = glm::rotate(rot/36, glm::vec3(this->Iden[0][0],this->Iden[0][1],this->Iden[0][2]) );
    this->Iden = rot_mat * this->Iden ;
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * this->Iden);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    //draw3DObject(this->object3);
}

void Ball::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Ball::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

