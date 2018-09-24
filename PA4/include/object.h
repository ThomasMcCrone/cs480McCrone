#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"
#include <stdio.h>
#include <string>
#include <cstring>

class Object
{
  public:
    Object(std::string s);
    ~Object();
    void Update(unsigned int dt);
    void Render();

    glm::mat4 GetModel();

  private:
    glm::mat4 model;
    std::vector<Vertex> myVertices;
    std::vector<unsigned int> myFaces;
    GLuint VB;
    GLuint IB;

    float angle;
};

#endif /* OBJECT_H */
