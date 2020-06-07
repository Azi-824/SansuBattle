//Time.hpp
//時間を管理するクラス

#pragma once

//################## ヘッダファイル読み込み ################
#include "Global.hpp"

//################## マクロ定義 ###################
#define GAME_LIMITTIME_DRAW_X	740		//ゲームの制限時間描画X位置
#define GAME_LIMITTIME_DRAW_Y	0		//ゲームの制限時間描画Y位置

//################## クラス定義 ###################
class Time
{
private:

	int StartTime;					//計測開始時間
	int ElapsedTime;				//経過時間

public:

	Time();							//コンストラクタ
	~Time();						//デストラクタ

	void SetTime();					//計測開始
	void UpdateElpasedTime();		//経過時間更新
	void DrawElapsedTime(int, int);	//時間描画

};
