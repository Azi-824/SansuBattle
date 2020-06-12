//ScoreAdd.cpp
//足し算のスコアを管理するクラス

//################ ヘッダファイル読み込み ##################
#include "ScoreAdd.hpp"

//################ クラス定義 ##################

//コンストラクタ
ScoreAdd::ScoreAdd()
{

}

//デストラクタ
ScoreAdd::~ScoreAdd()
{

}

//スコア計算処理
//引数：int：回答までにかかった時間
void ScoreAdd::CalcScore(int time)
{
	Score += 100;	//とりあえず100追加する
}