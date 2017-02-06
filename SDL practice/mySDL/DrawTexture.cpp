#include "DrawTexture.hpp"

#include "Define.hpp"
#include SDL2_path
#include SDL2image_path
#include "Basesystem.hpp"
#include "Make structs.hpp"

namespace mySDL
{
    void Texture::loadempty()
    {
        texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);
        drawrect = makeRect(0, 0, 100, 100);
        if(texture == NULL)
        {
            Error();
        }
    }
    
    Texture::Texture()
    {
        loadempty();
    }
    Texture::Texture(std::string image_path)
    {
        auto road = IMG_Load(image_path.c_str());
        
        if(road == NULL)
        {
            loadempty();
        }
        else
        {
            texture = SDL_CreateTextureFromSurface(render, road);
        }
        
        SDL_QueryTexture(texture, NULL, NULL, &drawrect.w, &drawrect.h);
        
        SDL_FreeSurface(road);
    }
    Texture::~Texture()
    {
        SDL_DestroyTexture(texture);
    }
        
    void Texture::draw(int x,int y)
    {
        drawrect.x = x;
        drawrect.y = y;
        SDL_RenderCopy(render, texture, NULL, &drawrect);
    }
}
