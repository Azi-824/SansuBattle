//Question.cpp
//問題関係の全ての基になるクラス

//############### ヘッダファイル読み込み #######################
#include "Question.hpp"

//############### クラス定義 ####################

//インスタンスを生成
Image* Question::img_kokuban;			//黒板の画像
vector<CalcInfo*> Question::calc_info;	//計算に使用する情報
vector<vector<int>> Question::value_num;	//値の数

//コンストラクタ
Question::Question()
{
	//メンバー初期化
	Anser = 0;				//答え初期化
	InputNum = 0;			//入力された数字初期化
	InputNumBuf = 0;		//貯めてある数字を初期化
	Q_Text = "";			//問題文初期化
	IsCreate = false;		//問題を作成したか初期化

	if (calc_info.empty())	//情報を作成していなければ
	{
		for (int i = CALC_SUM; i < CALC_MAX; ++i)	//計算種類分
		{
			CreateInfo(i);	//情報を作成
		}

		value_num.resize(GAMEMODE_MAX);	//サイズ変更
		for (int i = GAMEMODE_SUM; i < GAMEMODE_MAX; ++i)	//ゲームモードの種類分
		{
			CreateValueNum(i);	//値の数の情報を作成
		}

	}

	if (img_kokuban == NULL)	//黒板の画像を生成していなければ
	{
		img_kokuban = new Image(Q_IMAGE_DIR, Q_IMAGE_KOKUBAN_NAME);	//黒板の画像を生成
	}
	
}

//デストラクタ
Question::~Question(){}

//問題作成
void Question::Create(int gamemode, int gamelevel)
{
	int min = 0, max = 0;				//問題の最小値、最大値
	vector<int> calc_value, calc_type;	//値、計算の種類

	SetCalcType(gamemode, gamelevel, &calc_type);	//計算の種類を設定

	for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)		//計算回数分ループ
	{
		min = calc_info.at(calc_type.at(i))->GetMin(gamelevel);	//最小値取得
		max = calc_info.at(calc_type.at(i))->GetMax(gamelevel);	//最小値取得

		calc_value.push_back(GetRand(max - min) + min);			//値を生成

	}

	vector<int> order;				//計算の順番
	SetOrder(calc_type, &order);	//計算の順番を設定

	CreateQuestion(calc_value, calc_type,order);	//問題を生成

	IsCreate = true;	//問題を作成した

	//vectorの解放
	vector<int> v;
	calc_value.swap(v);
	vector<int> v2;
	calc_type.swap(v2);
	vector<int> v3;
	order.swap(v3);

}

//計算の種類を設定
void Question::SetCalcType(int gamemode, int gamelevel, vector<int>* calc_type)
{
	switch (gamemode)	//ゲームモード毎
	{

	case GAMEMODE_SUM:	//足し算の時

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_SUM);	//足し算
		}

		break;			//足し算の時ここまで

	case GAMEMODE_DIFFERENCE:	//引き算の時

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_DIFFERENCE);	//引き算
		}

		break;			//引き算の時ここまで

	case GAMEMODE_PRODUCT:	//掛け算の時

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_PRODUCT);	//掛け算
		}

		break;			//掛け算の時ここまで

	case GAMEMODE_DEALER:		//割り算の時

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_DEALER);	//割り算
		}

		break;		//割り算の時ここまで

	default:
		break;
	}

}

//計算の順番を設定
void Question::SetOrder(vector<int> calc_type, vector<int>* order)
{
	vector<bool> set_flg;	//設定済みか

	for (int i = 0; i < calc_type.size(); ++i)
		set_flg.push_back(false);	//初期化

	for (int i = 0; i < calc_type.size(); ++i)
	{
		if (calc_type.at(i) == CALC_PRODUCT || calc_type.at(i) == CALC_DEALER)	//掛け算か、割り算だったら
		{
			order->push_back(i);	//計算の順番を設定
			set_flg.at(i) = true;	//設定済み
		}

	}

	for (int i = 0; i < calc_type.size(); ++i)
	{
		if (!set_flg.at(i))	//設定済みじゃなければ
		{
			order->push_back(i);	//計算の順番を設定
			set_flg.at(i) = true;	//設定済み
		}
	}

	//vectorの解放
	vector<bool> v;
	set_flg.swap(v);

}

//それぞれの問題を作成
void Question::CreateQuestion(vector<int>calc_value, vector<int>calc_type, vector<int> order)
{
	Q_Text = std::to_string(calc_value.at(order.front()));	//一番最初に計算される値を問題文に設定

	for (int i = 0; i < order.size() - 1; ++i)
	{
		switch (calc_type.at(order.at(i)))	//計算の種類ごとに分岐
		{

		case CALC_SUM:	//足し算

			Q_Text += "＋";																				//演算記号を問題文に追加
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) + calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //足し算

		case CALC_DIFFERENCE:	//引き算

			Q_Text += "－";																				//演算記号を問題文に追加
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) - calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //引き算

		case CALC_PRODUCT:	//掛け算

			Q_Text += "×";																				//演算記号を問題文に追加
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) * calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //掛け算

		case CALC_DEALER:	//割り算

			Q_Text += "÷";																				//演算記号を問題文に追加
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) / calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //割り算


		default:
			break;
		}

		Q_Text += std::to_string(calc_value.at(order.at(i) + 1));	//問題文追加

		//計算済みの要素を削除
		calc_value.erase(calc_value.begin() + order.at(i) + 1);	//計算済みの値を削除
		calc_type.erase(calc_type.begin() + order.at(i) + 1);	//計算済みの計算種類を削除

		//計算済みの要素を削除したため、計算順番を一つずつ前に繰り上げる
		for (auto itr = order.begin(); itr != order.end(); ++itr)
		{
			if (*itr != 0)	//先頭じゃなければ
				--* itr;
		}

	}

	Anser = calc_value.front();	//先頭に全ての計算結果が格納されているため、それを答えに設定
	Q_Text += "＝？";			//問題文追加

}

//計算に使用する情報を作成
void Question::CreateInfo(int calctype)
{
	vector<int> min, max, value_num;	//最小値、最大値、数
	switch (calctype)	//計算の種類
	{

	case CALC_SUM:	//足し算

		min.push_back(1);	//簡単の最小値
		min.push_back(10);	//普通の最小値
		min.push_back(20);	//難しいの最小値

		max.push_back(9);	//簡単の最大値
		max.push_back(20);	//普通の最大値
		max.push_back(30);	//難しいの最大値

		value_num.push_back(1);	//簡単の計算回数
		value_num.push_back(1);	//普通の計算回数
		value_num.push_back(1);	//難しいの計算回数

		break; //足し算

	case CALC_DIFFERENCE:	//引き算

		min.push_back(1);	//簡単の最小値
		min.push_back(5);	//普通の最小値
		min.push_back(10);	//難しいの最小値

		max.push_back(9);	//簡単の最大値
		max.push_back(20);	//普通の最大値
		max.push_back(30);	//難しいの最大値

		value_num.push_back(1);	//簡単の計算回数
		value_num.push_back(1);	//普通の計算回数
		value_num.push_back(1);	//難しいの計算回数

		break; //引き算

	case CALC_PRODUCT:	//掛け算

		min.push_back(1);	//簡単の最小値
		min.push_back(5);	//普通の最小値
		min.push_back(10);	//難しいの最小値

		max.push_back(9);	//簡単の最大値
		max.push_back(20);	//普通の最大値
		max.push_back(30);	//難しいの最大値

		value_num.push_back(1);	//簡単の計算回数
		value_num.push_back(1);	//普通の計算回数
		value_num.push_back(1);	//難しいの計算回数

		break; //掛け算

	case CALC_DEALER:	//割り算

		min.push_back(1);	//簡単の最小値
		min.push_back(5);	//普通の最小値
		min.push_back(10);	//難しいの最小値

		max.push_back(9);	//簡単の最大値
		max.push_back(20);	//普通の最大値
		max.push_back(30);	//難しいの最大値

		value_num.push_back(1);	//簡単の計算回数
		value_num.push_back(1);	//普通の計算回数
		value_num.push_back(1);	//難しいの計算回数

		break; //割り算

	default:
		break;
	}

	calc_info.push_back(new CalcInfo(min, max, value_num));	//情報を追加

}

//ゲームモード毎の値の数の情報を作成
void Question::CreateValueNum(int gamemode)
{
	switch (gamemode)	//ゲームモード毎
	{

	case GAMEMODE_SUM:	//足し算の時

		value_num.at(gamemode).push_back(2);	//簡単の時の値の数
		value_num.at(gamemode).push_back(2);	//普通の時の値の数
		value_num.at(gamemode).push_back(2);	//難しいの時の値の数

		break;			//足し算の時ここまで

	case GAMEMODE_DIFFERENCE:	//引き算の時

		value_num.at(gamemode).push_back(2);	//簡単の時の値の数
		value_num.at(gamemode).push_back(2);	//普通の時の値の数
		value_num.at(gamemode).push_back(2);	//難しいの時の値の数

		break;			//引き算の時ここまで

	case GAMEMODE_PRODUCT:	//掛け算の時

		value_num.at(gamemode).push_back(2);	//簡単の時の値の数
		value_num.at(gamemode).push_back(2);	//普通の時の値の数
		value_num.at(gamemode).push_back(2);	//難しいの時の値の数

		break;			//掛け算の時ここまで

	case GAMEMODE_DEALER:		//割り算の時

		value_num.at(gamemode).push_back(2);	//簡単の時の値の数
		value_num.at(gamemode).push_back(2);	//普通の時の値の数
		value_num.at(gamemode).push_back(2);	//難しいの時の値の数

		break;			//割り算の時ここまで

	case GAMEMODE_SUM_DIFFERENCE:		//足し算、引き算の時

		value_num.at(gamemode).push_back(2);	//簡単の時の値の数
		value_num.at(gamemode).push_back(2);	//普通の時の値の数
		value_num.at(gamemode).push_back(2);	//難しいの時の値の数

		break;			//割り算の時ここまで

	case GAMEMODE_PRODUCT_DEALER:		//掛け算、割り算の時

		value_num.at(gamemode).push_back(2);	//簡単の時の値の数
		value_num.at(gamemode).push_back(2);	//普通の時の値の数
		value_num.at(gamemode).push_back(2);	//難しいの時の値の数

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

	if (!(NewInputNum == INPUT_ENTER || NewInputNum == INPUT_NOT_NUM || NewInputNum == INPUT_BACK))	//数値を入力した時
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

		if (NewInputNum == INPUT_BACK)	//バックスペースを押されたら
		{
			InputNumBuf /= Weight;		//一文字分消す
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

	case KEY_INPUT_BACK:		//バックスペースキーを押された場合

		return INPUT_BACK;		//バック

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
	Anser = 0;			//答えリセット
	InputNum = 0;		//キー入力内容リセット
	InputNumBuf = 0;	//貯めてある数字を初期化
	Q_Text = "";		//問題文リセット
	IsCreate = false;	//問題を作成したかリセット
}