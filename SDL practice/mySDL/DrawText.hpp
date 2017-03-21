#ifndef Draw_Text_hpp
#define Draw_Text_hpp

#include <string>

#include "Define.hpp"
#include SDL2_path
#include SDL2ttf_path

#include "Textdata.hpp"

namespace  mySDL
{
    /*
     class Text
     {
     private:
     SDL_Texture *str_tex;
     void makeTexture();
     public:
     Text();
     void draw();
     SDL_Texture *ret_SDL_Texture(){return str_tex;}
     ~Text();
     };
     */
    
    SDL_Rect drawText(long long value,const std::string &fontpath = "");
    
//    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str );
//    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str ,const char *fontname = NULL);
    //    void DrawText(const int x,const int y,const char  *str ,TTF_Font *font );
    //    void DrawText(const int x,const int y,std::string *str ,TTF_Font *font );
}
#endif /* Draw_Text_hpp */
