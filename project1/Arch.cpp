#include "Arch.h"
#include <glm/gtx/vector_angle.hpp>

void Arch:: save_point_and_color(glm::vec3 p, glm::vec3 c){
  all_points.push_back(p);
  all_colors.push_back(c);

  return all_points.size() - 1;
}

void Arch:: init_model(){
  if (!glIsBuffer(vertex_buffer))
      glGenBuffers(1, &vertex_buffer);
  if (!glIsBuffer(color_buffer))
      glGenBuffers(1, &color_buffer);
  if (!glIsBuffer(index_buffer))
      glGenBuffers(1, &index_buffer);
  all_points.clear();
  all_colors.clear();
  all_index.clear();
}


void Arch::build (void *data){
  int lev = *((int *) data);
  init_model(lev);

  post_build();
}
