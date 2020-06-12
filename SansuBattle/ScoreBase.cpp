//ScoreBase.cpp
//スコア関係の基になるクラス

//################# ヘッダファイル読み込み #################
#include "ScoreBase.hpp"

//################# クラス定義 ##################

//コンストラクタ
ScoreBase::ScoreBase()
{
	//メンバー変数初期化
	Score = 0;	//スコア初期化
}

//デストラクタ
ScoreBase::~ScoreBase()
{

}

//現在のスコア表示
void ScoreBase::DrawNowScore()
{
	DrawFormatString(300, 0, COLOR_WHITE, "%d", Score);		//スコア表示
}

//スコア取得
int ScoreBase::GetScore()
{
	return Score;
}