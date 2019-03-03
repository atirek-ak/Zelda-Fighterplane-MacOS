#include "smoke.h"
#include "main.h"

Smoke::Smoke(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->spawn = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100*9];

    float angle = 0;
    float rot_angle = 2*M_PI/100;

     GLfloat vertex_buffer_data2[200 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data2[i * 18 + 0]  = 5.3f * cos(angle);
     vertex_buffer_data2[i * 18 + 1]  = 0.0;
     vertex_buffer_data2[i * 18 + 2]  = 5.3f * sin(angle);
     vertex_buffer_data2[i * 18 + 3]  = 5.3f * cos(angle);
     vertex_buffer_data2[i * 18 + 4]  = 0.8f;
     vertex_buffer_data2[i * 18 + 5]  = 5.3f * sin(angle);
     vertex_buffer_data2[i * 18 + 6]  = 5.3f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 7]  = 0.0f;
     vertex_buffer_data2[i * 18 + 8]  = 5.3f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 9]  = 5.3f * cos(angle);
     vertex_buffer_data2[i * 18 + 10] = 0.8f;
     vertex_buffer_data2[i * 18 + 11] = 5.3f * sin(angle);
     vertex_buffer_data2[i * 18 + 12] = 5.3f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 13] = 0.0f;
     vertex_buffer_data2[i * 18 + 14] = 5.3f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 15] = 5.3f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 16] = 0.8f;
     vertex_buffer_data2[i * 18 + 17] = 5.3f * sin(angle + rot_angle);

     angle += rot_angle;

    };
  
    this->object1 = create3DObject(GL_TRIANGLES, 200*3, vertex_buffer_data2, COLOR_DARK_SLATE_GRAY, GL_FILL);
}


void Smoke::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    //draw3DObject(this->object);
    draw3DObject(this->object1);
    //draw3DObject(this->object3);
}

void Smoke::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

