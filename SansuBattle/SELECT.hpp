//Select.hpp
//選択画面の処理

#pragma once

//############# ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Button.hpp"

//############# マクロ定義 ##############
#define SELECT_GAMEMODE_DRAW_X		40	//ゲームモードの選択肢の描画開始X位置
#define SELECT_GAMEMODE_DRAW_Y		40	//ゲームモードの選択肢の描画開始Y位置
#define SELECT_LEVEL_DRAW_X		0		//レベルの選択肢の描画開始X位置
#define SELECT_LEVEL_DRAW_Y		250		//レベルの選択肢の描画開始Y位置

#define ARROW_RIGHT_DRAW_X		620		//矢印（右）の描画X位置
#define ARROW_LEFT_DRAW_X		50		//矢印（左）の描画X位置

#define START_DRAW_X			70		//スタートの描画X位置
#define START_DRAW_Y			400		//スタートの描画Y位置

#define SELECT_GAMEMODE_INTERVAL_SIDE		30		//ゲームモード選択肢の間隔(横)
#define SELECT_GAMEMODE_INTERVAL_VERTICAL	100		//ゲームモード選択肢の間隔(縦)
#define SELECT_LEVEL_INTERVAL_SIDE			10		//レベル選択肢の間隔(縦)
#define SELECT_START_INTERVAL_SIDE			80		//スタートの選択肢の間隔（横）

#define RECT_EXPANSION_VALUE	20	//領域の拡大量
#define RECT_TOUKA_VALUE		0.4	//領域の透過率

#define CHOISE_NONE	-1				//選択していない状態

#define PAGE_START	1				//先頭のページ

//############# クラス定義 ##############
class Select : public Scene	//Sceneを継承
{
private:

	vector<Button*> mode;		//ゲームモード
	vector<Image*> mode_img;	//ゲームモード画像
	vector<Button*> level;		//ゲームレベル
	vector<Image*> level_img;	//ゲームレベル画像

public:

	Select();			//コンストラクタ
	~Select();			//デストラクタ

	void SetInit() override;	//初期設定
	void Run() override;		//選択画面の処理

};
