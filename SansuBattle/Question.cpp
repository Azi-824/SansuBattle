//Question.cpp
//問題関係の全ての基になるクラス

//############### ヘッダファイル読み込み #######################
#include "Question.hpp"

//############### クラス定義 ####################

//インスタンスを生成
Image* Question::img_kokuban;					//黒板の画像
vector<vector<int>> Question::ValueNum_Table;	//値の数
vector<vector<int>> Question::CalcType_Table;	//各ゲームモードの計算の種類のテーブル

//コンストラクタ
Question::Question()
{
	//メンバー初期化
	Anser = 0;				//答え初期化
	InputNum = 0;			//入力された数字初期化
	InputNumBuf = 0;		//貯めてある数字を初期化
	Q_Text = "";			//問題文初期化
	IsCreate = false;		//問題を作成したか初期化

	if (ValueNum_Table.empty())	//情報を作成していなければ
	{
		//テーブル作成
		CreateTable();		//テーブル作成

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
	int min = 3, max = 0;				//問題の最小値、最大値

	vector<int> value, type;	//値、計算の種類

	SetCalcType(gamemode, gamelevel, &type);	//計算の種類を設定

	for (int i = 0; i < ValueNum_Table.at(gamemode).at(gamelevel); ++i)
	{
		max = GetMax(gamelevel, value);				//最大値設定
		int rand = GetRand(max - min) + min;		//値をランダムで生成

		value.push_back(rand);	//値を追加
	}


	vector<int> order;		//計算の順番
	SetOrder(type, &order);	//計算の順番を設定

	CreateQuestion(value, type, order);	//問題を生成

	IsCreate = true;	//問題を作成した

	//vectorの解放
	vector<int> v;
	value.swap(v);
	vector<int> v2;
	type.swap(v2);
	vector<int> v3;
	order.swap(v3);

}

//計算の種類を設定
void Question::SetCalcType(int gamemode, int gamelevel, vector<int>* calc_type)
{

	for (int i = 0; i < ValueNum_Table.at(gamemode).at(gamelevel) - 1; ++i)
	{
		int rand = GetRand(CalcType_Table.at(gamemode).size() - 1);		//乱数生成
		calc_type->push_back(CalcType_Table.at(gamemode).at(rand));		//計算の種類を設定
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

//最大値取得
int Question::GetMax(int gamelevel, vector<int> value)
{

	//レベル毎の最大値
	const int value_max[GAME_LEVEL_MAX] = { EASY_VALUE_MAX ,NORMAL_VALUE_MAX ,HARD_VALUE_MAX };

	if (value.empty())	//最初の取得なら
	{
		//定数を返す
		return value_max[gamelevel];	//ゲームレベル毎の最大値を返す

	}
	else	//最初じゃなければ
	{
		return GetRand(value.back());	//最後の値を最大値とした乱数を返す
	}
}

//それぞれの問題を作成
void Question::CreateQuestion(vector<int>calc_value, vector<int>calc_type, vector<int> order)
{

	auto type_cp = calc_type;	//種類のコピー
	auto value_cp = calc_value;	//値のコピー
	auto order_cp = order;		//順番のコピー

	for (int i = 0; i < order.size(); ++i)
	{
		switch (calc_type.at(order.at(i)))	//計算の種類ごとに分岐
		{

		case CALC_SUM:	//足し算

			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) + calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //足し算

		case CALC_DIFFERENCE:	//引き算

			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) - calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //引き算

		case CALC_PRODUCT:	//掛け算

			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) * calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //掛け算

		case CALC_DEALER:	//割り算

			//値の調整
			while (calc_value.at(order.at(i)) % calc_value.at(order.at(i) + 1) != 0)	//割り切れない間
			{
				//割り切れる値になるまで、値を減らす
				--calc_value.at(order.at(i) + 1);
			}
			value_cp.at(order.at(i) + 1) = calc_value.at(order.at(i) + 1);	//値を変化させたため、コピーの方を更新する
			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) / calc_value.at(order.at(i) + 1);	//指定された値と、その次の値で計算

			break; //割り算


		default:
			break;
		}

		//計算済みの要素を削除
		calc_value.erase(calc_value.begin() + order.at(i));		//計算済みの値を削除
		calc_type.erase(calc_type.begin() + order.at(i));		//計算済みの計算種類を削除

		//計算済みの要素を削除したため、計算順番を一つずつ前に繰り上げる
		for (auto itr = order.begin(); itr != order.end(); ++itr)
		{
			if (*itr != 0)	//先頭じゃなければ
				--* itr;
		}

	}

	SetText(value_cp, type_cp, order_cp);	//問題文のテキストを設定

	Anser = calc_value.front();	//先頭に全ての計算結果が格納されているため、それを答えに設定

}

//各ゲームモードの計算の種類のテーブル
void Question::CreateTable()
{

	vector<int> work;	//作業用

	//**************************** 各ゲームモードの値の数のテーブル **************************
	//足し算モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//足し算モードの値の数を追加
	work.clear();					//中身をクリア

	//引き算モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//引き算モードの値の数を追加
	work.clear();					//中身をクリア

	//掛け算モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//掛け算モードの値の数を追加
	work.clear();					//中身をクリア

	//割り算モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//割り算モードの値の数を追加
	work.clear();					//中身をクリア

	//足し算、引き算モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//足し算、引き算モードの値の数を追加
	work.clear();					//中身をクリア

	//掛け算、割り算モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//掛け算、割り算モードの値の数を追加
	work.clear();					//中身をクリア

	//+*モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//+*モードの値の数を追加
	work.clear();					//中身をクリア

	//+/モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//+/モードの値の数を追加
	work.clear();					//中身をクリア

	//-*モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//-*モードの値の数を追加
	work.clear();					//中身をクリア

	//+-*モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//+-*モードの値の数を追加
	work.clear();					//中身をクリア

	//+-/モード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//+-/モードの値の数を追加
	work.clear();					//中身をクリア

	//allモード
	work.push_back(2);		//簡単
	work.push_back(3);		//普通
	work.push_back(4);		//難しい
	ValueNum_Table.push_back(work);	//allモードの値の数を追加
	work.clear();					//中身をクリア


	//**************************** 各ゲームモードの計算の種類のテーブル **************************
	//足し算モード
	work.push_back(CALC_SUM);		//足し算
	CalcType_Table.push_back(work);	//足し算モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//引き算モード
	work.push_back(CALC_DIFFERENCE);//引き算
	CalcType_Table.push_back(work);	//引き算モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//掛け算モード
	work.push_back(CALC_PRODUCT);	//掛け算
	CalcType_Table.push_back(work);	//掛け算モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//割り算モード
	work.push_back(CALC_DEALER);	//割り算
	CalcType_Table.push_back(work);	//割り算モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//足し算、引き算モード
	work.push_back(CALC_SUM);		//足し算
	work.push_back(CALC_DIFFERENCE);//引き算
	CalcType_Table.push_back(work);	//足し算、引き算モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//掛け算、割り算モード
	work.push_back(CALC_PRODUCT);	//掛け算
	work.push_back(CALC_DEALER);	//割り算
	CalcType_Table.push_back(work);	//掛け算、割り算モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//足し算、掛け算モード
	work.push_back(CALC_SUM);		//足し算
	work.push_back(CALC_PRODUCT);	//掛け算
	CalcType_Table.push_back(work);	//足し算、掛け算モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//+/モード
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DEALER);	// /
	CalcType_Table.push_back(work);	//+/モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//-*モード
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_PRODUCT);	//*
	CalcType_Table.push_back(work);	//-*モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//+-*モード
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_PRODUCT);	//*
	CalcType_Table.push_back(work);	//+-*モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//+-/モード
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_DEALER);	///
	CalcType_Table.push_back(work);	//+-/モードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//allモード
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_PRODUCT);	//*
	work.push_back(CALC_DEALER);	///
	CalcType_Table.push_back(work);	//allモードの計算の種類の選択肢を追加
	work.clear();					//中身をクリア

	//vectorの解放
	vector<int> v;
	work.swap(v);


}

//問題文のテキストを設定
void Question::SetText(vector<int> value, vector<int> type, vector<int> order)
{

	//記号のテーブル作成
	static vector<string> SymbolTable = { "＋","－","×","÷" };

	Q_Text = std::to_string(value.front());	//先頭の値を問題文に設定

	for (int i = 0; i < type.size(); ++i)
	{
		Q_Text += SymbolTable.at(type.at(i));		//記号を問題文に追加
		Q_Text += std::to_string(value.at(i + 1));	//値を問題文に追加(最初の値は既に追加されているため、+1した要素の値を設定)
	}

	Q_Text += "＝？";			//問題文追加

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
	int NewInputKey = GetInputKey(keydown);	//新たに入力されたキー

	if (INPUT_NUM_0 <= NewInputKey && NewInputKey <= INPUT_NUM_9)	//数値を入力した時
	{
		if ((unsigned int)((InputNumBuf * Weight) + NewInputKey) < INT_MAX)		//int型の最大値を超えなければ
		{
			InputNumBuf = (InputNumBuf * Weight) + NewInputKey;	//入力値に桁の重みを付けて計算
		}

	}
	else	//数値以外を入力した時
	{
		if (NewInputKey == INPUT_ENTER)	//決定された場合
		{
			InputNumBuf = 0;	//初期化
			return true;		//入力終了
		}

		if (NewInputKey == INPUT_BACK)	//バックスペースを押されたら
		{
			InputNumBuf /= Weight;		//一文字分消す
		}
	}

	InputNum = InputNumBuf;	//入力された数字を設定

	return false;
}

//入力されたキーを取得
int Question::GetInputKey(KeyDown* keydown)
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

	case KEY_INPUT_MINUS:		//マイナスキー
	case KEY_INPUT_SUBTRACT:	//テンキーのマイナスキー

		return INPUT_MINUS;		//マイナス

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