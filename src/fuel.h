#include "main.h"
#include <string>

#ifndef FUEL_H
#define FUEL_H


class Fuel {
public:
    Fuel() {}
    Fuel(float x, float y, float z, float fuel);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object4;
};

#endif // DASHBOARD_H
