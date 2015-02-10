#define _USE_MATH_DEFINES
#include "arc.h"
#include <cmath>
//#include <glm/gtx/vector_angle.hpp>


arc::~arc(){
  glDeleteBuffers(1,&v_buf);
  glDeleteBuffers(1,&i_buf);
}

void arc::build(
  float x, float y, float z,
  float height, float width, float depth,
  float Rad)
{
  glGenBuffers (1, &v_buf);
  glGenBuffers (1, &i_buf);
  float temp_x;
  float temp_y;

  for(int i = 0; i < SUB_POINTS; i++)
  {
    float theta = M_PI * float(i) / float(SUB_POINTS);//get the current angle

    temp_x = Rad * cosf(theta);//calculate the x component
    temp_y = Rad * sinf(theta);//calculate the y component

    vertices.push_back(x + temp_x);
    vertices.push_back(y + temp_y);
    vertices.push_back(z);

  }

  vertices.push_back(x+ temp_x);
  vertices.push_back(y + temp_y);
  vertices.push_back(z);


  vertices.push_back(x+ temp_x-depth);
  vertices.push_back(y + temp_y);
  vertices.push_back(z);

  vertices.push_back(-x+ temp_x);
  vertices.push_back(y + temp_y);
  vertices.push_back(z);

  vertices.push_back(-x+ -temp_x + depth);
  vertices.push_back(y + temp_y);
  vertices.push_back(z);

  for(int i = 0; i <= SUB_POINTS + 12; i++)
    index.push_back(i);

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float),vertices.data(),GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size()*sizeof(float),index.data(),GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}


void arc::render() const{
  //const int N = index.size();

  glPushAttrib(GL_ENABLE_BIT);
  glDisableClientState(GL_COLOR_ARRAY);

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glVertexPointer(3,GL_FLOAT,0,0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
  glLineWidth(20);
      glDrawArrays(GL_TRIANGLES,0,SUB_POINTS);

      glDrawArrays(GL_LINES,SUB_POINTS, SUB_POINTS+12);

  glPopAttrib();
}
