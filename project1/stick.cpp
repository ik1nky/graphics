#define _USE_MATH_DEFINES
#include "stick.h"
#include <cmath>
//#include <glm/gtx/vector_angle.hpp>


stick::~stick(){
  glDeleteBuffers(1,&v_buf);
  glDeleteBuffers(1,&i_buf);
}

void stick::build(
  float x, float y, float z,
  float height, float width, float depth,
  float Rad)
{
  glGenBuffers (1, &v_buf);
  glGenBuffers (1, &i_buf);
  float temp_x;
  float temp_y;

  vertices.push_back(x);
  vertices.push_back(y);
  vertices.push_back(z);


  //bottom stick
  float twoPI = M_PI * 2;
  float tri_angle;
  for(int i = SUB_POINTS; i >=0; i--)
  {
    tri_angle = i*(twoPI/SUB_POINTS);

     vertices.push_back(x+Rad*cos(tri_angle));
     vertices.push_back(y+Rad*sin(tri_angle));
     vertices.push_back(z);
  }

  //top stick
  vertices.push_back(x);
  vertices.push_back(y);
  vertices.push_back(z-height);

  for(int i =0; i < SUB_POINTS+2; i++)
  {
    tri_angle = i*(twoPI/SUB_POINTS);

     vertices.push_back(x+Rad*cos(tri_angle));
     vertices.push_back(y+Rad*sin(tri_angle));
     vertices.push_back(z-height);
  }

  for(int i = SUB_POINTS*2-1; i >=0; i--)
  {
    tri_angle = i*(twoPI/SUB_POINTS);

    vertices.push_back(x+Rad*cos(tri_angle));
    vertices.push_back(y+Rad*sin(tri_angle));
    vertices.push_back(z);

    vertices.push_back(x+Rad*cos(tri_angle));
    vertices.push_back(y+Rad*sin(tri_angle));
    vertices.push_back(z-height);
  }

  for(int i = 0; i <= SUB_POINTS*2 + 4; i++)
    index.push_back(i);

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float),vertices.data(),GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size()*sizeof(float),index.data(),GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}


void stick::render(float r, float g, float b) const{
  //const int N = index.size();

  glPushAttrib(GL_ENABLE_BIT);
  glDisableClientState(GL_COLOR_ARRAY);

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glVertexPointer(3,GL_FLOAT,0,0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
  glLineWidth(20);

  glFrontFace(GL_CW);
  glColor3ub (r,g, b);
  glDrawArrays(GL_TRIANGLE_FAN,0,SUB_POINTS+2);
  glDrawArrays(GL_TRIANGLE_FAN,SUB_POINTS+4,SUB_POINTS*2);
  glDrawArrays(GL_QUAD_STRIP,SUB_POINTS*2+1,SUB_POINTS*4);


  glPopAttrib();
}
