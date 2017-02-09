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
    
    Uint32 pasttime = 0,time = 0,per = 0,fps = 0;
    
    while(Update())
    {
        {
        Color d = Defines::Red;
//        DrawRect(50, 100, 30, 70,Defines::Green);
//        rect.draw();
        
//        DrawLine(10+ a, 10, 400+a, 400 , d);
        a ++ ;
        a = a%60;
        
//        test.draw(250, 250);
        
        auto cc = Defines::White;

        if(per > 60)
        {
            pasttime = SDL_GetTicks();
            per = 0;
        }
        else
        {
             time = SDL_GetTicks() - pasttime;
             per ++;
            fps = 1000.0/(time/per);
        }
        
        auto str = "FPS : " + std::to_string(fps);
        DrawText(30, 240, 20,cc,str.c_str(), "Yu Gothic Bold.otf" );
        }
    }
    
//    Quit();
    return 0;
}
