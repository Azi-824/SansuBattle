//ScoreBase.cpp
//スコア関係の基になるクラス

//################# ヘッダファイル読み込み #################
#include "ScoreBase.hpp"

//################# クラス定義 ##################

//インスタンス生成
int ScoreBase::Score = 0;	//スコア

//コンストラクタ
ScoreBase::ScoreBase()
{

}

//デストラクタ
ScoreBase::~ScoreBase()
{

}

//現在のスコア表示
void ScoreBase::DrawNowScore()
{
	int Strlen = strlen(std::to_string(Score).c_str());						//文字列の長さを取得
	int Width = GetDrawStringWidth(std::to_string(Score).c_str(), Strlen);	//横幅取得

	DrawFormatString((GAME_WIDTH / 2) - (Width / 2), GAME_TOP, COLOR_WHITE, "%d", Score);		//スコア表示
}

//スコア取得
int ScoreBase::GetScore()
{
	return Score;
}