
#ifndef Figure_base_hpp
#define Figure_base_hpp

#include "Define.hpp"
#include SDL2_path

#include "Data class.hpp"
#include "Make structs.hpp"

namespace mySDL
{
    
    class figure
    {
    protected:
    public:
        virtual void draw() const =0; //描画
        virtual void move(int _x, int _y) =0; //現在位置から移動
        virtual void jump(int _x,int _y) =0; //指定位置へ移動
        
    };
    
    //座標クラス
    class Point : public figure
    {
    protected:
        int x,y;
    public:
        void draw() const override;
        void move(int _x, int _y) override;
        void jump(int _x, int _y) override;
        Point();
    };
    
    //SDL_Rectを微改良したもの
    class Rect : public figure
    {
    private:
        double angle;
        Color c;
    public:
        SDL_Rect rect;
        
        Rect();
        Rect(int x,int y, int w, int h);
        Rect(int x,int y, int w, int h, Color color);
    
        void draw() const override;
        void move(int _x, int _y) override;
        void jump(int _x, int _y) override;
    };
}

#endif /* Figure_base_hpp */
