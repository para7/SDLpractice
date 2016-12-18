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
    
    //Updateでfps調整まで可能
    int a = 0;
    while(Update())
    {
        Color d = Defines::Red;
        DrawRect(50, 100, 30, 70,Defines::Green);
        Rect();
        DrawLine(10+ a, 10, 400+a, 400 , d);
        a ++ ;
    }
    
//    Quit();
    return 0;
}
