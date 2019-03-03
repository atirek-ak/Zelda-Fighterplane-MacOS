#include "sea.h"
#include "main.h"

Sea::Sea(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    //this->rot_yaw = 0;
    //this->rot_pitch = 0;
    //this->rot_roll = 0;
    //this->speed = 1;
    //this->Iden = glm::mat4(1.0f);

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    //GLfloat vertex_buffer_data2[2*9];


   /* GLfloat vertex_buffer_data3[]={
     -2000.0, -2000.0, -10.0,
     -2000.0,  2000.0, -10.0,
      2000.0, -2000.0, -10.0,
      2000.0,  2000.0, -10.0,
     -2000.0,  2000.0, -10.0,
      2000.0, -2000.0, -10.0,

    };*/
    
    GLfloat vertex_buffer_data2[]={
     -2000.0, -10.0, -2000.0,
     -2000.0, -10.0,  2000.0,
      2000.0, -10.0, -2000.0,
      2000.0, -10.0,  2000.0,
     -2000.0, -10.0,  2000.0,
      2000.0, -10.0, -2000.0,

    };
    this->object2 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data2, COLOR_SEA, GL_FILL);
    //this->object3 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data3, COLOR_FIRE, GL_FILL);
}



void Sea::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
    //draw3DObject(this->object3);
}

void Sea::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

