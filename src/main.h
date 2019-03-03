#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <math.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct color_t {
    int r;
    int g;
    int b;
};

// nonedit.cpp
GLFWwindow *initGLFW(int width, int height);
GLuint     LoadShaders(const char *vertex_file_path, const char *fragment_file_path);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const GLfloat *color_buffer_data, GLenum fill_mode = GL_FILL);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode = GL_FILL);
struct VAO *create3DObject(GLenum primitive_mode, int numVertices, const GLfloat *vertex_buffer_data, const color_t color, GLenum fill_mode = GL_FILL);
void       draw3DObject(struct VAO *vao);

// input.cpp
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods);
void keyboardChar(GLFWwindow *window, unsigned int key);
void mouseButton(GLFWwindow *window, int button, int action, int mods);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

// other_handlers.cpp
void error_callback(int error, const char *description);
void quit(GLFWwindow *window);
void reshapeWindow(GLFWwindow *window, int width, int height);

// Types
struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int    NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    GLuint    MatrixID;
};

extern GLMatrices Matrices;

// ---- Logic ----

enum direction_t { DIR_UP, DIR_RIGHT, DIR_DOWN, DIR_LEFT };

struct bounding_box_t {
    float x;
    float y;
    float width;
    float height;
};

bool detect_collision(bounding_box_t a, bounding_box_t b);

extern float screen_zoom, screen_center_x, screen_center_y, mouse_x_rad, mouse_y_rad;
extern std::string camera_view;
extern double ini_cur_x, ini_cur_y;
extern float screen_zoom, screen_center_x, screen_center_y;

void reset_screen();
void set_camera_coords(float eye1, float eye2, float eye3, float target1, float target2, float target3, float up1, float up2, float up3);
void update_camera_coords();
void gravity();
void check_above_volcano();
void missile_spawn();
int calculate(double x1,double x2,double y1,double y2,double z1,double z2, double r);
void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

// ---- Colors ----
extern const color_t COLOR_RED;
extern const color_t COLOR_GREEN;
extern const color_t COLOR_BLACK;
extern const color_t COLOR_DARK_SLATE_GRAY;
extern const color_t COLOR_BACKGROUND;
extern const color_t COLOR_WHITE;
extern const color_t COLOR_NAVY;
extern const color_t COLOR_GRAY;
extern const color_t COLOR_SEA;
extern const color_t COLOR_BROWN;
extern const color_t COLOR_FIRE;
extern const color_t COLOR_MIDNIGHT_BLUE;
extern const color_t COLOR_DODGER_BLUE;
extern const color_t COLOR_DARK_OLIVE_GREEN;
extern const color_t COLOR_HOT_RED;
extern const color_t COLOR_GOLD;


#endif
