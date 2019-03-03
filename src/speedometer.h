#include "main.h"
#include <string>

#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H


class Speedometer {
public:
    Speedometer() {}
    Speedometer(float x, float y, float z, float speed);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object4;
};

#endif // DASHBOARD_H
