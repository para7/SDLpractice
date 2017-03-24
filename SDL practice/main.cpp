#include <stdio.h>
#include <string>
#include <vector>

#include "mySDL/mySDL.hpp"

using namespace mySDL;

//Screen dimension constants
int main( int argc, char* args[] )
{
    //最初に呼び出すこと
    SystemInit(2.0);
    
    int a = 0;
    Rect rect;
    
    Texture test("manda.png");
    
    int pasttime = 0,time = 0,per = 58,fps = 0;
    
    while(Update())
    {
        a ++ ;
        
        if(per > 60)
        {
            pasttime = SDL_GetTicks();
            per = 0;
        }
        else
        {
            time = SDL_GetTicks() - pasttime;
            ++per;
            fps = 1000.0/(time/per);
        }
        DrawText(0, 50, fps, 30,Defines::White,"Yu Gothic Bold.otf");
        DrawText(0, 0, "もじれつ", 30,Defines::White,"Yu Gothic Bold.otf");
        DrawText(0, 100, 40.1234,8, 30,Defines::White);
        DrawText(0, 130, 40.1234,2, 30,Defines::White);
    }
    
//    Quit();
    return 0;
}
