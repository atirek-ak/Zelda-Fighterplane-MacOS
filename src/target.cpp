#include "target.h"
#include "main.h"

Target::Target(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    
    float angle=0, rot_angle= 2 * M_PI / 100;
    GLfloat vertex_buffer_data2[800 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data2[i * 72 + 0]  = 9.0f + 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 1]  = 2.0f;
     vertex_buffer_data2[i * 72 + 2]  = 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 3]  = 9.0f + 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 4]  = 0.0f;
     vertex_buffer_data2[i * 72 + 5]  = 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 6]  = 9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 7]  = 2.0f;
     vertex_buffer_data2[i * 72 + 8]  = 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 9]  = 9.0f + 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 10] = 0.0f;
     vertex_buffer_data2[i * 72 + 11] = 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 12] = 9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 13] = 2.0f;
     vertex_buffer_data2[i * 72 + 14] = 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 15] = 9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 16] = 0.0f;
     vertex_buffer_data2[i * 72 + 17] = 1.0f * sin(angle + rot_angle);

     vertex_buffer_data2[i * 72 + 18]  = -9.0f + 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 19]  = 2.0f;
     vertex_buffer_data2[i * 72 + 20]  = 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 21]  = -9.0f + 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 22]  = 0.0f;
     vertex_buffer_data2[i * 72 + 23]  = 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 24]  = -9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 25]  = 2.0f;
     vertex_buffer_data2[i * 72 + 26]  = 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 27]  = -9.0f + 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 28]  = 0.0f;
     vertex_buffer_data2[i * 72 + 29]  = 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 30]  = -9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 31]  = 2.0f;
     vertex_buffer_data2[i * 72 + 32]  = 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 33]  = -9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 34]  = 0.0f;
     vertex_buffer_data2[i * 72 + 35]  = 1.0f * sin(angle + rot_angle);

     vertex_buffer_data2[i * 72 + 36]  = 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 37]  = 2.0f;
     vertex_buffer_data2[i * 72 + 38]  = 9.0f + 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 39]  = 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 40]  = 0.0f;
     vertex_buffer_data2[i * 72 + 41]  = 9.0f + 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 42]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 43]  = 2.0f;
     vertex_buffer_data2[i * 72 + 44]  = 9.0f + 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 45]  = 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 46]  = 0.0f;
     vertex_buffer_data2[i * 72 + 47]  = 9.0f + 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 48]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 49]  = 2.0f;
     vertex_buffer_data2[i * 72 + 50]  = 9.0f + 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 51]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 52]  = 0.0f;
     vertex_buffer_data2[i * 72 + 53]  = 9.0f + 1.0f * sin(angle + rot_angle);

     vertex_buffer_data2[i * 72 + 54]  = 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 55]  = 2.0f;
     vertex_buffer_data2[i * 72 + 56]  = -9.0f + 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 57]  = 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 58]  = 0.0f;
     vertex_buffer_data2[i * 72 + 59]  = -9.0f + 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 60]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 61]  = 2.0f;
     vertex_buffer_data2[i * 72 + 62]  = -9.0f + 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 63]  = 1.0f * cos(angle);
     vertex_buffer_data2[i * 72 + 64]  = 0.0f;
     vertex_buffer_data2[i * 72 + 65]  = -9.0f + 1.0f * sin(angle);
     vertex_buffer_data2[i * 72 + 66]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 67]  = 2.0f;
     vertex_buffer_data2[i * 72 + 68]  = -9.0f + 1.0f * sin(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 69]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data2[i * 72 + 70]  = 0.0f;
     vertex_buffer_data2[i * 72 + 71]  = -9.0f + 1.0f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    angle = 0;

    GLfloat vertex_buffer_data1[400 * 9];

    for(int i=0;i<100;i++)
    {
     vertex_buffer_data1[i * 36 + 0]  = 9.0f + 0.0f;
     vertex_buffer_data1[i * 36 + 1]  = 0.0f;
     vertex_buffer_data1[i * 36 + 2]  = 0.0f;
     vertex_buffer_data1[i * 36 + 3]  = 9.0f + 1.0f * cos(angle);
     vertex_buffer_data1[i * 36 + 4]  = 0.0f;
     vertex_buffer_data1[i * 36 + 5]  = 1.0f * sin(angle);
     vertex_buffer_data1[i * 36 + 6]  = 9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data1[i * 36 + 7]  = 0.0f;
     vertex_buffer_data1[i * 36 + 8]  = 1.0f * sin(angle + rot_angle);

     vertex_buffer_data1[i * 36 + 9]  = -9.0f + 0.0f;
     vertex_buffer_data1[i * 36 + 10] = 0.0f;
     vertex_buffer_data1[i * 36 + 11] = 0.0f;
     vertex_buffer_data1[i * 36 + 12] = -9.0f + 1.0f * cos(angle);
     vertex_buffer_data1[i * 36 + 13] = 0.0f;
     vertex_buffer_data1[i * 36 + 14] = 1.0f * sin(angle);
     vertex_buffer_data1[i * 36 + 15] = -9.0f + 1.0f * cos(angle + rot_angle);
     vertex_buffer_data1[i * 36 + 16] = 0.0f;
     vertex_buffer_data1[i * 36 + 17] = 1.0f * sin(angle + rot_angle);

     vertex_buffer_data1[i * 36 + 18]  = 0.0f;
     vertex_buffer_data1[i * 36 + 19]  = 0.0f;
     vertex_buffer_data1[i * 36 + 20]  = 9.0f + 0.0f;
     vertex_buffer_data1[i * 36 + 21]  = 1.0f * cos(angle);
     vertex_buffer_data1[i * 36 + 22]  = 0.0f;
     vertex_buffer_data1[i * 36 + 23]  = 9.0f + 1.0f * sin(angle);
     vertex_buffer_data1[i * 36 + 24]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data1[i * 36 + 25]  = 0.0f;
     vertex_buffer_data1[i * 36 + 26]  = 9.0f + 1.0f * sin(angle + rot_angle);

     vertex_buffer_data1[i * 36 + 27]  = 0.0f;
     vertex_buffer_data1[i * 36 + 28]  = 0.0f;
     vertex_buffer_data1[i * 36 + 29]  = -9.0f + 0.0f;
     vertex_buffer_data1[i * 36 + 30]  = 1.0f * cos(angle);
     vertex_buffer_data1[i * 36 + 31]  = 0.0f;
     vertex_buffer_data1[i * 36 + 32]  = -9.0f + 1.0f * sin(angle);
     vertex_buffer_data1[i * 36 + 33]  = 1.0f * cos(angle + rot_angle);
     vertex_buffer_data1[i * 36 + 34]  = 0.0f;
     vertex_buffer_data1[i * 36 + 35]  = -9.0f + 1.0f * sin(angle + rot_angle);
     

     angle += rot_angle;

    };

    angle=0;

    GLfloat vertex_buffer_data3[100 * 9];

    
    for(int i=0;i<100;i++)
    {
     vertex_buffer_data3[i * 9 + 0]  = 0.0f;
     vertex_buffer_data3[i * 9 + 1]  = 0.0f;
     vertex_buffer_data3[i * 9 + 2]  = 0.0f;
     vertex_buffer_data3[i * 9 + 3]  = 8.0f * cos(angle);
     vertex_buffer_data3[i * 9 + 4]  = 0.0f;
     vertex_buffer_data3[i * 9 + 5]  = 8.0f * sin(angle);
     vertex_buffer_data3[i * 9 + 6]  = 8.0f * cos(angle + rot_angle);
     vertex_buffer_data3[i * 9 + 7]  = 0.0f;
     vertex_buffer_data3[i * 9 + 8]  = 8.0f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    angle=0;

    GLfloat vertex_buffer_data4[100 * 9];

    
    for(int i=0;i<100;i++)
    {
     vertex_buffer_data4[i * 9 + 0]  = 0.0f;
     vertex_buffer_data4[i * 9 + 1]  = 0.01f;
     vertex_buffer_data4[i * 9 + 2]  = 0.0f;
     vertex_buffer_data4[i * 9 + 3]  = 5.0f * cos(angle);
     vertex_buffer_data4[i * 9 + 4]  = 0.01f;
     vertex_buffer_data4[i * 9 + 5]  = 5.0f * sin(angle);
     vertex_buffer_data4[i * 9 + 6]  = 5.0f * cos(angle + rot_angle);
     vertex_buffer_data4[i * 9 + 7]  = 0.01f;
     vertex_buffer_data4[i * 9 + 8]  = 5.0f * sin(angle + rot_angle);

     angle += rot_angle;

    };

    angle=0;

    GLfloat vertex_buffer_data5[100 * 9];

    
    for(int i=0;i<100;i++)
    {
     vertex_buffer_data5[i * 9 + 0]  = 0.0f;
     vertex_buffer_data5[i * 9 + 1]  = 0.02f;
     vertex_buffer_data5[i * 9 + 2]  = 0.0f;
     vertex_buffer_data5[i * 9 + 3]  = 2.0f * cos(angle);
     vertex_buffer_data5[i * 9 + 4]  = 0.02f;
     vertex_buffer_data5[i * 9 + 5]  = 2.0f * sin(angle);
     vertex_buffer_data5[i * 9 + 6]  = 2.0f * cos(angle + rot_angle);
     vertex_buffer_data5[i * 9 + 7]  = 0.02f;
     vertex_buffer_data5[i * 9 + 8]  = 2.0f * sin(angle + rot_angle);

     angle += rot_angle;

    };



    this->object1 = create3DObject(GL_TRIANGLES, 400*3, vertex_buffer_data1, COLOR_DARK_SLATE_GRAY, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 800*3, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data3, COLOR_NAVY, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data4, COLOR_WHITE, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data5, COLOR_NAVY, GL_FILL);
}



void Target::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
}

void Target::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

