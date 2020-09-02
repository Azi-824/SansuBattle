//Button.hpp
//ボタンのクラス

#pragma once

//################# ヘッダファイル読み込み ####################
#include "Global.hpp"
#include "Image.hpp"
#include "Music.hpp"

//################# マクロ定義 ################
#define BT_IMG_DIR				R"(.\Image\Button)"	//ボタンの画像のディレクトリ

#define BT_START_IMG_NAME		R"(\start.png)"				//ボタンの画像(start)
#define BT_END_IMG_NAME			R"(\end.png)"				//ボタンの画像(end)

#define BT_SUM_IMG_NAME			R"(\mode_sum.png)"			//ボタンの画像(+)
#define BT_DIF_IMG_NAME			R"(\mode_difference.png)"	//ボタンの画像(-)
#define BT_PRO_IMG_NAME			R"(\mode_product.png)"		//ボタンの画像(*)
#define BT_DEA_IMG_NAME			R"(\mode_dealer.png)"		//ボタンの画像(/)
#define BT_SUM_DIF_IMG_NAME		R"(\mode_sum_diff.png)"		//ボタンの画像(+-)
#define BT_PRO_DEA_IMG_NAME		R"(\mode_pro_dea.png)"		//ボタンの画像(*/)
#define BT_SUM_PRO_IMG_NAME		R"(\mode_sum_pro.png)"		//ボタンの画像(+*)
#define BT_SUM_DEA_IMG_NAME		R"(\mode_sum_dea.png)"		//ボタンの画像(+/)
#define BT_DIF_PRO_IMG_NAME		R"(\mode_dif_pro.png)"		//ボタンの画像(-*)
#define BT_SUM_DIF_PRO_IMG_NAME	R"(\mode_sum_dif_pro.png)"	//ボタンの画像（+-*）
#define BT_SUM_DIF_DEA_IMG_NAME	R"(\mode_sum_dif_dea.png)"	//ボタンの画像（+-/）
#define BT_ALL_IMG_NAME			R"(\mode_all.png)"			//ボタンの画像（四則演算）

#define BT_EASY_IMG_NAME		R"(\level_easy.png)"		//ボタンの画像(簡単)
#define BT_NORMAL_IMG_NAME		R"(\level_normal.png)"		//ボタンの画像(普通)
#define BT_HARD_IMG_NAME		R"(\level_hard.png)"		//ボタンの画像(難しい)


#define IMG_NAME_ARROW_RIGHT	R"(\Arrow_Right.png)"		//矢印（右）の画像
#define IMG_NAME_ARROW_LEFT		R"(\Arrow_Left.png)"		//矢印（左）の画像

#define BT_START_X	150		//スタートボタンX位置
#define BT_START_Y	500		//スタートボタンY位置
#define BT_END_X	500		//スタートボタンX位置
#define BT_END_Y	500		//スタートボタンY位置

#define BT_MODE_DRAW_X		40	//ゲームモードの選択肢の描画開始X位置
#define BT_MODE_DRAW_Y		40	//ゲームモードの選択肢の描画開始Y位置
#define BT_LEVEL_DRAW_X		0	//レベルの選択肢の描画開始X位置
#define BT_LEVEL_DRAW_Y		250	//レベルの選択肢の描画開始Y位置

#define BT_MODE_INTERVAL_SIDE		30		//ゲームモード選択肢の間隔(横)
#define BT_MODE_INTERVAL_VERTICAL	100		//ゲームモード選択肢の間隔(縦)
#define BT_LEVEL_INTERVAL_SIDE		10		//レベル選択肢の間隔(縦)
#define BT_LEVEL_INTERVAL_VERTICAL	0		//レベル選択肢の間隔(横)
#define BT_START_INTERVAL_SIDE		80		//スタートの選択肢の間隔（横）

#define RECT_EXPANSION_VALUE	20	//領域の拡大量
#define RECT_TOUKA_VALUE		0.8	//領域の透過率

#define CHOISE_NONE	-1				//選択していない状態

#define PAGE_START	1				//先頭のページ


//################# 列挙型 #################
enum BT_TYPE
{
	BT_START,		//スタート
	BT_END			//エンド
};

//################# クラス定義 ################
class Button
{
private:

	Image* img;	//画像
	RECT rect;	//領域
	static Music* se;	//効果音

	int Element;			//要素番号
	static int ElementCnt;	//要素数

public:

	Button(Image*);	//コンストラクタ
	~Button();		//デストラクタ

	void SetInit(int,int);	//初期設定

	void UpDate();	//更新処理

	bool OnClick();	//クリックされたか
	void Draw();	//描画
	void Draw(int, int);//描画（位置指定）
	int GetElement();	//要素番号取得
	int GetWidth();		//横幅取得
	int GetHeight();	//高さ取得
	void SetRect(int,int);//領域を設定
	
	template <typename F>
	void Event(F func)	//クリックされた時のイベント
	{
		func();
	}

};
