#include "main.h"
#include <string>

#ifndef SEA_H
#define SEA_H


class Sea {
public:
    Sea() {}
    Sea(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object2;
    //VAO *object3;
};

#endif //SEA_H
