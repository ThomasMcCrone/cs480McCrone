
#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
  player1Lives = 3;
  player2Lives = 3;
}

Engine::Engine(string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

bool Engine::Initialize()
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;
  
  //running sound
  SDL_Init(SDL_INIT_AUDIO);
  SDL_AudioSpec wavSpec;
  Uint32 wavLength;
  Uint8 *wavBuffer;
  SDL_LoadWAV("ambient.wav", &wavSpec, &wavBuffer, &wavLength);
  SDL_AudioDeviceID deviceID = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
  int success = SDL_QueueAudio(deviceID,wavBuffer,wavLength);
  SDL_PauseAudioDevice(deviceID,0);
  
  //running program
  while(m_running)
  {
    // Update the DT
    m_DT = getDT();
    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }
    if(player1Up) m_graphics->phys_eng->applyForce(1,1);
    if(player1Down) m_graphics->phys_eng->applyForce(1,2);
    if(player1Left) m_graphics->phys_eng->applyForce(1,3);
    if(player1Right) m_graphics->phys_eng->applyForce(1,4);
    
    if(player2Up) m_graphics->phys_eng->applyForce(2,2);
    if(player2Down) m_graphics->phys_eng->applyForce(2,1);
    if(player2Left) m_graphics->phys_eng->applyForce(2,4);
    if(player2Right) m_graphics->phys_eng->applyForce(2,3);
    // Update and render the graphics
    m_graphics->Update(m_DT);
//    std::cout<<m_DT<<std::endl;
    m_graphics->Render();
    int x = m_graphics->phys_eng->isOver();
    switch(x)
    {
    	case 0:
    		
    		break;
    	case 1:
    		player1Lives--;
    		if(player1Lives == 0) m_running = false;
    		std::cout<<"player 1 lives - "<<player1Lives<<std::endl;
    		std::cout<<"player 2 lives - "<<player2Lives<<std::endl;
    		std::cout<<std::endl;
    		playDeath();
    		break;
    	case 2:
    		player2Lives--;
    		if(player2Lives == 0) m_running = false;
    		std::cout<<"player 1 lives - "<<player1Lives<<std::endl;
    		std::cout<<"player 2 lives - "<<player2Lives<<std::endl;
    		std::cout<<std::endl;
    		playDeath();
    		break;
    }
    
    // Swap to the Window
    m_window->Swap();
  }
  std::cout<<"game over"<<std::endl;
}

void Engine::Keyboard()
{

  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  switch (m_event.type)
  {
      case SDL_KEYDOWN:
      	  if(m_DT == rand()% 15+10) m_graphics->phys_eng->shrink();
          switch(m_event.key.keysym.sym)
          {
              case SDLK_ESCAPE:
                  m_running = false;
                  break;
                  
                
            case SDLK_w:
            	player2Up = true;
           	break;
           
            case SDLK_s:
            	player2Down = true;
            	break;
            	
            case SDLK_a:
            	player2Left = true;
            	break;
            	
            case SDLK_d:
            	player2Right = true;
            	break;
            	
            case SDLK_UP:
            	player1Up = true;
           	break;
           
            case SDLK_DOWN:
            	player1Down = true;
            	break;
            	
            case SDLK_LEFT:
            	player1Left = true;
            	break;
            	
            case SDLK_RIGHT:
            	player1Right = true;
            	break;
          }
       break;
       
       case SDL_KEYUP:
       	  if(m_DT == rand()% 15+10) m_graphics->phys_eng->shrink();
       	  switch(m_event.key.keysym.sym)
          {
              
            case SDLK_w:
            	player2Up = false;
           	break;
           
            case SDLK_s:
            	player2Down = false;
            	break;
            	
            case SDLK_a:
            	player2Left = false;
            	break;
            	
            case SDLK_d:
            	player2Right = false;
            	break;
            	
            case SDLK_UP:
            	player1Up = false;
           	break;
           
            case SDLK_DOWN:
            	player1Down = false;
            	break;
            	
            case SDLK_LEFT:
            	player1Left = false;
            	break;
            	
            case SDLK_RIGHT:
            	player1Right = false;
            	break;
          }

  }

}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}
void Engine::playDeath()
{
	SDL_Init(SDL_INIT_AUDIO);
 	 SDL_AudioSpec wavSpec;
  	Uint32 wavLength;
  	Uint8 *wavBuffer;
 	 SDL_LoadWAV("bush_read.wav", &wavSpec, &wavBuffer, &wavLength);
 	 SDL_AudioDeviceID deviceID = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
 	 int success = SDL_QueueAudio(deviceID,wavBuffer,wavLength);
 	 SDL_PauseAudioDevice(deviceID,0);
 	 

}


