#ifndef KINKEMA_ARCH_H
#define KINKEMA_ARCH_H
#include <vector>
#include <glm/vec3.hpp>
#include "BufferObject.h"
using namespace std;

class Ach : public BufferObject {
private:
    float height;
    float width;
    int save_point_and_color(glm::vec3, glm::vec3);
    void init_model(int level);
    //void divideTriangle (int a, int b, int c, int level);
public:
    //float radius() const {
  //      return sphere_radius;
  //  }
    void build(void *);
};

#endif
