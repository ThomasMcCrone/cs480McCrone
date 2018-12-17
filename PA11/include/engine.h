#ifndef ENGINE_H
#define ENGINE_H

#include <sys/time.h>
#include <assert.h>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "window.h"
#include "graphics.h"


class Engine
{
  public:
    Engine(string name, int width, int height);
    Engine(string name);
    ~Engine();
    bool Initialize();
    void Run();
    void Keyboard();
    unsigned int getDT();
    long long GetCurrentTimeMillis();
    void playDeath();
  
  private:
    // Window related variables
    Window *m_window;    
    string m_WINDOW_NAME;
    int m_WINDOW_WIDTH;
    int m_WINDOW_HEIGHT;
    bool m_FULLSCREEN;
    SDL_Event m_event;

    Graphics *m_graphics;
    unsigned int m_DT;
    long long m_currentTimeMillis;
    bool m_running;
    Mix_Music *musicptr;
    
    //lives control variables
    int player1Lives;
    int player2Lives;
    
    //variables to help with player movement
    bool player1Up;
    bool player1Down;
    bool player1Left;
    bool player1Right;
    bool player2Up;
    bool player2Down;
    bool player2Left;
    bool player2Right;
};

#endif // ENGINE_H
