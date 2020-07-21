//Question.hpp
//問題関係の全ての基になるクラス

#pragma once

//################# ヘッダファイル読み込み ###############
#include "Global.hpp"
#include <string>
#include <vector>
#include "KeyDown.hpp"
#include "Image.hpp"

//################# マクロ定義 #################
#define Q_IMG_DRAW_Y 490	//問題の画像（黒板）描画Y位置
#define Q_DRAW_Y 500		//問題の描画Y位置

#define EASY_VALUE_MAX 15	//簡単レベルの問題の最大値
#define NORMAL_VALUE_MAX 20	//普通レベルの問題の最大値
#define HARD_VALUE_MAX	25	//難しいレベルの問題の最大値

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
	INPUT_BACK = 200,	//バックキー
	INPUT_MINUS = 300,	//マイナスキー
	INPUT_NOT_NUM = -1	//数値以外
};		//入力値の値

enum CALC_KIND
{
	CALC_SUM,			//足し算
	CALC_DIFFERENCE,	//引き算
	CALC_PRODUCT,		//掛け算
	CALC_DEALER,		//割り算
	CALC_MAX			//計算の種類の個数
};	//計算の種類

using std::vector;
using std::string;

//################# クラス定義 #################
class Question
{
private:

	static Image* img_kokuban;			//黒板の画像
	static vector<vector<int>> ValueNum_Table;	//値の数
	static vector<vector<int>> CalcType_Table;	//各ゲームモードの計算の種類のテーブル

	string Q_Text;				//問題文
	int Anser;					//答え
	string InputNum;			//入力された数字
	bool IsCreate;				//問題を作成したか

	int GetInputKey(KeyDown*);									//入力されたキーを取得
	void SetCalcType(int, int, vector<int>*);					//計算の種類を設定
	void SetOrder(vector<int>, vector<int>*);					//計算の順番を設定
	int GetMax(int, vector<int>);								//最大値取得
	void CreateQuestion(vector<int>, vector<int>, vector<int>);	//問題を作成
	void CreateTable();											//各ゲームモードの計算の種類のテーブルを作成
	void SetText(vector<int>, vector<int>, vector<int>);		//問題文のテキストを設定

public:

	Question();							//コンストラクタ
	~Question();						//デストラクタ

	void Create(int, int);			//問題作成

	void DrawQuestion();			//問題を描画する
	void DrawInputNum();			//入力中の数字を描画する

	bool JudgAnser();			//正解か判定する

	bool CheckInputKey(KeyDown*);//キー入力中か取得

	bool GetIsCreate();			//問題を作成したか取得
	void Reset();				//問題をリセット


};
