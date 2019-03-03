#include "parachute.h"
#include "main.h"

Parachute::Parachute(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100*9];

    float angle = 0;
    float rot_angle = 2*M_PI/100;

    for(int i=0;i<100;i++){
        vertex_buffer_data[9*i]=0.0;
        vertex_buffer_data[9*i+1]=2.0;
        vertex_buffer_data[9*i+2]=0.0;

        vertex_buffer_data[9*i+3]=2.0*cos(angle);
        vertex_buffer_data[9*i+4]=1.0;
        vertex_buffer_data[9*i+5]=2.0*sin(angle);

        vertex_buffer_data[9*i+6]=2.0*cos(angle+rot_angle);
        vertex_buffer_data[9*i+7]=1.0;
        vertex_buffer_data[9*i+8]=2.0*sin(angle+rot_angle);
    
        angle+=rot_angle;

    }
    
    GLfloat vertex_buffer_data2[]={
       -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
       -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,

        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
       -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
    
        1.0f,-1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,

          1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,

    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,

        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
    };
  

    this->object = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data, COLOR_GREEN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
}


void Parachute::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * this->Iden);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
}

void Parachute::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Parachute::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

