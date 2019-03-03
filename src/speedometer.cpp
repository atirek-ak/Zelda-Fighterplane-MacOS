#include "speedometer.h"
#include "main.h"

Speedometer::Speedometer(float x, float y, float z, float speed) {
    this->position = glm::vec3(x, y, z);
    
    float x1 = cos(speed * M_PI / 5.0f);
    float y1 = sin(speed * M_PI / 5.0f);

    GLfloat vertex_buffer_data4[] = {
        0.0f,  0.05f, 0.0f,
        0.0f, -0.05f, 0.0f,
        -0.3 * x1,  0.3 * y1, 0.0f,
    };

    this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data4, COLOR_RED, GL_FILL);
}



void Speedometer::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object4);
}

void Speedometer::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

