//QuestionProduct.hpp
//掛け算の問題を管理するクラス

#pragma once

//############## ヘッダファイル読み込み ###############
#include "Question.hpp"

//############## クラス定義 #############
class QuestionProduct :public Question	//Questionクラス修正
{
public:

	QuestionProduct();		//コンストラクタ
	~QuestionProduct();		//デストラクタ

	void CreateQuestion(int) override;	//問題作成

};

