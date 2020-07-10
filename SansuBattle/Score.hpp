//Score.hpp
//スコア関係の基になるクラス

#pragma once

//################### ヘッダファイル読み込み ###################
#include "Global.hpp"
#include <string>
#include <vector>

//################### マクロ定義 ########################
#define TIME_BONUS_EXCELLENT	2		//回答時間がエクセレントの時のボーナス倍率
#define TIME_BONUS_GREAT		1.5		//回答時間がグレートの時のボーナス倍率
#define LEVEL_BONUS_EASY		1		//簡単レベルのボーナス倍率
#define LEVEL_BONUS_NORMAL		2		//普通レベルのボーナス倍率
#define LEVEL_BONUS_HARD		3		//難しいレベルのボーナス倍率

#define SCORE_SUM_ANSER	100				//足し算の回答をした時のスコア
#define SCORE_DIFFERENCE_ANSER	150		//引き算の回答をした時のスコア
#define SCORE_PRODUCT_ANSER	200			//掛け算の回答をした時のスコア
#define SCORE_DEALER_ANSER	250			//割り算の回答をした時のスコア
#define SCORE_SUM_DIF_ANSER	300			//足し算、引き算の回答をした時のスコア
#define SCORE_PRO_DEA_ANSER	350			//掛け算、割り算の回答をした時のスコア
#define SCORE_SUM_PRO_ANSER	400			//+*の回答をした時のスコア

using std::vector;

//################### クラス定義 ########################
class Score
{
private:

	int score;			//得点

	vector<int> mode_score;	//ゲームモード毎のスコア
	vector<int> level_bonus;//ゲームレベル毎のボーナス

public:

	Score();							//コンストラクタ
	~Score();							//デストラクタ

	void CalcScore(int,int,int);		//スコア計算処理
	void DrawNowScore();				//現在のスコア表示
	void ResetScore();					//スコアリセット

	int GetScore();						//スコア取得

};
