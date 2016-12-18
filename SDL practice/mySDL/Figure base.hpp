
#ifndef Figure_base_hpp
#define Figure_base_hpp

#include "Define.hpp"
#include SDL2_path

#include "Make structs.hpp"

namespace mySDL
{
    
    class figure
    {
    protected:
    public:
        int x;
        int y;
        virtual void draw() const =0; //描画
        virtual void move(int _x, int _y) =0; //現在位置から移動
        virtual void jump(int _x,int _y) =0; //指定位置へ移動
        
    };
    
    class Point : public figure
    {
    private:
    public:
        void draw() const override;
        void move(int _x, int _y) override;
        void jump(int _x, int _y) override;
    };
    
    class Rect : public figure
    {
    private:
        SDL_Rect rect;
        double angle;
        Color c;
    public:
        SDL_Rect GetRect() const;//内部をSDL_Rectにして返します
        
        void draw() const override;
        void move(int _x, int _y) override;
        void jump(int _x, int _y) override;
    };
}

#endif /* Figure_base_hpp */
