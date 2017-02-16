#include "DrawText.hpp"
#include "Basesystem.hpp"
#include "Data class.hpp"
#include "Make structs.hpp"
#include "Define.hpp"
#include <string>

#include SDL2_path

namespace mySDL
{
    static TTF_Font *font = nullptr;
    static SDL_Surface *textsur;
    static SDL_Texture *texttex;

    
    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const char  *str ,const char  *fontname)
    {
        SDL_Rect drawrect = {0,0,50,50};
        

        if(texttex == nullptr)
        {
            printf("call CreateTexture¥n");
            texttex = SDL_CreateTexture(renderer,         SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,640, 480);
        }
        if(textsur == nullptr)
        {
            textsur            = SDL_CreateRGBSurface(0, 640, 480, 32,0x00FF0000,0x0000FF00,0x000000FF,0xFF000000);
        }
        
        
        font = TTF_OpenFont(fontname, size);
        
        if(font == NULL)
        {
            printf("TTF_OpenFont: %s\n", TTF_GetError());
            TTF_CloseFont(font);
            SDL_FreeSurface(textsur);
            return;
        }
        textsur = TTF_RenderUTF8_Blended(font, str, color);
        drawrect = makeRect(0,0,textsur->w,textsur->h);
        SDL_UpdateTexture(texttex, &drawrect, textsur->pixels, textsur->pitch);
        SDL_RenderCopy(renderer, texttex, NULL, &drawrect);
        
        TTF_CloseFont(font);
        SDL_FreeSurface(textsur);
//        textsur = nullptr;
        SDL_DestroyTexture(texttex);
        
    }
/*
    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str ,const char *fontname)
    {
        DrawText(x, y, size, color, str.c_str(),fontname);
        return;
    }
*/
    
}
