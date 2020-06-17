//Select.hpp
//選択肢を管理するクラス

#pragma once

//#################### ヘッダファイル読み込み #####################
#include "Global.hpp"
#include "Image.hpp"
#include "KeyDown.hpp"
#include <vector>

//##################### マクロ定義 ######################
#define SELECT_IMG_DIR			R"(.\MY_IMG\Select)"		//選択肢の画像ディレクトリ

#define IMG_NAME_SELECT_SUM			R"(\select_sum.png)"			//ゲームモード選択肢（足し算）の画像
#define IMG_NAME_SELECT_DIFFERENCE	R"(\select_difference.png)"		//ゲームモード選択肢（引き算）の画像
#define IMG_NAME_SELECT_PRODUCT		R"(\select_product.png)"		//ゲームモード選択肢（掛け算）の画像
#define IMG_NAME_SELECT_DEALER		R"(\select_dealer.png)"			//ゲームモード選択肢（割り算）の画像
#define IMG_NAME_SELECT_SUM_DIFF	R"(\select_sum_diff.png)"		//ゲームモード選択肢（足し算、引き算）の画像
#define IMG_NAME_SELECT_PRO_DEA		R"(\select_pro_dea.png)"		//ゲームモード選択肢（掛け算、割り算）の画像

#define IMG_NAME_SELECTLEVEL_EASY	R"(\select_level_easy.png)"		//レベル選択肢（簡単）の画像
#define IMG_NAME_SELECTLEVEL_NORMAL	R"(\select_level_normal.png)"	//レベル選択肢（普通）の画像
#define IMG_NAME_SELECTLEVEL_HARD	R"(\select_level_hard.png)"		//レベル選択肢（難しい）の画像

#define SELECT_GAMEMODE_DRAW_X		20	//ゲームモードの選択肢の描画開始X位置
#define SELECT_GAMEMODE_DRAW_Y		20	//ゲームモードの選択肢の描画開始Y位置
#define SELECT_LEVEL_DRAW_X		0		//レベルの選択肢の描画開始X位置
#define SELECT_LEVEL_DRAW_Y		250		//レベルの選択肢の描画開始Y位置

#define SELECT_INTERVAL		10		//選択肢の間隔

#define CHOISE_NONE	-1				//選択していない状態

//##################### 列挙型 #######################

//##################### クラス定義 ######################
class Select
{

private:

	Image* SelectImage;							//選択肢の画像

	std::vector<int> SelectCode;				//選択肢のコード番号
	std::vector<int>::iterator NowSelectCode;	//現在選んでいるコード番号

	int Choise_SelectCode;						//選んだ選択肢のコード番号

	bool IsCreateSelect;						//選択肢を作れたか
	bool IsChoise;								//選択したか

	int DrawX;									//描画開始X位置
	int DrawY;									//描画開始Y位置
	int DrawWidth_Range;						//描画幅の範囲
	int RowNum;									//描画範囲の中で描画できる列の数

public:

	Select(const char *,const char *,int);		//コンストラクタ
	~Select();									//デストラクタ

	bool GetIsCreateSelect();					//選択肢を作れたか取得
	bool GetIsChoise();							//選択したか取得
	bool GetChoiseSelectCode();					//選んだ選択肢のコード番号

	void SetInit(int,int,int);					//初期設定
	void Init();								//初期化

	bool Add(const char*, const char*,int);		//選択肢を追加

	void Draw();								//選択肢を描画

	void Operation(KeyDown*);					//キー操作
	void Next();								//次の選択肢へ
	void Next(int);								//指定された数分、次の選択肢へ
	void Prev();								//前の選択肢へ
	void Prev(int);								//指定された数分、前の選択肢へ

};
