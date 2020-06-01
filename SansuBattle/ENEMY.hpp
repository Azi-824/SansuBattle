//ENEMY.hpp
//敵を管理するクラス

#pragma once

//############### ヘッダファイル読み込み ####################
#include "CHARACTOR.hpp"

//############### マクロ定義 ####################
#define IMG_DIR_ENEMY	R"(.\MY_IMG\Enemy)"			//敵の画像のディレクトリ

#define IMG_NAME_ENEMY	R"(\enemy.png)"				//敵の画像の名前

#define ENEMY_DRAW_X	300			//敵描画X位置
#define ENEMY_DRAW_Y	300			//敵描画Y位置

//############### クラス定義 ####################
class ENEMY :public CHARACTOR		//CHARACTORクラスを継承
{
private:

public:

	ENEMY(const char* ,const char*);	//コンストラクタ
	~ENEMY();							//デストラクタ

	void DrawImage();					//画像描画

};
