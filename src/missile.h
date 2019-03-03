#include "main.h"
#include <string>

#ifndef MISSILE_H
#define MISSILE_H


class Missile {
public:
    Missile() {}
    Missile(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    glm::mat4 Iden;
    int spawn;
    int spawntime;
private:
    VAO *object;
    VAO *object1;
    VAO *object3;
};

#endif // Missile_H
