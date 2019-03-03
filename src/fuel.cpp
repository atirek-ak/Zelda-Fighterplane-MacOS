#include "fuel.h"
#include "main.h"

Fuel::Fuel(float x, float y, float z, float fuel) {
    this->position = glm::vec3(x, y, z);
    
    float x1 = cos(fuel * M_PI / 100.0f);
    float y1 = sin(fuel * M_PI / 100.0f);

    GLfloat vertex_buffer_data4[] = {
        0.0f,  0.05f, 0.0f,
        0.0f, -0.05f, 0.0f,
       -0.3f * x1,  0.3f * y1, 0.0f,
    };

    this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data4, COLOR_GOLD, GL_FILL);
}



void Fuel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object4);
}

void Fuel::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

