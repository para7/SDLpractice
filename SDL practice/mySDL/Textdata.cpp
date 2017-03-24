#include "Textdata.hpp"

#include <array>
#include <string>
#include <algorithm>
#include <array>
#include <map>
#include <cstdio>
#include <memory>

#include "Define.hpp"
#include SDL2_path
#include SDL2ttf_path

#include "Basesystem.hpp"
#include "Make structs.hpp"

namespace mySDL
{
    
    Number_font::Number_font(const std::string &font_path, const int size,const SDL_Color &color)
//    Number_font::Number_font(std::string font_path, int size,SDL_Color color)
    :
    fontname(font_path),
    fontsize(size),
    fontcolor(color)
    {
        const std::array<char,12> for_make = {'0','1','2','3','4','5','6','7','8','9','-','.'};//surface生成用文字列に終端文字が必要で面倒なのでstringにしている
        
        TTF_Font *font;
        SDL_Surface *sur;

        font = TTF_OpenFont(font_path.c_str(), fontsize);
        
        if(font == NULL)
        {
            printf("%s\n", TTF_GetError());//エラー
            
            //空の画像を生成
            for(auto c : for_make)
            {
                texttex[c].texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_BGRA8888, SDL_TEXTUREACCESS_TARGET, 1, 1);
                texttex[c].width = 1;
            }
            height = 1;
            return;
        }
        
        char str[2];
        height = 0;
        for(auto c : for_make)
        {
            int h;
            str[0] = c,str[1] = '\0';
            sur = TTF_RenderUTF8_Blended(font, str, fontcolor);
            texttex[c].texture = SDL_CreateTextureFromSurface(renderer, sur);
            SDL_QueryTexture(texttex[c].texture, NULL, NULL, &texttex[c].width, &h);
            height = std::max(height,h);
            SDL_FreeSurface(sur);
        }
        
        TTF_CloseFont(font);
    }
    
    Texture_with_width* Number_font::output(int number)
    {
        return &texttex[number];
    }
    
    Number_font::~Number_font()
    {
        for(int i=0;i<=11;++i)
        {
            SDL_DestroyTexture(texttex[i].texture);
        }
    }
    
    NumberTextures :: NumberTextures(const std::string &font_path, int size,SDL_Color const &color) : Number_font(font_path,size,color)
    {}
    
    NumberTextures :: NumberTextures(const FONT_TEXTURE_INFO &data) : Number_font(std::get<0>(data),std::get<1>(data),std::get<2>(data))
    {}
    
    void NumberTextures :: draw(const int x,const int y,         long long number , SDL_Rect *get_region, bool drawflag)
    {
        int w = 0;//合計横幅
        
        //文字列にした数字を一桁ずつ描画
        std::string str = std::to_string(number);
        
        if(drawflag)
        {
            for(char c : str)
            {
                SDL_Rect drawregion =makeRect(x + w, y, texttex[c].width,height);
                SDL_RenderCopy(renderer, texttex[c].texture,  NULL, &drawregion);
                w += texttex[c].width;
            }
        }
        else
        {
            for(char c : str)
            {
                w += texttex[c].width;
            }
        }
        
        if(get_region != nullptr) //範囲計算
        {
            *get_region = makeRect(x, y, w, height);
        }
    }
    
    void NumberTextures :: draw(int x,int y,double number ,int digits, SDL_Rect *get_region, bool drawflag)
    {
        int w = 0;
        int cnt = 0;
        std::string str = std::to_string(number);
        std::string sstr {};
        
        for(char c : str)
        {
            cnt++;
            if(drawflag)
            {
                SDL_Rect drawregion =makeRect(x + w, y, texttex[c].width,height);
                SDL_RenderCopy(renderer, texttex[c].texture,  NULL, &drawregion);
            }
            w += texttex[c].width;
            if(c=='.')
            {
                sstr = str.substr(cnt);
                break;
            }
        }
        
        char c;
        for(int i = 0; i < digits;++i)
        {
            i < sstr.size() ? c = sstr[i] : c = 0;
            
            if(drawflag)
            {
                SDL_Rect drawregion =makeRect(x + w, y, texttex[c].width,height);
                SDL_RenderCopy(renderer, texttex[c].texture,  NULL, &drawregion);
            }
            w += texttex[c].width;
        }
        
        if(get_region != nullptr) //範囲計算
        {
            *get_region = makeRect(x, y, w, height);
        }
    }
    
    void TTFTextures::draw(const int x,const int y,const std::string str, SDL_Rect *const get_region, const bool drawflag)
    {
        if(textures.count(str) == 0)
        {
            TTF_Font *font;
            SDL_Surface* sur;
            font = TTF_OpenFont(std::get<0>(textureinfo).c_str(), std::get<1>(textureinfo));
            sur = TTF_RenderUTF8_Blended(font, str.c_str(), std::get<2>(textureinfo));
            textures[str] = SDL_CreateTextureFromSurface(renderer, sur);
            TTF_CloseFont(font);
            SDL_FreeSurface(sur);
        }
        SDL_Rect dstrect;
        dstrect.x = x;dstrect.y = y;
        SDL_QueryTexture(textures[str], nullptr, nullptr, &dstrect.w, &dstrect.h);
        SDL_RenderCopy(renderer, textures[str], nullptr, &dstrect);
        
        if(get_region!= nullptr)
        {
            *get_region = dstrect;
        }
    }
    
    TTFTextures::~TTFTextures()
    {
        for(auto &tex : textures)
        {
            SDL_DestroyTexture(tex.second);
        }
    }
}
/*
 一桁ずつ描画
 格納をランダムアクセス可能配列にする
 数値を利用し直接アクセス→返ってきたSDL_Textureを描画、QueryTextureで事前に取得していた画像幅分ずらしてまた描画、の繰り返し
 
///////
 浮動小数点数の描画
 sprintfで少数と整数部分に分けて取り出す
 
 コピペを微編集したもの↓
 sprintf("整数部=%f\n", (int)n);
 sprintf("実数部=%f\n", n - (int)n);
 
 文字描画関数の最後にSDL_Rectの引数をつくる
 SDL_Rect *rect = nullptr;
 ここに描画範囲を代入する !rect
*/
