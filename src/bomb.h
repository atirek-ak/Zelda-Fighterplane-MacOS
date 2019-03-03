#include "main.h"
#include <string>

#ifndef BOMB_H
#define BOMB_H


class Bomb {
public:
    Bomb() {}
    Bomb(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    glm::mat4 Iden;
    int spawn;
private:
    VAO *object;
    VAO *object1;
    VAO *object3;
};

#endif // Bomb_H
