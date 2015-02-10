// #define _USE_MATH_DEFINES
// #include "ArchComplete.h"
// #include <cmath>
// //#include <glm/gtx/vector_angle.hpp>
//
// Arch3 leg1,leg2,leg3,leg4;
// Arch3 main_table;
// Arch3 side1, side2, side3, side4;
//
//
// ArchComplete::~ArchComplete(){
//   glDeleteBuffers(1,&v_buf);
//   glDeleteBuffers(1,&i_buf);
// }
//
// void ArchComplete::build(
//   float x, float y, float z,
//   float height, float width, float depth)
// {
//   main_table.build(1,1,1,10,6,1);
//   side1.build(1,20,3,1,6,1);
//   side2.build(10,1,2,10,.5,.5);
// }
//
//
// void ArchComplete::render() const{
//   main_table.render();
//   side1.render();
//   //side2.render();
// }
//
// //g++ -std=c++11 -IC:/GLFW/include -IC:/GLEW/include -IC:/GLM -LC:/GLFW/lib-mingw -LC:/GLEW/lib/Release/x64 ArchComplete.cpp -o test C:/GLFW/lib-mingw/glfw3dll.a -lglew32s -lglfw3 -lopengl32 -lglu32 -lgdi32
