//Q_ADD.hpp
//足し算の問題を管理するクラス

#pragma once

//################# ヘッダファイル読み込み #################
#include "Q_BASE.hpp"

//################# マクロ定義 ####################

//################# クラス定義 ####################
class Q_ADD :public Q_BASE
{
private:


public:

	Q_ADD();					//コンストラクタ
	~Q_ADD();					//デストラクタ

	void CreateQuestion();		//問題作成

};
