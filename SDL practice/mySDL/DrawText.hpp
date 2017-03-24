#ifndef Draw_Text_hpp
#define Draw_Text_hpp

#include <string>

#include "Define.hpp"
#include SDL2_path
#include SDL2ttf_path

#include "Textdata.hpp"
#include "Data class.hpp"


namespace  mySDL
{
    namespace    TTF_Numbers
    {
        void DrawText(int x, int y,long long value,unsigned int fontsize = 20,const SDL_Color &color = Defines::White,const std::string &fontpath = "Yu Gothic Bold.otf",SDL_Rect* drawregion = nullptr,bool skip_drawprcess = false);
        
        void DrawText(int x, int y,double    value,int digits,unsigned int fontsize = 20,const SDL_Color &color = Defines::White,const std::string &fontpath = "Yu Gothic Bold.otf",SDL_Rect* drawregion = nullptr,bool skip_drawprcess = false);
    }
    namespace TTF_Strings
    {
        void DrawText(int x, int y,std::string str,unsigned int fontsize = 20,const SDL_Color &color = Defines::White,const std::string &fontpath = "Yu Gothic Bold.otf",SDL_Rect* drawregion = nullptr,bool skip_drawprcess = false);
    }
}
using namespace mySDL::TTF_Numbers;
using namespace mySDL::TTF_Strings;
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
    
    

    
//    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str );
//    void DrawText(const int x,const int y,const int size ,SDL_Color &color ,const std::string &str ,const char *fontname = NULL);
    //    void DrawText(const int x,const int y,const char  *str ,TTF_Font *font );
    //    void DrawText(const int x,const int y,std::string *str ,TTF_Font *font );

#endif /* Draw_Text_hpp */
