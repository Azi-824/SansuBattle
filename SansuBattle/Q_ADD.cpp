//Q_Base.cpp
//足し算の問題を管理するクラス

//################# ヘッダファイル読み込み ##################
#include "Q_Add.hpp"

//################# クラス定義 ####################

//コンストラクタ
Q_Add::Q_Add()
{
	return;
}

//デストラクタ
Q_Add::~Q_Add()
{
	return;
}

//問題を作成
void Q_Add::CreateQuestion()
{
	int num1 = 0, num2 = 0;		//問題を入れる変数

	num1 = GetRand(Q_EASY_VALUE_MAX);			//問題を生成
	num2 = GetRand(Q_EASY_VALUE_MAX);			//問題を生成

	this->Anser = num1 + num2;	//問題の計算結果を答えに格納
	this->Q_Text = (std::to_string(num1) + "＋" + (std::to_string(num2) + "＝？"));		//問題文を設定

	IsCreate = true;	//問題を作成した

	return;

}
