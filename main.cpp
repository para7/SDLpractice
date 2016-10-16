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
        DrawLine(10+ a, 10, 400+a, 400 , Color(255,0,0));
        
        a ++ ;
    }
    
    Quit();
    return 0;
}
