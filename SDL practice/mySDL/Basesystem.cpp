
#include "Define.hpp"
#include <cstdio>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_mixer.lib")
#pragma comment(lib, "SDL2_ttf.lib")

#include SDL2_path
#include SDL2image_path
#include SDL2mixer_path
#include SDL2ttf_path
#include "Data class.hpp"
#include "Basesystem.hpp"
#include "Make structs.hpp"

namespace mySDL
{
    SDL_Window *window;
    SDL_Renderer *render;
    
    double windowrate;
    
    class flamecontrol
    {
    private:
        double fps;
        int past;
        bool delay;
    public:
        flamecontrol(int fps = 60)
        :fps(60),
        past(0)
        {}
        //fps変更
        void fpschange(double _fps)
        {
            fps = _fps;
        }
        void flamewait()
        {
            int wait = SDL_GetTicks() - past;
            if(wait < (1.0/60.0)*1000)
            {
                SDL_Delay(wait);
            }
            past = SDL_GetTicks();
        }
    };
    
    bool exitflag = true;
    
    flamecontrol flamerate;
    
    void SystemInit(double w_rate,int fps)
    {
        flamecontrol foo(fps);
        flamerate = foo;
        
        windowrate = w_rate;
        
        if(SDL_Init( SDL_INIT_VIDEO ) < 0)
        {
            printf("%s",SDL_GetError());
            exitflag = false;
            return;
        }
        
        window = SDL_CreateWindow("GAME", 100, 100, 640, 480, 0);
        render = SDL_CreateRenderer(window, -1, 0);
        
        // 描画操作(長方形, 直線, 消去)で使う色を得る
        SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
    }
    
    
    bool Events()
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
        return true;
    }
    
    bool Update()
    {
        
        //レンダリングの結果を画面に反映する
        SDL_RenderPresent(render);
        //描画操作(長方形, 直線, 消去)で使う色を設定する
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        //現在のレンダリングの対象を色で塗りつぶして消去する
        SDL_RenderClear(render);
        //フレームレート調整
        flamerate.flamewait();
        exitflag = exitflag & Events();
        
        if(!exitflag){Quit();}
        return exitflag;
    }
    
    
    void Quit(bool callquit)
    {
        if(callquit)SDL_Quit();
    }
}
