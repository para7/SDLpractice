#include <stdio.h>
#include <string>
#include <vector>

#include "mySDL/mySDL.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

using namespace mySDL;


//Screen dimension constants
int main( int argc, char* args[] )
{
    //最初に呼び出すこと
    SystemInit(2.0);
    
    int a = 0;
    Rect rect;
    
    Texture test("manda.png");
    
    while(Update())
    {
        Color d = Defines::Red;
        DrawRect(50, 100, 30, 70,Defines::Green);
        rect.draw();
        DrawLine(10+ a, 10, 400+a, 400 , d);
        a ++ ;
        
        test.draw(250, 250);
    }
    
//    Quit();
    return 0;
}
