#ifndef Draw_Text_hpp
#define Draw_Text_hpp

#include "Define.hpp"
#include <string>
#include SDL2_path
#include SDL2ttf_path

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
    
    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const char  *str    ,const char *fontname);
    //    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str );
//    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str ,const char *fontname = NULL);
    //    void DrawText(const int x,const int y,const char  *str ,TTF_Font *font );
    //    void DrawText(const int x,const int y,std::string *str ,TTF_Font *font );
}
#endif /* Draw_Text_hpp */
