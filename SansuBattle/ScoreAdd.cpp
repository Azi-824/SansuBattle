//ScoreAdd.cpp
//足し算のスコアを管理するクラス

//################ ヘッダファイル読み込み ##################
#include "ScoreAdd.hpp"

//################ クラス定義 ##################

//コンストラクタ
ScoreAdd::ScoreAdd()
{

}

//デストラクタ
ScoreAdd::~ScoreAdd()
{

}

//スコア計算処理
//引数：int：回答までにかかった時間
void ScoreAdd::CalcScore(int time)
{
	const int time_excellent = 5;		//エクセレントの評価基準の時間(5秒以内)
	const int time_great = 15;			//グレートの評価基準の時間(15秒以内)

	if (time <= time_excellent)	//エクセレントの評価基準より短ければ
	{
		Score = Score + (SCOREADD_SCORE_ANSER * TIME_BONUS_EXCELLENT);	//エクセレントのボーナスを加えて計算
	}
	else if (time <= time_great)//グレートの評価基準より短ければ
	{
		Score = Score + (SCOREADD_SCORE_ANSER * TIME_BONUS_GREAT);		//グレートのボーナスを加えて計算
	}
	else						//それより遅ければ
	{
		Score = Score + SCOREADD_SCORE_ANSER;	//ボーナスなしで計算
	}

}