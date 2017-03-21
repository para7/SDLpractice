#ifndef Textdata_hpp
#define Textdata_hpp

#include "Define.hpp"
#include SDL2ttf_path
#include "Basesystem.hpp"

#include <map>
#include <string>
#include <tuple>

namespace mySDL
{
    typedef std::tuple<std::string,int,SDL_Color> FONT_TEXTURE_INFO;//フォント名、サイズ、色
    
    //ちょっと付け足しただけ
    class Texture_with_width final
    {
    public:
        SDL_Texture *texture;
        int width;//頻繁なアクセスが発生するけど毎回SDL_QueryTexture呼ぶのはだるいので幅の数値を取っておく
        //int underscore;//高さ合わせ用　一番縦幅が大きいものに合わせて下にずらすことで下部を揃える
        
        Texture_with_width()//初期値設定用コンストラクタ
        :
        texture(SDL_TEXTURE_FORINIT),
        width(0)
        {}
    };
    
    //フォントテクスチャーの基本データ
    class Number_font
    {
    protected:
        std::map < char,Texture_with_width > texttex;
        const int fontsize;
        SDL_Color fontcolor;
        const std::string fontname;
        int height;
    public:
        Number_font(const std::string &font_path, int size,const SDL_Color &color);
//        Number_font(std::string font_path, int size,SDL_Color color);

        Texture_with_width* output(int number);
        virtual ~Number_font();
    };
    
    // フォントデータの比較、描画など
    class NumberTextures final : public Number_font
    {
    public:
        NumberTextures(const FONT_TEXTURE_INFO &data);
        NumberTextures(const std::string &font_path, int size,const SDL_Color &color);
        ~NumberTextures(){};
        //描画範囲をSDL_Rectで返す　falseを渡すと描画をスキップして範囲だけ返す
//        void draw(int x,int y,               int number , SDL_Rect *get_region = nullptr , bool drawflag = true);
//        void draw(int x,int y,          unsigned number , SDL_Rect *get_region = nullptr , bool drawflag = true);
        void draw(int x,int y,         long long number , SDL_Rect *get_region = nullptr , bool drawflag = true);//const; //  constつけたらmapにアクセスできなかった
        void draw(int x,int y,unsigned long long number , SDL_Rect *get_region = nullptr , bool drawflag = true);//const;
        void draw(int x,int y,             float number , SDL_Rect *get_region = nullptr , bool drawflag = true);//const;
        void draw(int x,int y,            double number , SDL_Rect *get_region = nullptr , bool drawflag = true);//const;
        
        FONT_TEXTURE_INFO status(){return FONT_TEXTURE_INFO{fontname,fontsize,fontcolor};}//比較用
    };
    
    /*
         staticなmapで読み込んだフォントデータを管理
         描画時にテクスチャーデータがなければロード
        */
    
/*
    class Number_font
    {
    protected:
        SDL_Surface number_sur[11];
    public:
        Number_font(const char *font_path, int size);
        ~Number_font();
    };
 */
}

#endif /* Textdata_hpp */
