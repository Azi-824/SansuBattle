//Score.cpp
//スコア関係の基になるクラス

//################# ヘッダファイル読み込み #################
#include "Score.hpp"

//################# クラス定義 ##################

//コンストラクタ
Score::Score()
{

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