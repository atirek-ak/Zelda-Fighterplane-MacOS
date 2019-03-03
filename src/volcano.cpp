#include "volcano.h"
#include "main.h"

Volcano::Volcano(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    
    float angle=0, rot_angle= 2 * M_PI / 100;
    GLfloat vertex_buffer_data2[200 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data2[i * 18 + 0]  = 5.0f * cos(angle);
     vertex_buffer_data2[i * 18 + 1]  = 5.0f;
     vertex_buffer_data2[i * 18 + 2]  = 5.0f * sin(angle);
     vertex_buffer_data2[i * 18 + 3]  = 8.0f * cos(angle);
     vertex_buffer_data2[i * 18 + 4]  = 0.0f;
     vertex_buffer_data2[i * 18 + 5]  = 8.0f * sin(angle);
     vertex_buffer_data2[i * 18 + 6]  = 5.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 7]  = 5.0f;
     vertex_buffer_data2[i * 18 + 8]  = 5.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 9]  = 8.0f * cos(angle);
     vertex_buffer_data2[i * 18 + 10] = 0.0f;
     vertex_buffer_data2[i * 18 + 11] = 8.0f * sin(angle);
     vertex_buffer_data2[i * 18 + 12] = 5.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 13] = 5.0f;
     vertex_buffer_data2[i * 18 + 14] = 5.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 15] = 8.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 18 + 16] = 0.0f;
     vertex_buffer_data2[i * 18 + 17] = 8.0f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    angle=0;

    GLfloat vertex_buffer_data3[100 * 9];

    
    for(int i=0;i<100;i++)
    {
     vertex_buffer_data3[i * 9 + 0]  = 0.0f;
     vertex_buffer_data3[i * 9 + 1]  = 5.0f;
     vertex_buffer_data3[i * 9 + 2]  = 0.0f;
     vertex_buffer_data3[i * 9 + 3]  = 5.0f * cos(angle);
     vertex_buffer_data3[i * 9 + 4]  = 5.0f;
     vertex_buffer_data3[i * 9 + 5]  = 5.0f * sin(angle);
     vertex_buffer_data3[i * 9 + 6]  = 5.0f * cos(angle + rot_angle);
     vertex_buffer_data3[i * 9 + 7]  = 5.0f;
     vertex_buffer_data3[i * 9 + 8]  = 5.0f * sin(angle + rot_angle);

     angle += rot_angle;

    };


    this->object2 = create3DObject(GL_TRIANGLES, 200*3, vertex_buffer_data2, COLOR_BROWN, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data3, COLOR_FIRE, GL_FILL);
}



void Volcano::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Volcano::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

