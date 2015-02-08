#define _USE_MATH_DEFINES
#include "Arch2.h"
#include <cmath>
//#include <glm/gtx/vector_angle.hpp>


void Arch2::build(){
  glGenBuffers (1, &v_buf);
  glGenBuffers (1, &i_buf);


  float delta = 2 * M_PI / (SUB_POINTS * 2);
  float angle = 0.0f;
  for(int i = 0; i < SUB_POINTS; i++){
      float x = RADIUS * cos(angle);
      float y = RADIUS * sin(angle);

      vertices.push_back (x);
      vertices.push_back (y);
      vertices.push_back (HEIGHT);
      angle += delta;
  }

  for(int i = 0; i < SUB_POINTS; i++){
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

  // Copy to GPU mem

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float),vertices.data(),GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size()*sizeof(float),index.data(),GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}


void Arch2::render() const{

}

int main(){
  return 0;
}

//g++ -std=c++11 -IC:/GLFW/include -IC:/GLEW/include -IC:/GLM -LC:/GLFW/lib-mingw -LC:/GLEW/lib/Release/x64 Arch2.cpp -o test C:/GLFW/lib-mingw/glfw3dll.a -lglew32s -lglfw3 -lopengl32 -lglu32 -lgdi32
