
#include "Define.hpp"
#include <cstdio>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_mixer.lib")
#pragma comment(lib, "SDL2_ttf.lib")

#include SDL2_path
#include <SDL2_image/SDL_image.h>
#include SDL2ttf_path
#include "Basesystem.hpp"
#include "Make structs.hpp"

/*
 namespace mySDL
 {
 class flamecontrol
 {
 private:
 double fps;
 double past;
 //  bool delay;
 public:
 flamecontrol()          :fps(60),  past(0){}
 flamecontrol(double _fps)  :fps(_fps),past(0){}
 //fps変更
 
 void fpschange(double _fps)
 {
 fps = _fps;
 }
 
 void flamewait()
 {
 int wait = - (Uint32)(1000.0/fps) - (SDL_GetTicks() - past);
 if(wait > 0)
 {
 SDL_Delay(wait);
 }
 past = SDL_GetTicks();
 }
 };
 
 }
 */

namespace mySDL
{
    SDL_Rect windowrect;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *SDL_TEXTURE_FORINIT;
    
    void BasestatusInit()
    {
        windowrect = makeRect(0, 0, 640, 480);
        window = SDL_CreateWindow("GAME", 100, 100, 640, 480, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // 拡大縮小が滑らかになる
        SDL_RenderSetLogicalSize(renderer, 640, 480);//拡縮に対応した固定画面サイズをセット

        //初期化用数値
        SDL_TEXTURE_FORINIT = SDL_CreateTexture(renderer,  SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET, 0, 0);
    }
}

namespace mySDL
{
//    double windowrate;
    bool callquit = true;
    bool exitflag = true;
    
    //    flamecontrol flamerate;
    
    void SystemInit(double w_rate,int fps,bool call_quit)
    {
        callquit = call_quit;
        
//        windowrate = w_rate;
        
        if(SDL_Init( SDL_INIT_VIDEO ) < 0)
        {
            Error();
            return;
        }
        if(TTF_Init() < 0)
        {
            printf("TTF_Init error : %s",TTF_GetError());
            Error();
            return;
        }
        
        // 描画操作(長方形, 直線, 消去)で使う色を得る
//        SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
        
        // JPGとPNG形式の画像を読み込めるようにする
        int flags=IMG_INIT_JPG|IMG_INIT_PNG;
        int initted=IMG_Init(flags);
        if(initted != flags)
        {
            printf("IMG_Init: JPGとPNGの読み込みの初期化に失敗した!\n");
            printf("IMG_Init: %s\n", IMG_GetError());
            // ここでエラー処理を行う
            Error();
        }
        BasestatusInit();
    }
    
    
    bool Events()
    {
        SDL_Event Qevnts;
        while(SDL_PollEvent(&Qevnts))
        {
            
            switch(Qevnts.type)
            {
                case SDL_QUIT:
                    return false;
                    break;
                case SDL_KEYDOWN:
                    if(Qevnts.key.keysym.sym==SDLK_ESCAPE || Qevnts.key.keysym.sym==SDLK_q) return false;
                    break;
                    
                default: break;
            }
        }
        return true;
    }
    
    bool Update()
    {
        
        //レンダリングの結果を画面に反映する
        SDL_RenderPresent(renderer);
        //描画操作(長方形, 直線, 消去)で使う色を設定する
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //現在のレンダリングの対象を色で塗りつぶして消去する
        SDL_RenderClear(renderer);
        //フレームレート調整
        //        flamerate.flamewait();
        exitflag = exitflag & Events();
        
        if((!exitflag) & callquit){Quit();}
        return exitflag;
    }
    
    
    void Quit()
    {
        SDL_Quit();
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
    }
    
    void Error()
    {
        printf("%s¥n",SDL_GetError());
        exitflag = false;
        return;
    }
}
