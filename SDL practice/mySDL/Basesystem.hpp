#ifndef Basesystem_hpp
#define Basesystem_hpp

#include "Data class.hpp"
#include "Define.hpp"
#include SDL2_path

namespace mySDL
{
    extern SDL_Window *window;
    extern SDL_Renderer *render;
    
    void SystemInit(double w_rate,int fps = 60);
    bool Update();
    void DrawLine(int x, int y, int x2, int y2 ,Color color);
    
    void Quit(bool callquit = false);
}
#endif /* Basesystem_hpp */
