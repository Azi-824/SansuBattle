//Score.cpp
//スコア関係の基になるクラス

//################# ヘッダファイル読み込み #################
#include "Score.hpp"

//################# クラス定義 ##################

//コンストラクタ
Score::Score()
{
	score = 0;	//score初期化
	//ゲームモード毎のスコアを設定
	mode_score.push_back(SCORE_SUM_ANSER);			//足し算の時のスコア
	mode_score.push_back(SCORE_DIFFERENCE_ANSER);	//引き算の時のスコア
	mode_score.push_back(SCORE_PRODUCT_ANSER);		//掛け算の時のスコア
	mode_score.push_back(SCORE_DEALER_ANSER);		//割り算の時のスコア
	mode_score.push_back(SCORE_SUM_DIF_ANSER);		//足し算、引き算の時のスコア
	mode_score.push_back(SCORE_PRO_DEA_ANSER);		//掛け算、割り算の時のスコア
	//ゲームレベル毎のボーナスを設定
	level_bonus.push_back(LEVEL_BONUS_EASY);		//簡単のときのボーナス
	level_bonus.push_back(LEVEL_BONUS_NORMAL);		//普通のときのボーナス
	level_bonus.push_back(LEVEL_BONUS_HARD);		//難しいのときのボーナス
}

//デストラクタ
Score::~Score()
{
	//vectorの解放
	vector<int> v;
	mode_score.swap(v);

	//vectorの解放
	vector<int> v2;
	level_bonus.swap(v2);

}

//現在のスコア表示
void Score::DrawNowScore()
{
	int Strlen = strlen(std::to_string(score).c_str());						//文字列の長さを取得
	int Width = GetDrawStringWidthToHandle(std::to_string(score).c_str(), Strlen, NowFontHandle);	//横幅取得

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), GAME_TOP, COLOR_WHITE, NowFontHandle, "%d", score);		//スコア表示
}

//スコア計算
void Score::CalcScore(int gamemode, int gamelevel, int time)
{
	//加算させるスコア量の設定
	int add_value = mode_score.at(gamemode);	//ゲームモード毎のスコアを取得

	const int time_excellent = 5;		//エクセレントの評価基準の時間(5秒以内)
	const int time_great = 15;			//グレートの評価基準の時間(15秒以内)

	if (time <= time_excellent)	//エクセレントの評価基準より短ければ
	{
		add_value *= TIME_BONUS_EXCELLENT;	//エクセレントのボーナスを加えて計算
	}
	else if (time <= time_great)//グレートの評価基準より短ければ
	{
		add_value *= TIME_BONUS_GREAT;		//グレートのボーナスを加えて計算
	}

	add_value *= level_bonus.at(gamelevel);	//レベル毎のボーナスを乗算

	score += add_value;	//スコア加算

}

//スコアリセット
void Score::ResetScore()
{
	score = 0;	//スコアリセット
}

//スコア取得
int Score::GetScore()
{
	return score;
}