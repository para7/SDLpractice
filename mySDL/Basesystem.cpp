#include "Basesystem.hpp"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "Data class.hpp"

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
    
    bool exitflag = true;
    
    void SystemInit(double w_rate)
    {
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
    
    
    bool Update()
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
        //レンダリングの結果を画面に反映する
        SDL_RenderPresent(render);
        //描画操作(長方形, 直線, 消去)で使う色を設定する
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        //現在のレンダリングの対象を色で塗りつぶして消去する
        SDL_RenderClear(render);
        //フレームレート調整
        flamerate.flamewait();
        return exitflag;
    }
    
    void DrawLine(int x, int y, int x2, int y2 ,Color color)
    {
        SDL_SetRenderDrawColor(render, color.red, color.green, color.blue, color.alpha);
        SDL_RenderDrawLine(render, x, y, x2, y2);
        
    }
    
    void Quit()
    {
        SDL_Quit();
    }
}
