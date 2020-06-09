//Q_BASE.hpp
//問題関係の全ての基になるクラス

#pragma once

//################# ヘッダファイル読み込み ###############
#include "Global.hpp"
#include <string>
#include "KEYDOWN.hpp"

//################# マクロ定義 #################
#define Q_DRAW_X 100		//問題の描画X位置
#define Q_DRAW_Y 100		//問題の描画Y位置

#define Q_EASY_VALUE_MAX 9	//簡単モードの問題の最大値

//################# 列挙型 ###################
enum INPUT_NUM
{
	INPUT_NUM_0,		//入力値0
	INPUT_NUM_1,		//入力値1
	INPUT_NUM_2,		//入力値2
	INPUT_NUM_3,		//入力値3
	INPUT_NUM_4,		//入力値4
	INPUT_NUM_5,		//入力値5
	INPUT_NUM_6,		//入力値6
	INPUT_NUM_7,		//入力値7
	INPUT_NUM_8,		//入力値8
	INPUT_NUM_9,		//入力値9
	INPUT_ENTER = 100,	//決定キー
	INPUT_NOT_NUM = -1	//数値以外
};		//入力値の値


//################# クラス定義 #################
class Q_BASE
{
protected:

	std::string Q_Text;			//問題文
	int Anser;					//答え
	int InputNum;				//入力された数字

private:


	int GetInputNum(KEYDOWN*);			//入力された数字を取得

public:

	Q_BASE();							//コンストラクタ
	~Q_BASE();							//デストラクタ

	void DrawQuestion();				//問題を描画する

	bool JudgAnser();					//正解か判定する

	bool CheckInputKey(KEYDOWN*);		//キー入力中か取得


};
