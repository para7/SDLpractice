#include "Data class.hpp"
#include "Define.hpp"
#include SDL2_path

namespace mySDL
{
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
