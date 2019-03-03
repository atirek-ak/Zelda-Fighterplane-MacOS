#include "main.h"
#include <string>

#ifndef FUELCAN_H
#define FUELCAN_H


class Fuelcan {
public:
    Fuelcan() {}
    Fuelcan(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object4;
    VAO *object3;
};

#endif // DASHBOARD_H
