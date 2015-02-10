#define _USE_MATH_DEFINES
#include "Arch3.h"
#include <cmath>
//#include <glm/gtx/vector_angle.hpp>


Arch3::~Arch3(){
  glDeleteBuffers(1,&v_buf);
  glDeleteBuffers(1,&i_buf);
}

void Arch3::build(
  float x, float y, float z,
  float height, float width, float depth)
{
  glGenBuffers (1, &v_buf);
  glGenBuffers (1, &i_buf);


  float delta = 2 * M_PI / (SUB_POINTS * 2);
  float angle = 0.0f;

  //Push Backs
  //Arch width = 2XRadius(Arc)
  //Arch Height = Height(Rectangles) + Radius(Arc)
  // float x=1;
  // float y=1;
  // float z=1;
  // float height=3;
  // float width=1;
  // float depth=2;

  //Front
  //1
  vertices.push_back(x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z);

  //2
  vertices.push_back(x*width);
  vertices.push_back(y*height);
  vertices.push_back(z);

  //3
  vertices.push_back(-x*width);
  vertices.push_back(y*height);
  vertices.push_back(z);

  //4
  vertices.push_back(-x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z);

  //Back
  vertices.push_back(-x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z+depth);

  vertices.push_back(-x*width);
  vertices.push_back(y*height);
  vertices.push_back(z+depth);

  vertices.push_back(x*width);
  vertices.push_back(y*height);
  vertices.push_back(z+depth);

  vertices.push_back(x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z+depth);

  //Link side
  //1
   vertices.push_back(-x*width);
   vertices.push_back(y*height);
   vertices.push_back(z);

   //2
   vertices.push_back(-x*width);
   vertices.push_back(y*height);
   vertices.push_back(z+depth);

   //3
   vertices.push_back(-x*width);
   vertices.push_back(-y*height);
   vertices.push_back(z+depth);

  vertices.push_back(-x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z);


  //face 1
  vertices.push_back(-x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z);

  vertices.push_back(-x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z+depth);

  vertices.push_back(x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z+depth);

  vertices.push_back(x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z);

  //face 2
  vertices.push_back(x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z);

  vertices.push_back(x*width);
  vertices.push_back(-y*height);
  vertices.push_back(z+depth);

  vertices.push_back(x*width);
  vertices.push_back(y*height);
  vertices.push_back(z+depth);

  vertices.push_back(x*width);
  vertices.push_back(y*height);
  vertices.push_back(z);

  //face 3
  vertices.push_back(x*width);
  vertices.push_back(y*height);
  vertices.push_back(z);

  vertices.push_back(x*width);
  vertices.push_back(y*height);
  vertices.push_back(z+depth);

  vertices.push_back(-x*width);
  vertices.push_back(y*height);
  vertices.push_back(z+depth);

  vertices.push_back(-x*width);
  vertices.push_back(y*height);
  vertices.push_back(z);

  for(int i = 0; i <= 96; i++)
    index.push_back(i);

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float),vertices.data(),GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size()*sizeof(float),index.data(),GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}


void Arch3::render() const{
  const int N = index.size();

  glPushAttrib(GL_ENABLE_BIT);
  glDisableClientState(GL_COLOR_ARRAY);

  glBindBuffer(GL_ARRAY_BUFFER, v_buf);
  glVertexPointer(3,GL_FLOAT,0,0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

/*  glFrontFace(GL_CW);
  glColor3ub (255, 0, 0);
  //glDrawElements(GL_QUADS,N, GL_UNSIGNED_SHORT,(void *)(N*sizeof(GLushort)));
  glDrawArrays(GL_QUADS,0,N);
  //glDrawElements(GL_QUAD_STRIP,2*SUB_POINTS + 2, GL_UNSIGNED_SHORT,);
  //(void *)(N*sizeof(GLushort))
*/

  for(int i = 0; i < N; i+=4)
  {
      glFrontFace(GL_CW);
      glColor3ub (255-(i*40), (i*40), 0);
      glDrawArrays(GL_QUADS,i,i+4);
  }
  glPopAttrib();
}
/*
int main(){
  return 0;
}*/

//g++ -std=c++11 -IC:/GLFW/include -IC:/GLEW/include -IC:/GLM -LC:/GLFW/lib-mingw -LC:/GLEW/lib/Release/x64 Arch3.cpp -o test C:/GLFW/lib-mingw/glfw3dll.a -lglew32s -lglfw3 -lopengl32 -lglu32 -lgdi32
