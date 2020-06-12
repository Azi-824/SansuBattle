//ScoreBase.hpp
//スコア関係の基になるクラス

#pragma once

//################### ヘッダファイル読み込み ###################
#include "Global.hpp"

//################### マクロ定義 ########################

//################### クラス定義 ########################
class ScoreBase
{
protected:

	int Score;			//得点

public:

	ScoreBase();							//コンストラクタ
	~ScoreBase();							//デストラクタ

	virtual void CalcScore(int) = 0;		//スコア計算処理
	void DrawNowScore();					//現在のスコア表示

	int GetScore();							//スコア取得

};
