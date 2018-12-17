#include "graphics.h"

Graphics::Graphics()
{
  light = glm::vec4(0,10,5,1);

  ambient = glm::vec4(.1f, .1f, .1f, 1);
  specular = glm::vec4(.1f, .1f, .1f, 1);
  diffuse = glm::vec4(.1f, .1f, .1f, 1);

  per_frag = true;
}

Graphics::~Graphics()
{

}

bool Graphics::Initialize(int width, int height)
{
  // Used for the linux OS
  #if !defined(__APPLE__) && !defined(MACOSX)
    // cout << glewGetString(GLEW_VERSION) << endl;
    glewExperimental = GL_TRUE;

    auto status = glewInit();

    // This is here to grab the error that comes from glew init.
    // This error is an GL_INVALID_ENUM that has no effects on the performance
    glGetError();

    //Check for error
    if (status != GLEW_OK)
    {
      std::cerr << "GLEW Error: " << glewGetErrorString(status) << "\n";
      return false;
    }
  #endif

  // For OpenGL 3
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Init Camera
  m_camera = new Camera();
  if(!m_camera->Initialize(width, height))
  {
    printf("Camera Failed to Initialize\n");
    return false;
  }
  phys_eng = new PhysicsEngine;
  phys_eng->createObjects();

  // Set up the shaders
  m_shader = new Shader("../shaders/shader.frag", "../shaders/shader.vert");
  if(!m_shader->Initialize())
  {
    printf("Shader Failed to Initialize\n");
    return false;
  }

  // Add the vertex shader
  if(!m_shader->AddShader(GL_VERTEX_SHADER))
  {
    printf("Vertex Shader failed to Initialize\n");
    return false;
  }

  // Add the fragment shader
  if(!m_shader->AddShader(GL_FRAGMENT_SHADER))
  {
    printf("Fragment Shader failed to Initialize\n");
    return false;
  }

  // Connect the program
  if(!m_shader->Finalize())
  {
    printf("Program to Finalize\n");
    return false;
  }

  // Locate the projection matrix in the shader
  m_projectionMatrix = m_shader->GetUniformLocation("projectionMatrix");
  if (m_projectionMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_projectionMatrix not found\n");
    return false;
  }

  // Locate the view matrix in the shader
  m_viewMatrix = m_shader->GetUniformLocation("viewMatrix");
  if (m_viewMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_viewMatrix not found\n");
    return false;
  }

  // Locate the model matrix in the shader
  m_modelMatrix = m_shader->GetUniformLocation("modelMatrix");
  if (m_modelMatrix == INVALID_UNIFORM_LOCATION) 
  {
    printf("m_modelMatrix not found\n");
    return false;
  }


  //enable depth testing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  return true;
}

void Graphics::Update(unsigned int dt)
{
  // Update the object
  phys_eng->Update(dt);
}

void Graphics::Render()
{
  //clear the screen
  glClearColor(0.0, 0.0, 0.2, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Start the correct program
  m_shader->Enable();
  m_projectionMatrix = m_shader->GetUniformLocation("projectionMatrix");
  m_viewMatrix = m_shader->GetUniformLocation("viewMatrix");
  m_modelMatrix = m_shader->GetUniformLocation("modelMatrix");

  // Send in the projection and view to the shader
  glUniformMatrix4fv(m_projectionMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetProjection()));
  glUniformMatrix4fv(m_viewMatrix, 1, GL_FALSE, glm::value_ptr(m_camera->GetView()));

  // Render the objects
  for(int x = 0; x<36; x++)
  {
  	if(phys_eng->fieldCollapse[x]){
   	glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->field[x]->GetModel()));
   	phys_eng->field[x]->Render();}
   }
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->plane->GetModel()));
   phys_eng->plane->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->player1->GetModel()));
   phys_eng->player1->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->player2->GetModel()));
   phys_eng->player2->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->Snowball1->GetModel()));
   phys_eng->Snowball1->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->Snowball2->GetModel()));
   phys_eng->Snowball2->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->Snowball3->GetModel()));
   phys_eng->Snowball3->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->Snowball4->GetModel()));
   phys_eng->Snowball4->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->Snowball5->GetModel()));
   phys_eng->Snowball5->Render();
   
   glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(phys_eng->Snowball6->GetModel()));
   phys_eng->Snowball6->Render();
  


  m_lightPos = m_shader->GetUniformLocation("LightPosition");

  m_ambient = m_shader->GetUniformLocation("AmbientProduct");
  m_diffuse = m_shader->GetUniformLocation("DiffuseProduct");
  m_specular = m_shader->GetUniformLocation("SpecularProduct");
  m_shininess = m_shader->GetUniformLocation("Shininess");

	glUniform4fv(m_lightPos, 1, glm::value_ptr(light));
	glUniform4fv(m_ambient, 1, glm::value_ptr(ambient));
	glUniform4fv(m_diffuse, 1, glm::value_ptr(diffuse));
	glUniform4fv(m_specular, 1, glm::value_ptr(specular));
	glUniform1fv(m_shininess, 1, &shininess);


  // Get any errors from OpenGL
  auto error = glGetError();
  if ( error != GL_NO_ERROR )
  {
    string val = ErrorString( error );
    std::cout<< "Error initializing OpenGL! " << error << ", " << val << std::endl;
  }
}

void Graphics::Launch()
{
  //phys_eng->Launch();
}

std::string Graphics::ErrorString(GLenum error)
{
  if(error == GL_INVALID_ENUM)
  {
    return "GL_INVALID_ENUM: An unacceptable value is specified for an enumerated argument.";
  }

  else if(error == GL_INVALID_VALUE)
  {
    return "GL_INVALID_VALUE: A numeric argument is out of range.";
  }

  else if(error == GL_INVALID_OPERATION)
  {
    return "GL_INVALID_OPERATION: The specified operation is not allowed in the current state.";
  }

  else if(error == GL_INVALID_FRAMEBUFFER_OPERATION)
  {
    return "GL_INVALID_FRAMEBUFFER_OPERATION: The framebuffer object is not complete.";
  }

  else if(error == GL_OUT_OF_MEMORY)
  {
    return "GL_OUT_OF_MEMORY: There is not enough memory left to execute the command.";
  }
  else
  {
    return "None";
  }
}
