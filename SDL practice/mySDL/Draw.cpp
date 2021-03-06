#include "Draw.hpp"
#include "Define.hpp"

#include "Basesystem.hpp"
#include "Data class.hpp"
#include SDL2_path

namespace mySDL
{
    void setDrawColor(int r,int g, int b,int a = 0)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }
    void setDrawColor(Color c)
    {
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    }
    
}
