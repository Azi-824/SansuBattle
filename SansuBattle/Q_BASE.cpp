//Q_BASE.cpp
//問題関係の全ての基になるクラス

//############### ヘッダファイル読み込み #######################
#include "Q_BASE.hpp"

//############### クラス定義 ####################

//コンストラクタ
Q_BASE::Q_BASE()
{
	//メンバー変数初期化
	this->Anser = -1;		//答え初期化
	this->Q_Text = "";		//問題文初期化
	this->InputNum = 0;		//入力された数字初期化

	return;
}

//デストラクタ
Q_BASE::~Q_BASE()
{
	return;
}

//問題を描画する
void Q_BASE::DrawQuestion()
{
	DrawFormatString(Q_DRAW_X, Q_DRAW_Y, GetColor(255, 255, 255), "%s", this->Q_Text.c_str());	//問題文を描画

	return;
}

//正解か判定する
/*
引数：int：プレイヤーの答え
戻り値：bool：true 正解：false 不正解
*/
bool Q_BASE::JudgAnser()
{
	if (this->Anser == this->InputNum)	//プレイヤーの回答が、答えと一緒だったら
		return true;					//正解
	else								//一緒じゃなかったら
		return false;					//不正解
}

//キー入力中か確認
//戻り値：bool：true 入力終了：false 入力中
bool Q_BASE::CheckInputKey(KEYDOWN* keydown)
{
	static int InputNumBuf = 0;						//入力された数字
	static int Weight = 10;							//桁の重み
	int NewInputNum = this->GetInputNum(keydown);	//新たに入力された数字

	if (!(NewInputNum == INPUT_ENTER || NewInputNum == INPUT_NOT_NUM))	//数値を入力した時
	{
		if ((unsigned int)((InputNumBuf * Weight) + NewInputNum) < INT_MAX)		//int型の最大値を超えなければ
		{
			InputNumBuf = (InputNumBuf * Weight) + NewInputNum;	//入力値に桁の重みを付けて計算
		}

	}
	else	//数値以外を入力した時
	{
		if (NewInputNum == INPUT_ENTER)	//決定された場合
		{
			InputNumBuf = 0;	//初期化
			return true;		//入力終了
		}
	}

	this->InputNum = InputNumBuf;	//入力された数字を設定

	return false;
}

//入力された数字を取得
int Q_BASE::GetInputNum(KEYDOWN* keydown)
{
	switch (keydown->GetInputKeyCode())		//入力されたキーコードごとに処理を分岐
	{

	case KEY_INPUT_0:		//0を入力された場合
	case KEY_INPUT_NUMPAD0:	//テンキーで0を入力された場合

		return INPUT_NUM_0;	//入力値0

		break;

	case KEY_INPUT_1:		//1を入力された場合
	case KEY_INPUT_NUMPAD1:	//テンキーで1を入力された場合

		return INPUT_NUM_1;	//入力値1

		break;

	case KEY_INPUT_2:		//2を入力された場合
	case KEY_INPUT_NUMPAD2:	//テンキーで2を入力された場合

		return INPUT_NUM_2;	//入力値2

		break;

	case KEY_INPUT_3:		//3を入力された場合
	case KEY_INPUT_NUMPAD3:	//テンキーで3を入力された場合

		return INPUT_NUM_3;	//入力値3

		break;

	case KEY_INPUT_4:		//4を入力された場合
	case KEY_INPUT_NUMPAD4:	//テンキーで4を入力された場合

		return INPUT_NUM_4;	//入力値4

		break;

	case KEY_INPUT_5:		//5を入力された場合
	case KEY_INPUT_NUMPAD5:	//テンキーで5を入力された場合

		return INPUT_NUM_5;	//入力値5

		break;

	case KEY_INPUT_6:		//6を入力された場合
	case KEY_INPUT_NUMPAD6:	//テンキーで6を入力された場合

		return INPUT_NUM_6;	//入力値6

		break;

	case KEY_INPUT_7:		//7を入力された場合
	case KEY_INPUT_NUMPAD7:	//テンキーで7を入力された場合

		return INPUT_NUM_7;	//入力値7

		break;

	case KEY_INPUT_8:		//8を入力された場合
	case KEY_INPUT_NUMPAD8:	//テンキーで8を入力された場合

		return INPUT_NUM_8;	//入力値8

		break;

	case KEY_INPUT_9:		//9を入力された場合
	case KEY_INPUT_NUMPAD9:	//テンキーで9を入力された場合

		return INPUT_NUM_9;	//入力値9

		break;

	case KEY_INPUT_RETURN:		//エンターキー（決定された）場合
	case KEY_INPUT_NUMPADENTER:	//テンキーでエンターキー（決定された）場合

		return INPUT_ENTER;		//決定

		break;

	default:					//それ以外の場合（数字以外の入力の場合）

		return INPUT_NOT_NUM;	//数字以外の入力
		break;
	}
}
