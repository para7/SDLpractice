#ifndef Drawfigures_hpp
#define Drawfigures_hpp


#include "Define.hpp"
#include "Data class.hpp"

#include SDL2_path

namespace mySDL
{
    void DrawLine(int x, int y, int x2, int y2 ,Color color = Defines::White);
    void DrawRect(int x, int y, int w, int h,Color color = Defines::White);
    void DrawRect(SDL_Rect rect,Color color = Defines::White);
}
#endif /* Drawfigures_hpp */
