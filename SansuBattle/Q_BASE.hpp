//Q_Base.hpp
//問題関係の全ての基になるクラス

#pragma once

//################# ヘッダファイル読み込み ###############
#include "Global.hpp"
#include <string>
#include "KeyDown.hpp"
#include "Image.hpp"

//################# マクロ定義 #################
#define Q_IMG_DRAW_Y 490	//問題の画像（黒板）描画Y位置
#define Q_DRAW_Y 500		//問題の描画Y位置

#define Q_EASY_VALUE_MAX 9	//簡単モードの問題の最大値

#define Q_IMAGE_DIR		R"(.\MY_IMG\Question)"		//問題関係の画像のディレクトリ

#define	Q_IMAGE_KOKUBAN_NAME	R"(\kokuban.png)"	//黒板の画像の名前

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
class Q_Base
{
protected:

	static Image* img_kokuban;			//黒板の画像

	static std::string Q_Text;			//問題文
	static int Anser;					//答え
	static int InputNum;				//入力された数字
	static bool IsCreate;				//問題を作成したか

private:

	static int GetInputNum(KeyDown*);	//入力された数字を取得

public:

	Q_Base();							//コンストラクタ
	~Q_Base();							//デストラクタ

	virtual void CreateQuestion(int) = 0;	//問題作成

	static void DrawQuestion();			//問題を描画する
	static void DrawInputNum();			//入力中の数字を描画する

	static bool JudgAnser();			//正解か判定する

	static bool CheckInputKey(KeyDown*);//キー入力中か取得

	static bool GetIsCreate();			//問題を作成したか取得

	static void Reset();				//問題をリセット


};
