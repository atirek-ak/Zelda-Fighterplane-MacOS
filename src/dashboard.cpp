#include "dashboard.h"
#include "main.h"

Dashboard::Dashboard(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    
    float angle=0, rot_angle= 2 * M_PI / 100;
    GLfloat vertex_buffer_data2[100 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data2[i * 9 + 0]  = 0.0f * cos(angle);
     vertex_buffer_data2[i * 9 + 2]  = 0.0f;
     vertex_buffer_data2[i * 9 + 1]  = 0.0f * sin(angle);
     vertex_buffer_data2[i * 9 + 3]  = 0.4f * cos(angle);
     vertex_buffer_data2[i * 9 + 5]  = 0.0f;
     vertex_buffer_data2[i * 9 + 4]  = 0.4f * sin(angle);
     vertex_buffer_data2[i * 9 + 6]  = 0.4f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 9 + 8]  = 0.0f;
     vertex_buffer_data2[i * 9 + 7]  = 0.4f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    angle = 0;

    GLfloat vertex_buffer_data3[100 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data3[i * 9 + 0]  = 1.0f + 0.0f * cos(angle);
     vertex_buffer_data3[i * 9 + 2]  = 0.0f;
     vertex_buffer_data3[i * 9 + 1]  = 0.0f * sin(angle);
     vertex_buffer_data3[i * 9 + 3]  = 1.0f + 0.4f * cos(angle);
     vertex_buffer_data3[i * 9 + 5]  = 0.0f;
     vertex_buffer_data3[i * 9 + 4]  = 0.4f * sin(angle);
     vertex_buffer_data3[i * 9 + 6]  = 1.0f + 0.4f * cos(angle + rot_angle);
     vertex_buffer_data3[i * 9 + 8]  = 0.0f;
     vertex_buffer_data3[i * 9 + 7]  = 0.4f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    angle = 0;

    GLfloat vertex_buffer_data4[100 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data4[i * 9 + 0]  = 2.0f + 0.0f * cos(angle);
     vertex_buffer_data4[i * 9 + 2]  = 0.0f;
     vertex_buffer_data4[i * 9 + 1]  = 0.0f * sin(angle);
     vertex_buffer_data4[i * 9 + 3]  = 2.0f + 0.4f * cos(angle);
     vertex_buffer_data4[i * 9 + 5]  = 0.0f;
     vertex_buffer_data4[i * 9 + 4]  = 0.4f * sin(angle);
     vertex_buffer_data4[i * 9 + 6]  = 2.0f + 0.4f * cos(angle + rot_angle);
     vertex_buffer_data4[i * 9 + 8]  = 0.0f;
     vertex_buffer_data4[i * 9 + 7]  = 0.4f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    angle = 0;

    GLfloat vertex_buffer_data5[100 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data5[i * 9 + 0]  = 3.0f + 0.0f * cos(angle);
     vertex_buffer_data5[i * 9 + 2]  = 0.0f;
     vertex_buffer_data5[i * 9 + 1]  = 0.0f * sin(angle);
     vertex_buffer_data5[i * 9 + 3]  = 3.0f + 0.4f * cos(angle);
     vertex_buffer_data5[i * 9 + 5]  = 0.0f;
     vertex_buffer_data5[i * 9 + 4]  = 0.4f * sin(angle);
     vertex_buffer_data5[i * 9 + 6]  = 3.0f + 0.4f * cos(angle + rot_angle);
     vertex_buffer_data5[i * 9 + 8]  = 0.0f;
     vertex_buffer_data5[i * 9 + 7]  = 0.4f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    //angle=0;
//
//    //GLfloat vertex_buffer_data3[]={
//    //    0.0f
    //};


    this->object2 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data3, COLOR_BLACK, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data4, COLOR_BLACK, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data5, COLOR_BLACK, GL_FILL);
}



void Dashboard::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
}

void Dashboard::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

