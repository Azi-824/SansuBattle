//Q_BASE.hpp
//問題関係の全ての基になるクラス

#pragma once

//################# ヘッダファイル読み込み ###############
#include "DxLib.h"
#include <string>

//################# マクロ定義 #################
#define Q_DRAW_X 30		//問題の描画X位置
#define Q_DRAW_Y 30		//問題の描画Y位置
//################# クラス定義 #################
class Q_BASE
{
protected:

	std::string Q_Text;			//問題文
	int Anser;					//答え

public:

	Q_BASE();							//コンストラクタ
	~Q_BASE();							//デストラクタ

	void DrawQuestion();				//問題を描画する

	bool JudgAnser(int);				//正解か判定する

};
