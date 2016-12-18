

#include "Make structs.hpp"
#include "Define.hpp"
#include SDL2_path

namespace  mySDL
{
    
    
    SDL_Rect makeRect(int x, int y, int w, int h)
    {
        SDL_Rect ret;
        ret.x = x;
        ret.y = y;
        ret.w = w;
        ret.h = h;
        return ret;
    }
    
}
