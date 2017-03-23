#include "Data class.hpp"
#include "Define.hpp"
#include SDL2_path

namespace mySDL
{
        bool Color:: operator >(const Color& rhs) const
    {
        if(this->r != rhs.r) return this->r > rhs.r;
        if(this->g != rhs.g) return this->g > rhs.g;
        if(this->b != rhs.b) return this->b > rhs.b;
        if(this->a != rhs.a) return this->a > rhs.a;
        return false;
    }
bool    Color::  operator <(const Color& rhs) const
    {
        if(this->r != rhs.r) return this->r < rhs.r;
        if(this->g != rhs.g) return this->g < rhs.g;
        if(this->b != rhs.b) return this->b < rhs.b;
        if(this->a != rhs.a) return this->a < rhs.a;
        return false;
        return false;
    }
    bool Color:: operator ==(const Color& rhs) const
    {
        return this->r == rhs.r &&
               this->b == rhs.b &&
               this->g == rhs.g &&
               this->a == rhs.a;
    }
    
    Color::Color(SDL_Color col)
    {
        this->r = col.r;
        this->g = col.g;
        this->b = col.b;
        this->a = col.a;
    }
    
    Color::Color()
    {
        r = g = b = a = 0;
    };
    
    Color::Color(int _red , int _green , int _blue)
    {
        r = _red;
        g = _green;
        b = _blue;
        a = 0;
    };
    
    Color::Color(int _red , int _green , int _blue , int _alpha)
    {
        r = _red;
        g = _green;
        b = _blue;
        a = 0;
    };
    
    namespace Defines
    {
        const mySDL::Color White(255,255,255);
        const mySDL::Color Black(0,0,0);
        const mySDL::Color Red(255,0,0);
        const mySDL::Color Green(0,255,0);
        const mySDL::Color Blue(0,0,255);
    }
}
