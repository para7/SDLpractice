//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <string>
#include<vector>


using namespace std;

SDL_Window *window;
SDL_Renderer *r;
SDL_Surface *s;
double windowrate;

class flamecontrol
{
private:
    double fps;
    int past;
    bool delay;
public:
    flamecontrol(){fps = 60;past = 0;}
    //fps変更
    void fpschange(double _fps)
    {
        fps = _fps;
    }
    void flamewait()
    {
        int wait = SDL_GetTicks() - past;
        if(wait > (1000.0/60.0))
        {
            SDL_Delay(wait);
        }
        past = SDL_GetTicks();
    }
}flamerate;

bool systemInit(double w_rate)
{
    windowrate = w_rate;
    
    if(SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        printf("%s",SDL_GetError());
        return false;
    }
    
    window = SDL_CreateWindow("GAME", 100, 100, 640 * w_rate, 480 * w_rate, 0);
    s = SDL_GetWindowSurface(window);
    
    return true;
    
}


bool update()
{
    SDL_Event Qevnts;
    if(SDL_PollEvent(&Qevnts))
    {
        
        switch(Qevnts.type)
        {
            case SDL_QUIT:
                return false;
                break;
            case SDL_KEYDOWN:
                if(Qevnts.key.keysym.sym==SDLK_ESCAPE ||
                   Qevnts.key.keysym.sym==SDLK_q) return false;
                break;
                
            default: break;
        }
    }
    
    //フレームレート調整
    flamerate.flamewait();
    auto surret = SDL_UpdateWindowSurface(window);
    if(surret < 0)
        {
            printf("%s",SDL_GetError());
        }
    return !(surret < 0);
}
vector<SDL_Window*> Dwin;

/*
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
    systemInit(1.0);
    
    while(update())
    {
        
    }
    
    SDL_Quit();
}
