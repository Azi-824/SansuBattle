//Q_BASE.cpp
//問題関係の全ての基になるクラス

//############### ヘッダファイル読み込み #######################
#include "Q_BASE.hpp"

//############### クラス定義 ####################

//コンストラクタ
Q_BASE::Q_BASE()
{
	//メンバー変数初期化
	this->Anser = -1;		//答え初期化
	this->Q_Text = "";		//問題文初期化

	return;
}

//デストラクタ
Q_BASE::~Q_BASE()
{
	return;
}

//問題を描画する
void Q_BASE::DrawQuestion()
{
	DrawFormatString(Q_DRAW_X, Q_DRAW_Y, GetColor(255, 255, 255), "%s", this->Q_Text.c_str());	//問題文を描画

	return;
}

//正解か判定する
/*
引数：int：プレイヤーの答え
戻り値：bool：true 正解：false 不正解
*/
bool Q_BASE::JudgAnser(int plyer_ans)
{
	if (this->Anser == plyer_ans)		//プレイヤーの回答が、答えと一緒だったら
		return true;					//正解
	else								//一緒じゃなかったら
		return false;					//不正解
}
