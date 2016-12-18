#include "Define.hpp"

#include "Figure base.hpp"
#include SDL2_path
#include "Draw.hpp"
#include "Data class.hpp"

namespace mySDL
{
    class figure_base
    {
    public:
        virtual void draw() const =0; //描画
        virtual void move() =0; //現在位置から移動
        virtual void jump() =0; //指定位置へ移動
    };
    
    void Rect::draw() const
    {
        DrawRect(rect, c);
    }
    void Rect::move(int _x, int _y)
    {
        rect.x += _x;
        rect.y += _y;
    }
    void Rect::jump(int _x, int _y)
    {
        rect.x = _x;
        rect.y = _y;
    }

}
