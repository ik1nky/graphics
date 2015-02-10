#define _USE_MATH_DEFINES
#include "Arch2.h"
#include <cmath>
//#include <glm/gtx/vector_angle.hpp>


Arch2::~Arch2(){
  glDeleteBuffers(1,&v_buf);
  glDeleteBuffers(1,&i_buf);
}

void Arch2::build(){
  glGenBuffers (1, &v_buf);
  glGenBuffers (1, &i_buf);


  float delta = 2 * M_PI / (SUB_POINTS * 2);
  float angle = 0.0f;
  for(int i = 0; i < SUB_POINTS/2; i++){
      float x = RADIUS * cos(angle);
      float y = RADIUS * sin(angle);

      vertices.push_back (x);
      vertices.push_back (y);
      vertices.push_back (HEIGHT);
      angle += delta;
  }

  for(int i = 0; i < SUB_POINTS/2; i++){
      float x = RADIUS * cos(angle);
      float y = RADIUS * sin(angle);

      vertices.push_back (x);
      vertices.push_back (y);
      vertices.push_back (-HEIGHT);
      angle += delta;
  }

  vertices.push_back(0);
  vertices.push_back(0);
  vertices.push_back(HEIGHT);


  for(int i = 0; i < SUB_POINTS; i++){
    index.push_back(i);
    index.push_back(i + SUB_POINTS);
  }
  index.push_back(0);
  index.push_back(SUB_POINTS);

  index.push_back (SUB_POINTS * 2);
    /* index of rest of the tri-fan */
    for (int k = 0; k < SUB_POINTS; k++)
        index.push_back (k);
    /* close the last arc of the tri-fan */
    index.push_back (0);

  // Copy to GPU mem

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float),vertices.data(),GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size()*sizeof(float),index.data(),GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}


void Arch2::render() const{
  glPushAttrib(GL_ENABLE_BIT);
  glDisableClientState(GL_COLOR_ARRAY);

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glVertexPointer(3,GL_FLOAT,0,0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);


  //glDrawElements(GL_QUAD_STRIP,SUB_POINTS+2, GL_UNSIGNED_SHORT,0);
  //glDrawElements(GL_QUAD_STRIP,2*SUB_POINTS + 2, GL_UNSIGNED_SHORT,);

  glPopAttrib();
}
/*
int main(){
  return 0;
}*/

//g++ -std=c++11 -IC:/GLFW/include -IC:/GLEW/include -IC:/GLM -LC:/GLFW/lib-mingw -LC:/GLEW/lib/Release/x64 Arch2.cpp -o test C:/GLFW/lib-mingw/glfw3dll.a -lglew32s -lglfw3 -lopengl32 -lglu32 -lgdi32
