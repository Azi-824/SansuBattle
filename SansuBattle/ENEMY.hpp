//ENEMY.hpp
//敵を管理するクラス

#pragma once

//############### ヘッダファイル読み込み ####################
#include "CHARACTOR.hpp"

//############### マクロ定義 ####################
#define IMG_DIR_ENEMY	R"(.\MY_IMG\Enemy)"			//敵の画像のディレクトリ

#define IMG_NAME_ENEMY_FIRST	R"(\enemy.png)"		//敵(1体目)の画像の名前
#define IMG_NAME_ENEMY_SECOND	R"(\enemy2.png)"	//敵(2体目)の画像の名前
#define IMG_NAME_ENEMY_THIRD	R"(\enemy3.png)"	//敵(3体目)の画像の名前
#define IMG_NAME_ENEMY_HP		R"(\enemy_hp.png)"	//敵のHPの画像の名前

#define ENEMY_HP_DRAW_X		20	//HPの描画開始X位置
#define ENEMY_HP_DRAW_Y		150	//HPの描画開始Y位置

#define ENEMY_MAX		3			//敵の最大数

//############### クラス定義 ####################
class ENEMY :public CHARACTOR		//CHARACTORクラスを継承
{
private:

	static int NowEnemyNum;						//現在何体目の敵か

public:

	ENEMY(const char* ,const char*);	//コンストラクタ
	~ENEMY();							//デストラクタ

	void Init();						//初期化

	static void NextEnemy();			//次の敵へ
	static int GetNowEnemyNum();		//現在何体目の敵か取得

	void DrawHp() override;				//HP描画

};
