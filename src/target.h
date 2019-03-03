#include "main.h"
#include <string>

#ifndef TARGET_H
#define TARGET_H


class Target {
public:
    Target() {}
    Target(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
};

#endif // TARGET_H
