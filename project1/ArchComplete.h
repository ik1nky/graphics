#ifndef ARCH_C_DEMO_H
#define ARCH_C_DEMO_H


#define GLEW_STATIC
#include <GL/glew.h>

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/io.hpp>
#include <GLFW/glfw3.h>
#include "Arch3.h"
//#include <glm/vec3.hpp>

using namespace std;

class ArchComplete {
    private:
      const int SUB_POINTS = 20;

      const float RADIUS = 3.0f;
      const float HEIGHT = 5.0f;
      const float WIDTH = 4.0f;

      GLuint v_buf, i_buf;
      vector<float> vertices;
      vector<GLushort> index;
    public:
      ~ArchComplete();
      void build(float x, float y, float z,
      float height, float width, float depth);
      void render() const;
};

#endif
