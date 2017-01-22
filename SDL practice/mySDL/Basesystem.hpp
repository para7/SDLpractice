#ifndef Basesystem_hpp
#define Basesystem_hpp

#include "Data class.hpp"
#include "Define.hpp"
#include SDL2_path

namespace mySDL
{
    extern SDL_Window *window;
    extern SDL_Renderer *render;
    
    void SystemInit(double w_rate,int fps = 60,bool call_quit = true);
    bool Update();
    void Error();
    
    void Quit(bool callquit = false);
}
#endif /* Basesystem_hpp */
