//SaveData.hpp
//セーブデータを管理するクラス

#pragma once

//################## ヘッダファイル読み込み ####################
#include "Data.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <direct.h>

//################## マクロ定義 #######################
#define SAVEDATA_DIR	R"(C:\SansuBattle)"		//セーブデータの保存ディレクトリ名

#define SAVEDATA_NAME			R"(\Savedata.csv)"			//セーブデータの名前
#define SAVE_NAME_SUM			R"(\Save_Add.csv)"			//セーブデータの名前(足し算)
#define SAVE_NAME_DIF			R"(\Save_Dif.csv)"			//セーブデータの名前(引き算)
#define SAVE_NAME_PRO			R"(\Save_Pro.csv)"			//セーブデータの名前(掛け算)
#define SAVE_NAME_DEA			R"(\Save_Dea.csv)"			//セーブデータの名前(割り算)
#define SAVE_NAME_SUM_DIF		R"(\Save_SumDif.csv)"		//セーブデータの名前(足し算、引き算)
#define SAVE_NAME_PRO_DEA		R"(\Save_ProDea.csv)"		//セーブデータの名前(掛け算、割り算)
#define SAVE_NAME_SUM_PRO		R"(\Save_SumPro.csv)"		//セーブデータの名前(+*)
#define SAVE_NAME_SUM_DEA		R"(\Save_SumDea.csv)"		//セーブデータの名前(+/)
#define SAVE_NAME_DIF_PRO		R"(\Save_DifPro.csv)"		//セーブデータの名前(-*)
#define SAVE_NAME_SUM_DIF_PRO	R"(\Save_SumDifPro.csv)"	//セーブデータの名前(+-*)
#define SAVE_NAME_SUM_DIF_DEA	R"(\Save_SumDifDea.csv)"	//セーブデータの名前(+-/)
#define SAVE_NAME_ALL			R"(\Save_All.csv)"			//セーブデータの名前(+-*/)


//テキスト関係
#define TEXT_GAMEMODE				"ゲームモード:"					//ゲームモードのテキスト
#define TEXT_GAMEMODE_SUM			"たしざん"						//足し算モードのテキスト
#define TEXT_GAMEMODE_DIF			"ひきざん"						//引き算モードのテキスト
#define TEXT_GAMEMODE_PRO			"かけざん"						//掛け算モードのテキスト
#define TEXT_GAMEMODE_DEA			"わりざん"						//割り算モードのテキスト
#define TEXT_GAMEMODE_SUM_DIF		"たしざん、ひきざん"			//足し算と引き算モードのテキスト
#define TEXT_GAMEMODE_PRO_DEA		"かけざん、わりざん"			//掛け算と割り算モードのテキスト
#define TEXT_GAMEMODE_SUM_PRO		"たしざん、かけざん"			//+*モードのテキスト
#define TEXT_GAMEMODE_SUM_DEA		"たしざん、わりざん"			//+/モードのテキスト
#define TEXT_GAMEMODE_DIF_PRO		"ひきざん、かけざん"			//-*モードのテキスト
#define TEXT_GAMEMODE_SUM_DIF_PRO	"たしざん、ひきざん、かけざん"	//+-*モードのテキスト
#define TEXT_GAMEMODE_SUM_DIF_DEA	"たしざん、ひきざん、わりざん"	//+-/モードのテキスト
#define TEXT_GAMEMODE_ALL			"まとめ"						//allモードのテキスト


#define DRAW_DATA_TEXT			"%2d:%dpoint(%d/%d/%d)"			//ランキング描画のテキスト
#define DRAW_DATA_X		20	//ランキング描画開始X位置
#define DRAW_DATA_Y		20	//ランキング描画開始Y位置
#define DRAW_DATA_MAX	10	//描画するデータの数
#define SAVE_MAX		15	//保存するデータの最大数

//############## マクロ定義：エラーメッセージ ###################
#define DATA_ERROR_TTILE	"DATA_ERROR"						//エラータイトル
#define DATA_ERROR_MSG		"データが読み込めませんでした"		//エラーメッセージ

using std::string;
using std::vector;

//################## クラス定義 #######################
class SaveData
{

private:

	vector<Data*> DataCode;					//セーブデータ
	static vector<string> FileNameTable;	//ファイル名のテーブル
	static vector<string> TextTable;		//テキストのテーブル

	bool CheckCreateFile(string);			//指定されたファイルが存在するか取得
	void CreateTable();						//テーブルの作成

public:

	SaveData();		//コンストラクタ
	~SaveData();	//デストラクタ

	void Add(int);	//データ追加

	bool Save(int);	//セーブ
	bool Load(int);	//読み込み

	void Sort();	//セーブデータを降順に並べ替える

	void Draw(int);	//データ描画


};
