#ifndef Basesystem_hpp
#define Basesystem_hpp

#include "Data class.hpp"
#include <SDL2/SDL.h>

namespace mySDL
{
    extern SDL_Window *window;
    extern SDL_Renderer *render;
    
    void SystemInit(double w_rate);
    bool Update();
    void DrawLine(int x, int y, int x2, int y2 ,Color color);
    
    void Quit();
}
#endif /* Basesystem_hpp */
