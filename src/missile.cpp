#include "missile.h"
#include "main.h"

Missile::Missile(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->Iden = glm::mat4(1.0f);
    this->spawn = 0;
    this->spawntime =0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100*9];

    float angle = 0;
    float rot_angle = 2*M_PI/100;

    for(int i=0;i<100;i++){
        vertex_buffer_data[9*i+0]=0.0;
        vertex_buffer_data[9*i+1]=0.0;
        vertex_buffer_data[9*i+2]=0.0;
        vertex_buffer_data[9*i+3]=0.3*cos(angle);
        vertex_buffer_data[9*i+4]=0.3*sin(angle);
        vertex_buffer_data[9*i+5]=0.8;
        vertex_buffer_data[9*i+6]=0.3*cos(angle+rot_angle);
        vertex_buffer_data[9*i+7]=0.3*sin(angle+rot_angle);
        vertex_buffer_data[9*i+8]=0.8;

    
        angle+=rot_angle;

    }
     GLfloat vertex_buffer_data2[200 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data2[i * 18 + 0]  = 0.3f * cos(angle);
     vertex_buffer_data2[i * 18 + 1]  = 0.3f * sin(angle);
     vertex_buffer_data2[i * 18 + 2]  = 0.8f;
     vertex_buffer_data2[i * 18 + 3]  = 0.3f * cos(angle);
     vertex_buffer_data2[i * 18 + 4]  = 0.3f * sin(angle);
     vertex_buffer_data2[i * 18 + 5]  = 2.0f;
     vertex_buffer_data2[i * 18 + 6]  = 0.3f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 7]  = 0.3f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 8]  = 0.8f;
     vertex_buffer_data2[i * 18 + 9]  = 0.3f * cos(angle);
     vertex_buffer_data2[i * 18 + 10] = 0.3f * sin(angle);
     vertex_buffer_data2[i * 18 + 11] = 2.0f;
     vertex_buffer_data2[i * 18 + 12] = 0.3f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 13] = 0.3f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 14] = 0.8f;
     vertex_buffer_data2[i * 18 + 15] = 0.3f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 16] = 0.3f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 17] = 2.0f;

     angle += rot_angle;

    };
  
    GLfloat vertex_buffer_data3[] ={
        0.3f,0.0f,2.0f,
        0.3f,0.0f,1.7f,
        0.7f,0.0f,2.0f,

        -0.3f,0.0f,2.0f,
        -0.3f,0.0f,1.7f,
        -0.7f,0.0f,2.0f,

        0.0f,0.3f,2.0f,
        0.0f,0.3f,1.7f,
        0.0f,0.7f,2.0f,

        0.0f,-0.3f,2.0f,
        0.0f,-0.3f,1.7f,
        0.0f,-0.7f,2.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data, COLOR_RED, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 200*3, vertex_buffer_data2, COLOR_WHITE, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data3, COLOR_RED, GL_FILL);
}


void Missile::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * this->Iden);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object3);
}

void Missile::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

