#ifndef DrawTexture_hpp
#define DrawTexture_hpp

#include "Define.hpp"
#include SDL2_path
#include <string>

namespace mySDL
{
    class Texture
    {
    private:
        int w,h;
        SDL_Texture *texture;
        SDL_Rect drawrect;
        void loadempty();
    public:
        Texture();
        Texture(std::string image_path);
        ~Texture();
        
        void draw(int x,int y);
    };
    
}

#endif /* DrawTexture_hpp */
