#include "compass.h"
#include "main.h"

Compass::Compass(float x, float y, float z, glm::vec3 speed) {
    this->position = glm::vec3(x, y, 0);
    speed[1] = 0;
    speed = glm::normalize(speed);
    float compass_angle = acos(speed[2]);
    if(speed[0]>0)
        compass_angle = -compass_angle;
    float x1 = cos(compass_angle);
    float y1 = sin(compass_angle);

    GLfloat vertex_buffer_data4[] = {
        0.0f,  0.05f, 0.0f,
        0.0f, -0.05f, 0.0f,
        -0.3 * x1,  0.3 * y1, 0.0f,
    };

    this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data4, COLOR_DODGER_BLUE, GL_FILL);
}



void Compass::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object4);
}

void Compass::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, 0);
}

