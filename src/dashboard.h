#include "main.h"
#include <string>

#ifndef DASHBOARD_H
#define DASHBOARD_H


class Dashboard {
public:
    Dashboard() {}
    Dashboard(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
};

#endif // DASHBOARD_H
