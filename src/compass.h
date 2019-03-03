#include "main.h"
#include <string>

#ifndef COMPASS_H
#define COMPASS_H


class Compass {
public:
    Compass() {}
    Compass(float x, float y, float z, glm::vec3 speed);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object4;
};

#endif // DASHBOARD_H
