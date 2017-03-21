
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
    
    class Rect : public figure
    {
    private:
//        double angle;
    public:
        SDL_Rect s_rect;
        Color c;

        Rect();
        Rect(int x,int y, int w, int h);
        Rect(int x,int y, int w, int h, Color color);
        
        SDL_Rect GetRect() const
        {
            return s_rect;
        }//内部をSDL_Rectにして返します
        void draw() const override;
        void drawfill() const;
        void move(int _x, int _y) override;
        void jump(int _x, int _y) override;
    };
}

#endif /* Figure_base_hpp */
