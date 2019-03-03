#include "main.h"
#include <string>

#ifndef ALTITUDE_H
#define ALTITUDE_H


class Altitude {
public:
    Altitude() {}
    Altitude(float x, float y, float z, float altitude);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object4;
};

#endif // DASHBOARD_H
