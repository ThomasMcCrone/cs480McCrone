#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object();
    ~Object();
    void UpdateRotation(unsigned int dt);
    void UpdateOrbit(unsigned int dt);
    void InvertedUpdateRotation(unsigned int dt);
    void InvertedUpdateOrbit(unsigned int dt);
    void Render();

    glm::mat4 GetModel();

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angleRotation;
    float angleOrbit;
    
};

#endif /* OBJECT_H */
