//QuestionAdd.hpp
//足し算の問題を管理するクラス

#pragma once

//################# ヘッダファイル読み込み #################
#include "Question.hpp"

//################# マクロ定義 ####################

//################# クラス定義 ####################
class QuestionAdd :public Question
{
private:


public:

	QuestionAdd();					//コンストラクタ
	~QuestionAdd();					//デストラクタ

	void CreateQuestion(int) override;		//問題作成

};
