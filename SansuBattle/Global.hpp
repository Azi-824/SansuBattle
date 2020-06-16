//Global.hpp
//複数のソースで使用したい定義などをまとめたヘッダーファイル

#pragma once

//################## ヘッダファイル読み込み ##################
#include "DxLib.h"

//################## マクロ定義 ######################
#define GAME_LEFT	  0		//画面の横の始点
#define GAME_TOP	  0		//画面の縦の始点
#define GAME_WIDTH	880		//画面の横の大きさ
#define GAME_HEIGHT	640		//画面の縦の大きさ
#define GAME_FPS_SPEED					   60

//色関係
#define COLOR_RED	GetColor(255,0,0)		//赤色
#define COLOR_GREEN	GetColor(0,255,0)		//緑色
#define COLOR_BLUE	GetColor(0,0,255)		//青色
#define COLOR_WHITE GetColor(255,255,255)	//白色
#define COLOR_BLACK GetColor(0,0,0)			//黒色

//****************** その他 ***********************
#define INIT_VALUE		0	//初期値
#define FADE_MAX_CNT	60	//フェード処理のカウント最大値
#define TOUKA_MAX_VALUE	255	//透過の最大値

//##################### マクロ定義 #####################
enum Q_MODE_KIND
{
	Q_MODE_SUM,					//モード、和（足し算）
	Q_MODE_DIFFERENCE,			//モード、差（引き算）
	Q_MODE_PRODUCT,				//モード、積（掛け算）
	Q_MODE_DEALER,				//モード、商（割り算）
	Q_MODE_SUM_DIFFERENCE,		//モード、和差（足し算、引き算）
	Q_MODE_PRODUCT_DEALER		//モード、積商（掛け算、割り算）
};	//問題の種類

enum STAGE_LEVEL
{
	STAGE_LEVEL_EASY,		//簡単
	STAGE_LEVEL_NORMAL,		//普通
	STAGE_LEVEL_HARD		//難しい
};	//ステージのレベル

extern int NowFontHandle;	//現在のフォントハンドル
