//Question.cpp
//問題関係の全ての基になるクラス

//############### ヘッダファイル読み込み #######################
#include "Question.hpp"

//############### クラス定義 ####################

//インスタンスを生成
Image* Question::img_kokuban;			//黒板の画像

//コンストラクタ
Question::Question()
{
	//メンバー初期化
	Anser = -1;				//答え初期化
	InputNum = 0;			//入力された数字初期化
	InputNumBuf = 0;		//貯めてある数字を初期化
	Q_Text = "";			//問題文初期化
	IsCreate = false;		//問題を作成したか初期化

	if (img_kokuban == NULL)	//黒板の画像を生成していなければ
	{
		img_kokuban = new Image(Q_IMAGE_DIR, Q_IMAGE_KOKUBAN_NAME);	//黒板の画像を生成
	}
	return;
}

//デストラクタ
Question::~Question()
{
	return;
}

//問題作成
void Question::Create(int gamemode, int gamelevel)
{
	int min = 0, max = 0;	//問題の最小値、最大値
	SetMinMax(gamemode, gamelevel, &min, &max);	//問題の最小値、最大値設定

	int num1 = 0, num2 = 0;		//問題を入れる変数

	num1 = GetRand(max - min) + min;			//問題を生成
	num2 = GetRand(max - min) + min;			//問題を生成

	CreateQuestion(gamemode, num1, num2);		//ゲームモード毎の問題を作成。
	IsCreate = true;	//問題を作成した

}

//指定されたゲームモード、ゲームレベルの問題の最大値最小値を設定
void Question::SetMinMax(int gamemode, int gamelevel, int* min, int* max)
{
	switch (gamemode)	//ゲームモード毎
	{

	case Q_MODE_SUM:	//足し算の時

		switch (gamelevel)	//ゲームレベル毎
		{

		case STAGE_LEVEL_EASY:	//簡単の時

			*min = 1;					//最小値1
			*max = Q_EASY_VALUE_MAX;	//最大値9

			break;	//簡単の時

		case STAGE_LEVEL_NORMAL:	//普通の時

			*min = 10;	//最小値10
			*max = 20;	//最大値20

			break;	//普通の時

		case STAGE_LEVEL_HARD:	//難しいの時

			*min = 20;	//最小値20
			*max = 30;	//最大値30

			break;	//難しいの時

		default:
			break;
		}

		break;			//足し算の時ここまで

	case Q_MODE_DIFFERENCE:	//引き算の時

		switch (gamelevel)	//ゲームレベル毎
		{

		case STAGE_LEVEL_EASY:	//簡単の時

			*min = 1;					//最小値1
			*max = Q_EASY_VALUE_MAX;	//最大値9

			break;	//簡単の時

		case STAGE_LEVEL_NORMAL:	//普通の時

			*min = 5;	//最小値5
			*max = 20;	//最大値20

			break;	//普通の時

		case STAGE_LEVEL_HARD:	//難しいの時

			*min = 10;	//最小値10
			*max = 30;	//最大値30

			break;	//難しいの時

		default:
			break;
		}

		break;			//引き算の時ここまで

	case Q_MODE_PRODUCT:	//掛け算の時

		switch (gamelevel)	//ゲームレベル毎
		{

		case STAGE_LEVEL_EASY:	//簡単の時

			*min = 1;					//最小値1
			*max = Q_EASY_VALUE_MAX;	//最大値9

			break;	//簡単の時

		case STAGE_LEVEL_NORMAL:	//普通の時

			*min = 5;	//最小値5
			*max = 20;	//最大値20

			break;	//普通の時

		case STAGE_LEVEL_HARD:	//難しいの時

			*min = 10;	//最小値10
			*max = 30;	//最大値30

			break;	//難しいの時

		default:
			break;
		}

		break;			//掛け算の時ここまで

	case Q_MODE_DEALER:		//割り算の時

		switch (gamelevel)	//ゲームレベル毎
		{

		case STAGE_LEVEL_EASY:	//簡単の時

			*min = 1;					//最小値1
			*max = Q_EASY_VALUE_MAX;	//最大値9

			break;	//簡単の時

		case STAGE_LEVEL_NORMAL:	//普通の時

			*min = 5;	//最小値5
			*max = 20;	//最大値20

			break;	//普通の時

		case STAGE_LEVEL_HARD:	//難しいの時

			*min = 10;	//最小値10
			*max = 30;	//最大値30

			break;	//難しいの時

		default:
			break;
		}

		break;		//割り算の時ここまで

	default:
		break;
	}

}

//ゲームモード毎の問題を作成
void Question::CreateQuestion(int gamemode,int num1, int num2)
{
	switch (gamemode)	//ゲームモード毎
	{

	case Q_MODE_SUM:	//足し算の時

		Anser = num1 + num2;	//足し算の答えを設定
		Q_Text = (std::to_string(num1) + "＋" + (std::to_string(num2) + "＝？"));		//問題文を設定

		break;			//足し算の時ここまで

	case Q_MODE_DIFFERENCE:	//引き算の時

		if (num1 < num2)		//num1の値がnum2より小さいとき
		{
			//値の交換
			int w = num2;
			num2 = num1;
			num1 = w;
		}
		Anser = num1 - num2;	//問題の計算結果を答えに格納
		Q_Text = (std::to_string(num1) + "－" + (std::to_string(num2) + "＝？"));		//問題文を設定

		break;			//引き算の時ここまで

	case Q_MODE_PRODUCT:	//掛け算の時

		Anser = num1 * num2;	//問題の計算結果を答えに格納
		Q_Text = (std::to_string(num1) + "×" + (std::to_string(num2) + "＝？"));		//問題文を設定

		break;			//掛け算の時ここまで

	case Q_MODE_DEALER:		//割り算の時

		if (num1 % num2 != 0)	//割り切れない時
		{
			num1 -= num1 % num2;	//割り切れるように調整
		}
		Anser = num1 / num2;	//問題の計算結果を答えに格納
		Q_Text = (std::to_string(num1) + "÷" + (std::to_string(num2) + "＝？"));		//問題文を設定

		break;			//割り算の時ここまで

	default:
		break;
	}
}

//問題を描画する
void Question::DrawQuestion()
{

	img_kokuban->Draw(GAME_LEFT, Q_IMG_DRAW_Y);		//黒板の画像を描画

	int Strlen = strlen(Q_Text.c_str());					//文字列長さを取得
	int Width = GetDrawStringWidthToHandle(Q_Text.c_str(), Strlen, NowFontHandle);	//横幅取得

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), Q_DRAW_Y, COLOR_WHITE, NowFontHandle, "%s", Q_Text.c_str());	//問題文を描画

	return;
}

//入力中の数字を描画する
void Question::DrawInputNum()
{
	int Strlen = strlen(std::to_string(InputNum).c_str());						//文字列の長さを取得
	int Width = GetDrawStringWidthToHandle(std::to_string(InputNum).c_str(), Strlen, NowFontHandle);	//横幅取得
	int Height = GetFontSizeToHandle(NowFontHandle);							//高さ取得

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), COLOR_WHITE, NowFontHandle, "%d", InputNum);	//入力中の数字を描画

}

//正解か判定する
/*
引数：int：プレイヤーの答え
戻り値：bool：true 正解：false 不正解
*/
bool Question::JudgAnser()
{
	if (Anser == InputNum)				//プレイヤーの回答が、答えと一緒だったら
	{
		Question::IsCreate = false;		//問題を作成したか、リセット
		return true;					//正解
	}
	else								//一緒じゃなかったら
		return false;					//不正解
}

//キー入力中か確認
//戻り値：bool：true 入力終了：false 入力中
bool Question::CheckInputKey(KeyDown* keydown)
{
	static int Weight = 10;					//桁の重み
	int NewInputNum = GetInputNum(keydown);	//新たに入力された数字

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

	InputNum = InputNumBuf;	//入力された数字を設定

	return false;
}

//入力された数字を取得
int Question::GetInputNum(KeyDown* keydown)
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

//問題を作成したか取得
bool Question::GetIsCreate()
{
	return IsCreate;
}

//問題をリセット
void Question::Reset()
{
	Anser = -1;			//答えリセット
	InputNum = 0;		//キー入力内容リセット
	InputNumBuf = 0;	//貯めてある数字を初期化
	Q_Text = "";		//問題文リセット
	IsCreate = false;	//問題を作成したかリセット
}