#include "main.h"
#include <string>

#ifndef VOLCANO_H
#define VOLCANO_H


class Volcano {
public:
    Volcano() {}
    Volcano(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object2;
    VAO *object3;
};

#endif // VOLCANO_H
