//ScoreBase.hpp
//スコア関係の基になるクラス

#pragma once

//################### ヘッダファイル読み込み ###################
#include "Global.hpp"
#include <string>

//################### マクロ定義 ########################
#define TIME_BONUS_EXCELLENT	2		//回答時間がエクセレントの時のボーナス倍率
#define TIME_BONUS_GREAT		1.5		//回答時間がグレートの時のボーナス倍率

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
	void ResetScore();						//スコアリセット

	int GetScore();							//スコア取得

};
