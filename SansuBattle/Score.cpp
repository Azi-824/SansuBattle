//Score.cpp
//スコア関係の基になるクラス

//################# ヘッダファイル読み込み #################
#include "Score.hpp"

//################# クラス定義 ##################

//コンストラクタ
Score::Score()
{
	score = 0;	//score初期化
}

//デストラクタ
Score::~Score()
{

}

//現在のスコア表示
void Score::DrawNowScore()
{
	int Strlen = strlen(std::to_string(score).c_str());						//文字列の長さを取得
	int Width = GetDrawStringWidthToHandle(std::to_string(score).c_str(), Strlen, NowFontHandle);	//横幅取得

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), GAME_TOP, COLOR_WHITE, NowFontHandle, "%d", score);		//スコア表示
}

//スコア計算
void Score::CalcScore(int gamemode, int gamelevel, int time)
{

	int add_value = 0;	//加算されるスコア

	//*************** 加算させるスコア量の設定 ***********************
	switch (gamemode)	//ゲームモード毎
	{

	case Q_MODE_SUM:	//足し算の時

		add_value = SCORE_ADD_ANSER;	//足し算のスコアを、加算される量に設定

		break;			//足し算の時ここまで

	case Q_MODE_DIFFERENCE:	//引き算の時

		add_value = SCORE_DIFFERENCE_ANSER;	//引き算のスコアを、加算される量に設定

		break;			//引き算の時ここまで

	case Q_MODE_PRODUCT:	//掛け算の時

		add_value = SCORE_PRODUCT_ANSER;	//掛け算のスコアを、加算される量に設定

		break;			//掛け算の時ここまで

	default:
		break;
	}

	const int time_excellent = 5;		//エクセレントの評価基準の時間(5秒以内)
	const int time_great = 15;			//グレートの評価基準の時間(15秒以内)

	if (time <= time_excellent)	//エクセレントの評価基準より短ければ
	{
		add_value *= TIME_BONUS_EXCELLENT;	//エクセレントのボーナスを加えて計算
	}
	else if (time <= time_great)//グレートの評価基準より短ければ
	{
		add_value *= TIME_BONUS_GREAT;		//グレートのボーナスを加えて計算
	}

	switch (gamelevel)	//ゲームレベル毎
	{

	case (int)STAGE_LEVEL_EASY:		//簡単のとき

		add_value *= LEVEL_BONUS_EASY;	//簡単のレベルボーナスを乗算

		break;	//簡単の時ここまで

	case (int)STAGE_LEVEL_NORMAL:		//普通のとき

		add_value *= LEVEL_BONUS_NORMAL;	//普通のレベルボーナスを乗算

		break;	//普通の時ここまで

	case (int)STAGE_LEVEL_HARD:		//難しいのとき

		add_value *= LEVEL_BONUS_HARD;	//難しいのレベルボーナスを乗算

		break;	//難しいの時ここまで

	default:
		break;
	}

	score += add_value;	//スコア加算

}

//スコアリセット
void Score::ResetScore()
{
	score = 0;	//スコアリセット
}

//スコア取得
int Score::GetScore()
{
	return score;
}