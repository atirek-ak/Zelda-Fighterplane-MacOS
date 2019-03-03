#include "arrow.h"
#include "main.h"

Arrow::Arrow(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->Iden=glm::mat4(1.0f);

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100*9];

    float angle = 0;
    float rot_angle = 2*M_PI/100;

    for(int i=0;i<100;i++){
        vertex_buffer_data[9*i]=0.0;
        vertex_buffer_data[9*i+1]=0.0;
        vertex_buffer_data[9*i+2]=0.0;

        vertex_buffer_data[9*i+3]=0.4*cos(angle);
        vertex_buffer_data[9*i+4]=0.4*sin(angle);
        vertex_buffer_data[9*i+5]=1.0;

        vertex_buffer_data[9*i+6]=0.4*cos(angle+rot_angle);
        vertex_buffer_data[9*i+7]=0.4*sin(angle+rot_angle);
        vertex_buffer_data[9*i+8]=1.0;
    
        angle+=rot_angle;

    }

    angle = 0;
    GLfloat vertex_buffer_data1[100*9];

    for(int i=0;i<100;i++){
        vertex_buffer_data1[9*i]=0.0;
        vertex_buffer_data1[9*i+1]=0.0;
        vertex_buffer_data1[9*i+2]=1.0;

        vertex_buffer_data1[9*i+3]=0.4*cos(angle);
        vertex_buffer_data1[9*i+4]=0.4*sin(angle);
        vertex_buffer_data1[9*i+5]=1.0;

        vertex_buffer_data1[9*i+6]=0.4*cos(angle+rot_angle);
        vertex_buffer_data1[9*i+7]=0.4*sin(angle+rot_angle);
        vertex_buffer_data1[9*i+8]=1.0;
    
        angle+=rot_angle;

    }
    
    GLfloat vertex_buffer_data2[200*9];
    angle=0;

    for(int i=0;i<100;i++){
        vertex_buffer_data2[18*i]=0.3*cos(angle);
        vertex_buffer_data2[18*i+1]=0.3*sin(angle);
        vertex_buffer_data2[18*i+2]=2.0;

        vertex_buffer_data2[18*i+3]=0.3*cos(angle);
        vertex_buffer_data2[18*i+4]=0.3*sin(angle);
        vertex_buffer_data2[18*i+5]=1.0f;

        vertex_buffer_data2[18*i+6]=0.3*cos(angle+rot_angle);
        vertex_buffer_data2[18*i+7]=0.3*sin(angle+rot_angle);
        vertex_buffer_data2[18*i+8]=2.0f;

        vertex_buffer_data2[18*i+9]=0.3*cos(angle+rot_angle);
        vertex_buffer_data2[18*i+10]=0.3*sin(angle+rot_angle);
        vertex_buffer_data2[18*i+11]=2.0f;

        vertex_buffer_data2[18*i+12]=0.3*cos(angle+rot_angle);
        vertex_buffer_data2[18*i+13]=0.3*sin(angle+rot_angle);
        vertex_buffer_data2[18*i+14]=1.0f;

        vertex_buffer_data2[18*i+15]=0.3*cos(angle);
        vertex_buffer_data2[18*i+16]=0.3*sin(angle);
        vertex_buffer_data2[18*i+17]=1.0f;

        angle+=rot_angle;
    }
  

    this->object = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data, COLOR_HOT_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 100*3, vertex_buffer_data1, COLOR_HOT_RED, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 200*3, vertex_buffer_data2, COLOR_HOT_RED, GL_FILL);
}


void Arrow::draw(glm::mat4 VP, glm::vec3 pos, glm::vec3 direction_vector) {
    glm::vec3 current_x = glm::normalize(direction_vector);
    glm::vec3 current_y = glm::normalize(glm::cross(direction_vector,glm::vec3(1,1,1)));
    glm::vec3 current_z = glm::normalize(glm::cross(current_y,current_x));

    for(int i = 0;i<3;i++)
    {
        this->Iden[2][i] = -current_x[i];
        this->Iden[1][i] = current_y[i];
        this->Iden[0][i] = current_z[i];

    }

    this->position = pos;

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    Matrices.model *= (translate * this->Iden);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Arrow::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

//void Arrow::tick(glm::vec3 ballpos) {
//    this->position = ballpos;
//}

