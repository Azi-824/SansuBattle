//ScoreProduct.cpp
//掛け算のスコアを管理するクラス

//################ ヘッダファイル読み込み ##################
#include "ScoreProduct.hpp"

//################ クラス定義 ##################

//コンストラクタ
ScoreProduct::ScoreProduct() {}

//デストラクタ
ScoreProduct::~ScoreProduct() {}

//スコア計算処理
//引数：int：ゲームレベル
//引数：int：回答までにかかった時間
void ScoreProduct::CalcScore(int gamelevel, int time)
{
	const int time_excellent = 5;		//エクセレントの評価基準の時間(5秒以内)
	const int time_great = 15;			//グレートの評価基準の時間(15秒以内)
	int addscore_value = 0;				//加算されるスコア

	if (time <= time_excellent)	//エクセレントの評価基準より短ければ
	{
		addscore_value = SCORE_PRODUCT_ANSER * TIME_BONUS_EXCELLENT;	//エクセレントのボーナスを加えて計算
	}
	else if (time <= time_great)//グレートの評価基準より短ければ
	{
		addscore_value = SCORE_PRODUCT_ANSER * TIME_BONUS_GREAT;		//グレートのボーナスを加えて計算
	}
	else						//それより遅ければ
	{
		addscore_value = SCORE_PRODUCT_ANSER;	//ボーナスなしで計算
	}

	switch (gamelevel)	//ゲームレベル毎
	{

	case (int)STAGE_LEVEL_EASY:		//簡単のとき

		addscore_value *= LEVEL_BONUS_EASY;	//簡単のレベルボーナスを乗算

		break;	//簡単の時ここまで

	case (int)STAGE_LEVEL_NORMAL:		//普通のとき

		addscore_value *= LEVEL_BONUS_NORMAL;	//普通のレベルボーナスを乗算

		break;	//普通の時ここまで

	case (int)STAGE_LEVEL_HARD:		//難しいのとき

		addscore_value *= LEVEL_BONUS_HARD;	//難しいのレベルボーナスを乗算

		break;	//難しいの時ここまで

	default:
		break;
	}

	score += addscore_value;	//スコア加算

}