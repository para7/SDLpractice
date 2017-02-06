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
    
    while(Update())
    {
        Color d = Defines::Red;
        DrawRect(50, 100, 30, 70,Defines::Green);
        rect.draw();
        DrawLine(10+ a, 10, 400+a, 400 , d);
        a ++ ;
        
        test.draw(250, 250);
        
        auto cc = Defines::White;
        
        DrawText(30, 240, 20,cc, "テキスト", "Yu Gothic Bold.otf" );
    }
    
//    Quit();
    return 0;
}
