#ifndef Basesystem_hpp
#define Basesystem_hpp

#include "Data class.hpp"
#include "Define.hpp"
#include SDL2_path

namespace mySDL
{
    extern SDL_Rect windowrect;
    extern SDL_Window *window;
    extern SDL_Renderer *renderer;
    
    extern SDL_Texture *SDL_TEXTURE_FORINIT;
    
    void BasestatusInit();
}

namespace mySDL
{
    
    void SystemInit(double w_rate,int fps = 60,bool call_quit = true);
    bool Update();
    void Error();
    
    void Quit();
}
#endif /* Basesystem_hpp */
