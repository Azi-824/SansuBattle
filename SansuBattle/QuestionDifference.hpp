//QuestionDifference.hpp
//引き算の問題を管理するクラス

#pragma once

//############## ヘッダファイル読み込み ################
#include "Question.hpp"

//############## クラス定義 ##################
class QuestionDifference :public Question	//Questionクラス修正
{
public:

	QuestionDifference();		//コンストラクタ
	~QuestionDifference();		//デストラクタ

	void CreateQuestion(int) override;	//問題作成

};
