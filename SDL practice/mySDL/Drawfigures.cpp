#include "Define.hpp"

#include "Drawfigures.hpp"
#include "Draw.hpp"

#include "Data class.hpp"
#include "Basesystem.hpp"
#include "Make structs.hpp"

namespace mySDL
{
    void DrawLine(int x, int y, int x2, int y2 ,Color color)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(renderer, x, y, x2, y2);
        
    }
    //長方形を描画
    void DrawRect(int x, int y, int w, int h,Color color)
    {
        auto rect = makeRect(x, y, w, h);
        setDrawColor(color);
//        SDL_RenderDrawRect(render, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
    void DrawRect(SDL_Rect rect,Color color)
    {
        setDrawColor(color);
        SDL_RenderDrawRect(renderer, &rect);
    }
}
