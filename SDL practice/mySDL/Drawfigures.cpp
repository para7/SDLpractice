#include "Define.hpp"

#include "Drawfigures.hpp"

#include "Data class.hpp"
#include "Basesystem.hpp"

namespace mySDL
{
    void DrawLine(int x, int y, int x2, int y2 ,Color color)
    {
        SDL_SetRenderDrawColor(render, color.red, color.green, color.blue, color.alpha);
        SDL_RenderDrawLine(render, x, y, x2, y2);
        
    }
    
}
