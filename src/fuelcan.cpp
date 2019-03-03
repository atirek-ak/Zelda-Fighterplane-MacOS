#include "fuelcan.h"
#include "main.h"

Fuelcan::Fuelcan(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);

    GLfloat vertex_buffer_data4[] = {
        0.0f,  0.0f, 0.0f,
        0.0f,  2.0f, 0.0f,
        0.5f,  0.0f, 0.0f,
        0.0f,  2.0f, 0.0f,
        0.5f,  0.0f, 0.0f,
        0.5f,  2.0f, 0.0f,
        0.0f,  0.0f, 1.0f,
        0.0f,  2.0f, 1.0f,
        0.5f,  0.0f, 1.0f,
        0.0f,  2.0f, 1.0f,
        0.5f,  0.0f, 1.0f,
        0.5f,  2.0f, 1.0f,
        
        0.0f,  0.0f, 0.0f,
        0.5f,  0.0f, 0.0f,
        0.0f,  0.0f, 1.0f,
        0.5f,  0.0f, 0.0f,
        0.0f,  0.0f, 1.0f,
        0.5f,  0.0f, 1.0f,
        0.0f,  2.0f, 0.0f,
        0.5f,  2.0f, 0.0f,
        0.0f,  2.0f, 1.0f,
        0.5f,  2.0f, 0.0f,
        0.0f,  2.0f, 1.0f,
        0.5f,  2.0f, 1.0f,

        0.0f,  0.0f, 0.0f,
        0.0f,  2.0f, 0.0f,
        0.0f,  0.0f, 1.0f,
        0.0f,  2.0f, 0.0f,
        0.0f,  0.0f, 1.0f,
        0.0f,  2.0f, 1.0f,
        0.5f,  0.0f, 0.0f,
        0.5f,  2.0f, 0.0f,
        0.5f,  0.0f, 1.0f,
        0.5f,  2.0f, 0.0f,
        0.5f,  0.0f, 1.0f,
        0.5f,  2.0f, 1.0f,
    };

    GLfloat vertex_buffer_data3[] = {
        -0.01f, 0.0f, 0.0f,
        -0.01f, 2.0f, 0.0f,
        -0.01f, 0.0f, 0.25f,
        -0.01f, 2.0f, 0.0f,
        -0.01f, 0.0f, 0.25f,
        -0.01f, 2.0f, 0.25f,

        -0.01f, 1.0f, 0.25f,
        -0.01f, 1.25f, 0.25f,
        -0.01f, 1.0f, 1.0f,
        -0.01f, 1.25f, 0.25f,
        -0.01f, 1.0f, 1.0f,
        -0.01f, 1.25f, 1.0f,

        -0.01f, 0.75f + 1.0f, 0.25f,
        -0.01f, 0.75f + 1.25f, 0.25f,
        -0.01f, 0.75f + 1.0f, 1.0f,
        -0.01f, 0.75f + 1.25f, 0.25f,
        -0.01f, 0.75f + 1.0f, 1.0f,
        -0.01f, 0.75f + 1.25f, 1.0f,

        0.5f + 0.01f, 0.0f, 1.0f - 0.0f,
        0.5f + 0.01f, 2.0f, 1.0f - 0.0f,
        0.5f + 0.01f, 0.0f, 1.0f - 0.25f,
        0.5f + 0.01f, 2.0f, 1.0f - 0.0f,
        0.5f + 0.01f, 0.0f, 1.0f - 0.25f,
        0.5f + 0.01f, 2.0f, 1.0f - 0.25f,

        0.5f + 0.01f,1.0f, 1.0f - 0.25f,
        0.5f + 0.01f,1.25f, 1.0f - 0.25f,
        0.5f + 0.01f,1.0f, 1.0f - 1.0f,
        0.5f + 0.01f,1.25f, 1.0f - 0.25f,
        0.5f + 0.01f,1.0f, 1.0f - 1.0f,
        0.5f + 0.01f,1.25f, 1.0f - 1.0f,

        0.5f + 0.01f, 0.75f + 1.0f, 1.0f - 0.25f,
        0.5f + 0.01f, 0.75f + 1.25f, 1.0f - 0.25f,
        0.5f + 0.01f, 0.75f + 1.0f, 1.0f - 1.0f,
        0.5f + 0.01f, 0.75f + 1.25f, 1.0f - 0.25f,
        0.5f + 0.01f, 0.75f + 1.0f, 1.0f - 1.0f,
        0.5f + 0.01f, 0.75f + 1.25f, 1.0f - 1.0f,



    };

    this->object4 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data4, COLOR_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data3, COLOR_BLACK, GL_FILL);
}



void Fuelcan::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object4);
    draw3DObject(this->object3);
}

void Fuelcan::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

