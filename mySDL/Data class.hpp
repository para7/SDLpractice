#ifndef Data_class_hpp
#define Data_class_hpp

namespace mySDL
{

class Color
{
private:
    
public:
    int red;
    int green;
    int blue;
    int alpha;
    
    Color();
    Color(int _red , int _green , int _blue );
    Color(int _red , int _green , int _blue , int _alpha);
};

}

#endif /* Data_class_hpp */
