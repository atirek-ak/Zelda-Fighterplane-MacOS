#include "main.h"
#include <string>

#ifndef PARACHUTE_H
#define PARACHUTE_H


class Parachute {
public:
    Parachute() {}
    Parachute(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    float rot_yaw;
    float rot_roll;
    float rot_pitch;
    void roll(float rot);
    void yaw (float rot);
    void pitch(float rot);
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    int control;
    double speed;
    double fuel;
    double axis_speed;
    glm::mat4 Iden;
private:
    VAO *object;
    VAO *object2;
};

#endif // BALL_H
