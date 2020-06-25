//ScoreDifference.hpp
//引き算のスコアを管理するオブジェクト

#pragma once

//############## ヘッダファイル読み込み ################
#include "Score.hpp"

//################### マクロ定義 #####################
#define SCORE_DIFFERENCE_ANSER	100		//引き算の回答をした時のスコア

//############# クラス定義 ################
class ScoreDifference : public Score	//Scoreを継承
{
public:

	ScoreDifference();			//コンストラクタ
	~ScoreDifference();			//デストラクタ

	void CalcScore(int, int) override;		//スコア計算処理

};