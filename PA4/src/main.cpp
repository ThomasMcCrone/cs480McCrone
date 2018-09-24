#include <iostream>

#include "engine.h"


int main(int argc, char **argv)
{
  cout<<"name of the file"<<endl;
  std::string s;
  cin>>s;
  // Start an engine and run it then cleanup after
  Engine *engine = new Engine("Thomas McCrone-CS480-PA1", 800, 600);
  if(!engine->Initialize(s))
  {
    printf("The engine failed to start.\n");
    delete engine;
    engine = NULL;
    return 1;
  }
  engine->Run();
  delete engine;
  engine = NULL;
  return 0;
}
