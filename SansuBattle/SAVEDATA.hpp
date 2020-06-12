//SAVEDATA.hpp
//セーブデータを管理するクラス

#pragma once

//################## ヘッダファイル読み込み ####################
#include "DATA.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <direct.h>

//################## マクロ定義 #######################
#define SAVEDATA_DIR	R"(C:\SansuBattle)"		//セーブデータの保存ディレクトリ名

#define SAVEDATA_NAME		R"(\Savedata.csv)"		//セーブデータの名前
#define SAVE_NAME_ADD		R"(\Save_Add.csv)"		//セーブデータの名前(足し算)
#define SAVE_NAME_DIF		R"(\Save_Dif.csv)"		//セーブデータの名前(引き算)
#define SAVE_NAME_PRO		R"(\Save_Pro.csv)"		//セーブデータの名前(掛け算)
#define SAVE_NAME_DEA		R"(\Save_Dea.csv)"		//セーブデータの名前(割り算)
#define SAVE_NAME_SUM_DIF	R"(\Save_SumDif.csv)"	//セーブデータの名前(足し算、引き算)
#define SAVE_NAME_PRO_DEA	R"(\Save_ProDea.csv)"	//セーブデータの名前(掛け算、割り算)


//テキスト関係
#define DRAW_DATA_TEXT_INDEX	"ランキング"					//ランキングのテキストタイトル
#define DRAW_DATA_TEXT			"%2d位:%d人抜き(%d/%d/%d)"		//ランキング描画のテキスト
#define DRAW_DATA_X		0	//ランキング描画開始X位置
#define DRAW_DATA_Y		0	//ランキング描画開始Y位置
#define DRAW_DATA_MAX	10	//描画するデータの数

//############## マクロ定義：エラーメッセージ ###################
#define DATA_ERROR_TTILE	"DATA_ERROR"						//エラータイトル
#define DATA_ERROR_MSG		"データが読み込めませんでした"		//エラーメッセージ

using std::string;

//################## クラス定義 #######################
class SAVEDATA
{

private:

	std::vector<DATA*> DataCode;			//セーブデータ

	const char* GetFileName(int);			//どのファイルを使用するか取得
	bool CheckCreateFile(string);			//指定されたファイルが存在するか取得

public:

	SAVEDATA();		//コンストラクタ
	~SAVEDATA();	//デストラクタ

	void Add(int);	//データ追加

	bool Save(int);	//セーブ
	bool Load(int);	//読み込み

	void Sort();	//セーブデータを降順に並べ替える

	void Draw();	//データ描画


};
