//FONT.hpp
//フォントクラス

/*
追加方法
・フォントのファイル名と、フォントの名前をマクロ定義する
・マクロ定義されているフォントの種類を増やす
・Add処理を使用して、ゲーム内で使用するフォントを増やすことができる
*/

#pragma once

//################# ヘッダファイル読み込み ######################
#include "Global.hpp"
#include <string>
#include <vector>

//################ マクロ定義 ファイルパスと名前 ###############
#define FONT_DIR			R"(.\MY_FONT)"				//フォントファイルの場所

#define FONT_FILE_NAME		R"(\kokubanB.ttf)"			//フォントの名前
//############### マクロ定義 ##################

//*********** フォント名 **************
#define FONT_NAME		"こくばん"					//フォントの正式名称

//*********** フォントサイズ **************
#define DEFAULT_FONTSIZE	128						//デフォルトのフォントサイズ
#define FONTSIZE_MINI		48						//フォントサイズ（ミニ）
#define FONTSIZE_DRAW_RANKING	54					//ランキング描画の時のフォントサイズ

//************* フォントの太さ *****************
#define FONT_BOLD_DEFAULT	5		//デフォルトのフォントの太さ

//################ マクロ定義 エラーメッセージ #################
#define FONT_ERROR_TITLE "FONT_ERROR"						//エラータイトル
#define FONT_ERROR_MSG	"フォントが読み込めませんでした"	//エラーメッセージ

//################ 列挙型 #####################
enum LOAD_FONT_NAME
{
	FONT_NAME_KOKUBAN	//こくばんフォント
};	//読み込んだフォントの種類

enum FONT_HANDLE_TYPE
{
	HANDLE_TYPE_KOKUBAN_NORMALSIZE		//こくばんフォントのノーマルサイズのハンドル
};

using std::vector;
using std::string;

//################ クラスの定義 ##################
class FONT {

private:
	static vector<string> FilePath;			//パス
	static vector<string> LoadFontName;		//読み込んだフォントの名前

	int Handle;								//フォントハンドル
	bool IsCreate;							//フォントハンドルを作成できたか

public:

	FONT(int, int, int, int);		//コンストラクタ
	~FONT();						//デストラクタ

	static bool LoadFont(const char*, const char*, const char*);	//フォントを読み込み
	static bool ReleaseFont();										//読み込んだフォントを開放

	int GetHandle();		//フォントハンドル取得
	bool GetIsCreate();		//フォントハンドルを作成できたか取得

};
