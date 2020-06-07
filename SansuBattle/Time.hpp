//Time.hpp
//時間を管理するクラス

#pragma once

//################## ヘッダファイル読み込み ################
#include "Global.hpp"

//################## マクロ定義 ###################
#define GAME_LIMITTIME_DRAW_X	740		//ゲームの制限時間描画X位置
#define GAME_LIMITTIME_DRAW_Y	0		//ゲームの制限時間描画Y位置

#define GAME_LIMIT_TIME		30			//ゲームの制限時間

//################## クラス定義 ###################
class Time
{
private:

	int StartTime;						//計測開始時間
	int ElapsedTime;					//経過時間
	int NowLimitTime;					//残りの制限時間

public:

	Time();								//コンストラクタ
	~Time();							//デストラクタ

	void SetTime();						//計測開始
	void UpdateElpasedTime();			//経過時間更新
	void UpdateLimitTime(int);			//制限時間更新
	void DrawElapsedTime(int, int);		//経過時間描画
	void DrawLimitTime(int, int,int);	//制限時間描画

};
