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
	int time_excellent = 5;		//エクセレントの評価基準の時間
	int time_great = 15;		//グレートの評価基準の時間

	if (time <= time_excellent)	//エクセレントの評価基準より短ければ
	{
		Score = Score + (100 * 2);
	}
	else if (time <= time_great)//グレートの評価基準より短ければ
	{
		Score = Score + (100 * 1.5);
	}
	else						//それより遅ければ
	{
		Score = Score + 100;
	}

}