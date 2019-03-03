#include "main.h"
#include <string>

#ifndef CANNONBALL_H
#define CANNONBALL_H


class Cannonball {
public:
    Cannonball() {}
    Cannonball(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object;
    VAO *object1;
};

#endif // Cannonball_H
