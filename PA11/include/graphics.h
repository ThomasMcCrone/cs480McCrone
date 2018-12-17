#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"
#include <vector>

class Graphics
{
	friend class PhysicsEngine;
	friend class Engine;
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt);
    void Render();
    void Launch();

	glm::vec4 ambient;
	glm::vec4 diffuse;
	glm::vec4 specular;
	glm::vec4 light;
	float shininess;
	bool per_frag;
        char isZoomOut;

protected:
	PhysicsEngine *phys_eng;

private:
    
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader* m_shader;

	GLint m_lightPos;
    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    GLint m_ambient;
    GLint m_diffuse;
    GLint m_specular;
    GLint m_shininess;

};

#endif /* GRAPHICS_H */
