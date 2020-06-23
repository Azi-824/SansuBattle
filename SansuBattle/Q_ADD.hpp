//Q_Add.hpp
//足し算の問題を管理するクラス

#pragma once

//################# ヘッダファイル読み込み #################
#include "Question.hpp"

//################# マクロ定義 ####################

//################# クラス定義 ####################
class Q_Add :public Question
{
private:


public:

	Q_Add();					//コンストラクタ
	~Q_Add();					//デストラクタ

	void CreateQuestion(int) override;		//問題作成

};
