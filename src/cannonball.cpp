#include "cannonball.h"
#include "main.h"

Cannonball::Cannonball(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100*9*4];

    float angle = 0;
    float rot_angle = 2*M_PI/100;

    for(int i=0;i<100;i++){
        vertex_buffer_data[36*i+0]=9.0f + 0.0;
        vertex_buffer_data[36*i+1]=2.0;
        vertex_buffer_data[36*i+2]=0.0;
        vertex_buffer_data[36*i+3]=9.0f + 0.99*cos(angle);
        vertex_buffer_data[36*i+4]=1.2;
        vertex_buffer_data[36*i+5]=0.99*sin(angle);
        vertex_buffer_data[36*i+6]=9.0f + 0.99*cos(angle+rot_angle);
        vertex_buffer_data[36*i+7]=1.2;
        vertex_buffer_data[36*i+8]=0.99*sin(angle+rot_angle);

        vertex_buffer_data[36*i+9]=0.0;
        vertex_buffer_data[36*i+10]=2.0;
        vertex_buffer_data[36*i+11]=9.0f + 0.0;
        vertex_buffer_data[36*i+12]=0.99*cos(angle);
        vertex_buffer_data[36*i+13]=1.2;
        vertex_buffer_data[36*i+14]=9.0f + 0.99*sin(angle);
        vertex_buffer_data[36*i+15]=0.99*cos(angle+rot_angle);
        vertex_buffer_data[36*i+16]=1.2;
        vertex_buffer_data[36*i+17]=9.0f + 0.99*sin(angle+rot_angle);

        vertex_buffer_data[36*i+18]=-9.0f + 0.0;
        vertex_buffer_data[36*i+19]=2.0;
        vertex_buffer_data[36*i+20]=0.0;
        vertex_buffer_data[36*i+21]=-9.0f + 0.99*cos(angle);
        vertex_buffer_data[36*i+22]=1.2;
        vertex_buffer_data[36*i+23]=0.99*sin(angle);
        vertex_buffer_data[36*i+24]=-9.0f + 0.99*cos(angle+rot_angle);
        vertex_buffer_data[36*i+25]=1.2;
        vertex_buffer_data[36*i+26]=0.99*sin(angle+rot_angle);

        vertex_buffer_data[36*i+27]=0.0;
        vertex_buffer_data[36*i+28]=2.0;
        vertex_buffer_data[36*i+29]=-9.0f + 0.0;
        vertex_buffer_data[36*i+30]=0.99*cos(angle);
        vertex_buffer_data[36*i+31]=1.2;
        vertex_buffer_data[36*i+32]=-9.0f + 0.99*sin(angle);
        vertex_buffer_data[36*i+33]=0.99*cos(angle+rot_angle);
        vertex_buffer_data[36*i+34]=1.2;
        vertex_buffer_data[36*i+35]=-9.0f + 0.99*sin(angle+rot_angle);
    
        angle+=rot_angle;

    }
     GLfloat vertex_buffer_data2[800 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data2[i * 72 + 0]  = 9.0f + 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 1]  = 1.2f;
     vertex_buffer_data2[i * 72 + 2]  = 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 3]  = 9.0f + 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 4]  = 0.0f;
     vertex_buffer_data2[i * 72 + 5]  = 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 6]  = 9.0f + 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 7]  = 1.2f;
     vertex_buffer_data2[i * 72 + 8]  = 0.99f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 9]  = 9.0f + 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 10] = 0.0f;
     vertex_buffer_data2[i * 72 + 11] = 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 12] = 9.0f + 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 13] = 1.2f;
     vertex_buffer_data2[i * 72 + 14] = 0.99f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 15] = 9.0f + 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 16] = 0.0f;
     vertex_buffer_data2[i * 72 + 17] = 0.99f * sin(angle + rot_angle);

     vertex_buffer_data2[i * 72 + 18]  = -9.0f +0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 19]  = 1.2f;
     vertex_buffer_data2[i * 72 + 20]  = 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 21]  = -9.0f +0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 22]  = 0.0f;
     vertex_buffer_data2[i * 72 + 23]  = 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 24]  = -9.0f +0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 25]  = 1.2f;
     vertex_buffer_data2[i * 72 + 26]  = 0.99f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 27]  = -9.0f +0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 28]  = 0.0f;
     vertex_buffer_data2[i * 72 + 29]  = 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 30]  = -9.0f +0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 31]  = 1.2f;
     vertex_buffer_data2[i * 72 + 32]  = 0.99f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 33]  = -9.0f +0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 34]  = 0.0f;
     vertex_buffer_data2[i * 72 + 35]  = 0.99f * sin(angle + rot_angle);

     vertex_buffer_data2[i * 72 + 36]  = 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 37]  = 1.2f;
     vertex_buffer_data2[i * 72 + 38]  = 9.0f + 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 39]  = 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 40]  = 0.0f;
     vertex_buffer_data2[i * 72 + 41]  = 9.0f + 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 42]  = 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 43]  = 1.2f;
     vertex_buffer_data2[i * 72 + 44]  = 9.0f + 0.99f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 45]  = 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 46]  = 0.0f;
     vertex_buffer_data2[i * 72 + 47]  = 9.0f + 0.99f * sin(angle);
     vertex_buffer_data2[i * 72 + 48]  = 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 49]  = 1.2f;
     vertex_buffer_data2[i * 72 + 50]  = 9.0f + 0.99f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 51]  = 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 52]  = 0.0f;
     vertex_buffer_data2[i * 72 + 53]  = 9.0f + 0.99f * sin(angle + rot_angle);

     vertex_buffer_data2[i * 72 + 54]  = 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 55]  = 1.2f;
     vertex_buffer_data2[i * 72 + 56]  = -9.0f +0.99f  * sin(angle);
     vertex_buffer_data2[i * 72 + 57]  = 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 58]  = 0.0f;
     vertex_buffer_data2[i * 72 + 59]  = -9.0f +0.99f  * sin(angle);
     vertex_buffer_data2[i * 72 + 60]  = 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 61]  = 1.2f;
     vertex_buffer_data2[i * 72 + 62]  = -9.0f +0.99f  * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 63]  = 0.99f * cos(angle);
     vertex_buffer_data2[i * 72 + 64]  = 0.0f;
     vertex_buffer_data2[i * 72 + 65]  = -9.0f +0.99f  * sin(angle);
     vertex_buffer_data2[i * 72 + 66]  = 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 67]  = 1.2f;
     vertex_buffer_data2[i * 72 + 68]  = -9.0f +0.99f  * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 69]  = 0.99f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 70]  = 0.0f;
     vertex_buffer_data2[i * 72 + 71]  = -9.0f +0.99f  * sin(angle + rot_angle);

     angle += rot_angle;

    };
  

    this->object = create3DObject(GL_TRIANGLES, 100*3*4, vertex_buffer_data, COLOR_DODGER_BLUE, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 800*3, vertex_buffer_data2, COLOR_DODGER_BLUE, GL_FILL);
}


void Cannonball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object);
}

void Cannonball::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

