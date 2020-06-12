//ScoreAdd.hpp
//足し算のスコアを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ####################
#include "ScoreBase.hpp"

//################### マクロ定義 #####################

//################### クラス定義 #####################
class ScoreAdd :public ScoreBase	//ScoreBaseクラスを継承
{
public:

	ScoreAdd();			//コンストラクタ
	~ScoreAdd();		//デストラクタ

	virtual void CalcScore(int) override;		//スコア計算処理

};
