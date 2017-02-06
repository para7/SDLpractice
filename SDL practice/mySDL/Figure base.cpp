#include "Define.hpp"

#include "Figure base.hpp"
#include SDL2_path
#include "Draw.hpp"
#include "Data class.hpp"

namespace mySDL
{
    Rect::Rect()
    :
        rect((SDL_Rect){0,0,100,100}),
        c(Defines::White)
    {}
    
    Rect::Rect(int x,int y, int w, int h)
    :
        rect((SDL_Rect){x,y,w,h}),
        c(Defines::White)
    {}
    
    Rect::Rect(int x,int y, int w, int h, Color color)
    :
        rect((SDL_Rect){x,y,w,h}),
        c(color)
    {}
    
    void Rect::draw() const
    {
        DrawRect(rect, c);
    }
    
    void Rect::drawfill() const
    {
        
    }
    
    void Rect::move(int _x, int _y)
    {
        rect.x += _x;
        rect.y += _y;
    }
    
    void Rect::jump(int _x, int _y)
    {
        rect.x = _x;
        rect.y = _y;
    }
}
