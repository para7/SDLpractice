#ifndef Data_class_hpp
#define Data_class_hpp

#include "Define.hpp"
#include SDL2_path

namespace mySDL
{
    
    class Color final : public SDL_Color
    {
    private:
        
    public:
        Color(SDL_Color col);
        Color();
        Color(int _red , int _green , int _blue );
        Color(int _red , int _green , int _blue , int _alpha);
        
        bool operator >(const Color& rhs) const;
        bool operator <(const Color& rhs) const;
        bool operator ==(const Color& rhs) const;
        inline bool operator !=(const Color rhs) const
        {
            return !(*this == rhs);
        }
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
