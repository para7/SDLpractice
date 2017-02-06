#ifndef Data_class_hpp
#define Data_class_hpp

#include "Define.hpp"
#include SDL2_path

namespace mySDL
{
    
    class Color : public SDL_Color
    {
    private:
        
    public:
        SDL_Color color;
        Color();
        Color(int _red , int _green , int _blue );
        Color(int _red , int _green , int _blue , int _alpha);
    };
    
    namespace Defines
    {
        const extern mySDL::Color White;
        const extern mySDL::Color Black;
        const extern mySDL::Color Red;
        const extern mySDL::Color Green;
        const extern mySDL::Color Blue;
    } //namespace Defines
}


#endif /* Data_class_hpp */
