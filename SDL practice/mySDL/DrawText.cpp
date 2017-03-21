#include "DrawText.hpp"
#include <string>
#include <map>
#include <memory>

#include "Define.hpp"
#include SDL2_path

#include "Basesystem.hpp"
#include "Data class.hpp"
#include "Make structs.hpp"
#include "Textdata.hpp"

namespace mySDL
{
    static std::map <FONT_TEXTURE_INFO,std::unique_ptr<NumberTextures>> numberdraws;

    SDL_Rect DrawText(int x, int y,unsigned int fontsize,const std::string &fontpath,const SDL_Color &color,long long value,bool skip_drawprcessing)
    {

        //    Texture_with_width
        //tupleをキーにしたmapで管理
        FONT_TEXTURE_INFO drawinfo(fontpath,fontsize,color);
        
        if(numberdraws.find(drawinfo) == numberdraws.end())
        {
            numberdraws[drawinfo] = std::unique_ptr<NumberTextures>(new NumberTextures(drawinfo));
        }
        
        //texs.draw(0,0, value);
        
        return {0,0,0,0};
    }
}
