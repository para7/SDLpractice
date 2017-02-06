#include "DrawText.hpp"
#include "Basesystem.hpp"
#include "Data class.hpp"
#include "Make structs.hpp"
#include "Define.hpp"
#include <string>

#include SDL2_path

namespace mySDL
{
    
    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const char  *str ,const char  *fontname)
    {
        if(fontname == NULL)
        {
            //            fontname = "游ゴシック";
            return;
        }
        TTF_Font *font;
        SDL_Surface *textsur;
        SDL_Texture *texttex;
        int w,h;
        
        font = TTF_OpenFont(fontname, size);
        
        if(font == NULL)
        {
            printf("TTF_OpenFont: %s\n", TTF_GetError());
            return;
            //            font = TTF_OpenFont("游ゴシック", size);
        }
        textsur = TTF_RenderUTF8_Blended(font, str, color);
        texttex = SDL_CreateTextureFromSurface(render, textsur);
        SDL_QueryTexture(texttex, NULL, NULL, &w, &h);
        auto drawrect = makeRect(x, y, w, h);
        SDL_RenderCopy(render, texttex, NULL, &drawrect);
    }
/*
    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str ,const char *fontname)
    {
        DrawText(x, y, size, color, str.c_str(),fontname);
        return;
    }
*/
    
}
