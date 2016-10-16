//Using SDL and standard IO
#include <stdio.h>
#include <string>
#include <vector>

#include "mySDL.hpp"

using namespace mySDL;
/*
std::vector<SDL_Window*> Dwin;
void  create()
{
    static int a=0;
//    if( a>5 ) return;// true :false;

    string fname = "window" + to_string(a);
    SDL_Window *asdf = SDL_CreateWindow(fname.c_str(), 100, 100, 640 , 480 , 0);
    
    a++;
    Dwin.push_back(asdf);
}
*/

//Screen dimension constants
int main( int argc, char* args[] )
{
    SystemInit(1.0);
    
    while(Update())
    {
        DrawLine(10, 10, 400, 400);
        
    }
    
    Quit();
    return 0;
}
