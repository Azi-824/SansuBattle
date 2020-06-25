//ScoreProduct.hpp
//掛け算のスコアを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ###############
#include "Score.hpp"

//################### マクロ定義 #####################
#define SCORE_PRODUCT_ANSER	150		//掛け算の回答をした時のスコア

//############# クラス定義 ################
class ScoreProduct : public Score	//Scoreを継承
{
public:

	ScoreProduct();			//コンストラクタ
	~ScoreProduct();		//デストラクタ

	void CalcScore(int, int) override;		//スコア計算処理

};
