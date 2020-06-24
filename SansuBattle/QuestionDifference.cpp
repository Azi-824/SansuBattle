//QuestionDifference.cpp
//引き算の問題を管理するクラス

//############ ヘッダファイル読み込み ###############
#include "QuestionDifference.hpp"

//############ クラス定義 ##############

//コンストラクタ
QuestionDifference::QuestionDifference(){}

//デストラクタ
QuestionDifference::~QuestionDifference(){}

//問題作成
void QuestionDifference::CreateQuestion(int gamelevel)
{
	int q_min = 0, q_max = 0;	//問題の最小値と最大値を入れる変数

	switch (gamelevel)	//ゲームレベル毎に分岐
	{

	case (int)STAGE_LEVEL_EASY:	//簡単の時

		q_min = 1;					//最小値1
		q_max = Q_EASY_VALUE_MAX;	//最大値9

		break;	//簡単の時

	case (int)STAGE_LEVEL_NORMAL:	//普通の時

		q_min = 5;					//最小値5
		q_max = 20;	//最大値20

		break;	//普通の時

	case (int)STAGE_LEVEL_HARD:	//難しいの時

		q_min = 10;					//最小値10
		q_max = 30;	//最大値30

		break;	//難しいの時


	default:
		break;
	}

	int num1 = 0, num2 = 0;		//問題を入れる変数

	num1 = GetRand(q_max - q_min) + q_min;			//問題を生成
	num2 = GetRand(q_max - q_min) + q_min;			//問題を生成

	if (num1 < num2)		//num1の値がnum2より小さいとき
	{
		//値の交換
		int w = num2;
		num2 = num1;
		num1 = w;	
	}
	Anser = num1 - num2;	//問題の計算結果を答えに格納
	Q_Text = (std::to_string(num1) + "－" + (std::to_string(num2) + "＝？"));		//問題文を設定

	IsCreate = true;	//問題を作成した

}