//ScoreAdd.hpp
//足し算のスコアを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ####################
#include "Score.hpp"

//################### マクロ定義 #####################
#define SCORE_ADD_ANSER	100		//足し算の回答をした時のスコア

//################### クラス定義 #####################
class ScoreAdd :public Score	//ScoreBaseクラスを継承
{
public:

	ScoreAdd();			//コンストラクタ
	~ScoreAdd();		//デストラクタ

	void CalcScore(int,int) override;		//スコア計算処理

};
