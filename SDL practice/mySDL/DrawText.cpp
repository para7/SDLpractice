#include "DrawText.hpp"
#include <string>
#include <map>
#include <unordered_map>
#include <memory>
#include <set>
#include <tuple>
#include <functional>

#include "Define.hpp"
#include SDL2_path

#include "Basesystem.hpp"
#include "Data class.hpp"
#include "Make structs.hpp"
#include "Textdata.hpp"

namespace mySDL
{
    
    std::map <FONT_TEXTURE_INFO,std::unique_ptr<NumberTextures>> numberdraws;

    void DrawText(const int x,const int y,const long long value,const unsigned int fontsize,const SDL_Color &color,const std::string &fontpath,SDL_Rect * drawregion,bool skip_drawprcess)
    {
        Color co(color);
        //tupleをキーにしたmapで管理
        auto drawinfo = std::make_tuple(fontpath,fontsize,co);
        
        if(numberdraws.find(drawinfo) == numberdraws.end())
        {
            numberdraws[drawinfo] = std::unique_ptr<NumberTextures>(new NumberTextures(drawinfo));
        }
        
        numberdraws[drawinfo]->draw(x, y, value,drawregion,!skip_drawprcess);
    }
    void DrawText(const int x,const int y,const double value,const int digits,const unsigned int fontsize,const SDL_Color &color,const std::string &fontpath,SDL_Rect * drawregion,bool skip_drawprcess)
    {
        Color co(color);
        //tupleをキーにしたmapで管理
        auto drawinfo = std::make_tuple(fontpath,fontsize,co);
        
        if(numberdraws.find(drawinfo) == numberdraws.end())
        {
            numberdraws[drawinfo] = std::unique_ptr<NumberTextures>(new NumberTextures(drawinfo));
        }
        
        numberdraws[drawinfo]->draw(x, y, value,digits,drawregion,!skip_drawprcess);
    }
    
    
}
