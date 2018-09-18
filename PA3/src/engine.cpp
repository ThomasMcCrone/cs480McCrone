
#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
  m_REVERSE_DIRECTION_ROTATION = false;
  IS_REVERSED_ROTATION = false;
  m_REVERSE_DIRECTION_ORBIT = false;
  IS_REVERSED_ORBIT = false;
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

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    
    if(!m_REVERSE_DIRECTION_ORBIT) m_graphics->Update(m_DT,2);
    else m_graphics->Update(m_DT,4);
    
    if(!m_REVERSE_DIRECTION_ROTATION) m_graphics->Update(m_DT,1);
    else m_graphics->Update(m_DT,3);
    
    
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
    
    
  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    // handle key down events here
    if (m_event.key.keysym.sym == SDLK_ESCAPE)
    {
      m_running = false;
    }
    //orbit left
    else if(m_event.key.keysym.sym == SDLK_UP || m_event.key.keysym.sym == SDLK_w)
    {
    	if(!IS_REVERSED_ORBIT)
    	{
    		m_REVERSE_DIRECTION_ORBIT = true;
    		IS_REVERSED_ORBIT = true;
    	}
    	
    }
    //orbit right
    else if(m_event.key.keysym.sym == SDLK_DOWN || m_event.key.keysym.sym == SDLK_s)
    {
    	if(IS_REVERSED_ORBIT)
    	{
    		m_REVERSE_DIRECTION_ORBIT = false;
    		IS_REVERSED_ORBIT = false;
    	}
    }
    //spin left
    else if(m_event.key.keysym.sym == SDLK_LEFT || m_event.key.keysym.sym == SDLK_a)
    {
    	if(!IS_REVERSED_ROTATION)
    	{
    		m_REVERSE_DIRECTION_ROTATION = true;
    		IS_REVERSED_ROTATION = true;
    	}
    }
    //spin right
    else if(m_event.key.keysym.sym == SDLK_RIGHT || m_event.key.keysym.sym == SDLK_d)
    {
    	if(IS_REVERSED_ROTATION)
    	{
    		m_REVERSE_DIRECTION_ROTATION = false;
    		IS_REVERSED_ROTATION = false;
    	}
    }
  }
  
  //left controls orbit
  if(m_event.button.button == SDL_BUTTON_LEFT)
  {
  	if(m_event.type == SDL_MOUSEBUTTONDOWN)
  	{
  		if(!IS_REVERSED_ORBIT)
    		{
    			m_REVERSE_DIRECTION_ORBIT = true;
    			IS_REVERSED_ORBIT = true;
    		}
    		else
    		{
    			m_REVERSE_DIRECTION_ORBIT = false;
    			IS_REVERSED_ORBIT = false;
    		}
    	}
  }
  //right controls spin
  else if(m_event.button.button == SDL_BUTTON_RIGHT)
  {
  	if(m_event.type == SDL_MOUSEBUTTONDOWN)
  	{
  		if(!IS_REVERSED_ROTATION)
    		{
    			m_REVERSE_DIRECTION_ROTATION = true;
    			IS_REVERSED_ROTATION = true;
    		}
    		else
    		{
    			m_REVERSE_DIRECTION_ROTATION = false;
    			IS_REVERSED_ROTATION = false;
    		}
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
