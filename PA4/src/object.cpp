#include "object.h"

Object::Object(std::string s)
{
  char fileopen[s.size()+1];
  strcpy(fileopen,s.c_str());
//  std::cout<<fileopen<<std::endl;
  FILE *file = fopen(fileopen,"r");
//  if(file == NULL) std::cout<<"shit happened yo"<<std::endl;
  int x = 0;
  int y = 0;
  while(1)
  {
 // 	std::cout<<"baloney"<<std::endl;
  	char lineheader[128];
//  	std::cout<<"baloney"<<std::endl;
  	int res = fscanf(file,"%s",lineheader);
 // 	std::cout<<"baloney"<<std::endl;
  	if(res == EOF) break;
 // 	std::cout<<"baloney"<<std::endl;
  	if(strcmp(lineheader,"v")==0)
  	{
 // 		std::cout<<"x"<<std::endl;
  		glm::vec3 vertex;
  		fscanf(file,"%f %f %f\n",&vertex.x,&vertex.y,&vertex.z);
  		glm::vec3 color(glm::sin(vertex.x),glm::cos(vertex.y),glm::sin(vertex.z));
  		Vertex input(vertex,color);
  		myVertices.push_back(input);
  		x++;
  	}
  	else if(strcmp(lineheader,"f")==0)
  	{
 // 		std::cout<<"y"<<std::endl;
  		unsigned int vertexIndex[3];
  		fscanf(file,"%d %d %d\n",&vertexIndex[0],&vertexIndex[1],&vertexIndex[2]);
  		myFaces.push_back(vertexIndex[0]);
  		myFaces.push_back(vertexIndex[1]);
  		myFaces.push_back(vertexIndex[2]);
  		y++;
  	}
  	
  }
  
  for(unsigned int x = 0; x<myFaces.size();x++)
  {
  	myFaces[x] = myFaces[x]-1;
  }
  
  
  
  angle = 0.0f;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * myVertices.size(), &myVertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * myFaces.size(), &myFaces[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  myVertices.clear();
  myFaces.clear();
}

void Object::Update(unsigned int dt)
{
  angle += dt * M_PI/1000;
  model = glm::rotate(glm::mat4(1.0f), (angle/5), glm::vec3(0.0f,5.0f, 0.0f));
  model = glm::translate(model,glm::vec3(0.0f,0.0f,5.0f));
  model = glm::rotate(model,(angle),glm::vec3(0.0f,1.0f,0.0f));
  
}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, myFaces.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

