#include "main.h"
#include <string>

#ifndef SMOKE_H
#define SMOKE_H


class Smoke {
public:
    Smoke() {}
    Smoke(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    glm::mat4 Iden;
    int spawn;
private:
    //VAO *object;
    VAO *object1;
    //VAO *object3;
};

#endif // Smoke_H
