#include "Data class.hpp"

namespace mySDL
{
    Color::Color()
    :
    red   (0),
    green (0),
    blue  (0),
    alpha (0)
    {};
    
    Color::Color(int _red , int _green , int _blue)
    :
    red   ( _red   ),
    green ( _green ),
    blue  ( _blue  ),
    alpha ( 0 )
    {};
    
    Color::Color(int _red , int _green , int _blue , int _alpha)
    :
    red   ( _red   ),
    green ( _green ),
    blue  ( _blue  ),
    alpha ( _alpha )
    {};
}
