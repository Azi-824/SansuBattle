//Select.hpp
//選択肢を管理するクラス

#pragma once

//#################### ヘッダファイル読み込み #####################
#include "Global.hpp"
#include "Image.hpp"
#include "KeyDown.hpp"
#include "Music.hpp"
#include <vector>

//##################### マクロ定義 ######################
#define SELECT_IMG_DIR			R"(.\MY_IMG\Select)"		//選択肢の画像ディレクトリ

#define IMG_NAME_SELECT_SUM			R"(\select_sum.png)"			//ゲームモード選択肢（足し算）の画像
#define IMG_NAME_SELECT_DIFFERENCE	R"(\select_difference.png)"		//ゲームモード選択肢（引き算）の画像
#define IMG_NAME_SELECT_PRODUCT		R"(\select_product.png)"		//ゲームモード選択肢（掛け算）の画像
#define IMG_NAME_SELECT_DEALER		R"(\select_dealer.png)"			//ゲームモード選択肢（割り算）の画像
#define IMG_NAME_SELECT_SUM_DIFF	R"(\select_sum_diff.png)"		//ゲームモード選択肢（足し算、引き算）の画像
#define IMG_NAME_SELECT_PRO_DEA		R"(\select_pro_dea.png)"		//ゲームモード選択肢（掛け算、割り算）の画像
#define IMG_NAME_SELECT_SUM_PRO		R"(\select_sum_pro.png)"		//ゲームモード選択肢（足し算、掛け算）の画像
#define IMG_NAME_SELECT_SUM_DEA		R"(\select_sum_dea.png)"		//ゲームモード選択肢（足し算、割り算）の画像
#define IMG_NAME_SELECT_DIF_PRO		R"(\select_dif_pro.png)"		//ゲームモード選択肢（引き算、掛け算）の画像
#define IMG_NAME_SELECT_SUM_DIF_PRO	R"(\select_sum_dif_pro.png)"	//ゲームモード選択肢（+-*）の画像
#define IMG_NAME_SELECT_SUM_DIF_DEA	R"(\select_sum_dif_dea.png)"	//ゲームモード選択肢（+-/）の画像
#define IMG_NAME_SELECT_ALL			R"(\select_all.png)"			//ゲームモード選択肢（四則演算）の画像

#define IMG_NAME_SELECTLEVEL_EASY	R"(\select_level_easy.png)"		//レベル選択肢（簡単）の画像
#define IMG_NAME_SELECTLEVEL_NORMAL	R"(\select_level_normal.png)"	//レベル選択肢（普通）の画像
#define IMG_NAME_SELECTLEVEL_HARD	R"(\select_level_hard.png)"		//レベル選択肢（難しい）の画像

#define IMG_NAME_ARROW_RIGHT		R"(\Arrow_Right.png)"			//矢印（右）の画像
#define IMG_NAME_ARROW_LEFT			R"(\Arrow_Left.png)"			//矢印（左）の画像

#define SELECT_GAMEMODE_DRAW_X		40	//ゲームモードの選択肢の描画開始X位置
#define SELECT_GAMEMODE_DRAW_Y		40	//ゲームモードの選択肢の描画開始Y位置
#define SELECT_LEVEL_DRAW_X		0		//レベルの選択肢の描画開始X位置
#define SELECT_LEVEL_DRAW_Y		250		//レベルの選択肢の描画開始Y位置

#define ARROW_RIGHT_DRAW_X		640		//矢印（右）の描画X位置
#define ARROW_LEFT_DRAW_X		50		//矢印（左）の描画X位置

#define SELECT_GAMEMODE_INTERVAL_SIDE		30		//ゲームモード選択肢の間隔(横)
#define SELECT_GAMEMODE_INTERVAL_VERTICAL	100		//ゲームモード選択肢の間隔(縦)
#define SELECT_LEVEL_INTERVAL_SIDE			10		//レベル選択肢の間隔(縦)

#define RECT_EXPANSION_VALUE	20	//領域の拡大量
#define RECT_TOUKA_VALUE		0.4	//領域の透過率

#define CHOISE_NONE	-1				//選択していない状態

#define PAGE_START	1				//先頭のページ

//##################### 列挙型 #######################

using std::vector;

//##################### クラス定義 ######################
class Select
{

private:

	vector<Image*> SelectImage;					//選択肢の画像
	RECT rect;									//選択肢の領域
	static vector<Music*> Key_se;				//キーボード操作の時の効果音
	static vector<Image*> Arrow;				//矢印の画像

	vector<int> SelectCode;						//選択肢のコード番号
	vector<int>::iterator NowSelectCode;		//現在選んでいるコード番号

	int Choise_SelectCode;						//選んだ選択肢のコード番号

	bool IsChoise;								//選択したか
	bool IsBack;								//戻るか

	int PageMax;								//ページ数
	int NowPage;								//現在のページ
	bool IsNextPage;							//次のページへ行けるか

	int DrawX;									//描画開始X位置
	int DrawY;									//描画開始Y位置
	int RowNum;									//描画範囲の中で描画できる列の数
	int LineNum;								//描画範囲の中で描画できる行の数
	int Interval_Side;							//選択肢の間隔(横)
	int Interval_Vertical;						//選択肢の間隔(縦)

	bool CheckIsNextPage();						//次のページへ行けるか確認
	bool CheckIsPrevPage();						//前のページへ行けるか確認
	void NextPage();							//次のページへ
	void PrevPage();							//前のページへ

	void Next();								//次の選択肢へ
	void Next(int);								//指定された数分、次の選択肢へ
	void Prev();								//前の選択肢へ
	void Prev(int);								//指定された数分、前の選択肢へ

public:

	Select(vector<Image*>);						//コンストラクタ
	~Select();									//デストラクタ

	bool GetIsChoise();							//選択したか取得
	bool GetIsBack();							//戻るか取得
	int GetChoiseSelectCode();					//選んだ選択肢のコード番号

	void SetInit(int,int,int,int interval_vertical = 0);	//初期設定
	void Init();								//初期化

	void Add(Image*);							//選択肢を追加

	void Draw();								//選択肢を描画

	void Operation(KeyDown*);					//キー操作

};
