//SELECT.hpp
//選択肢を管理するクラス

#pragma once

//#################### ヘッダファイル読み込み #####################
#include "DxLib.h"
#include "IMAGE.hpp"
#include <vector>

//##################### マクロ定義 ######################
#define SELECT_IMG_DIR			R"(.\MY_IMG\Select)"		//選択肢の画像ディレクトリ

#define IMG_NAME_SELECT_DAMMY1	R"(\dammy01.png)"			//選択肢のダミー画像1
#define IMG_NAME_SELECT_DAMMY2	R"(\dammy02.png)"			//選択肢のダミー画像2
#define IMG_NAME_SELECT_DAMMY3	R"(\dammy03.png)"			//選択肢のダミー画像3
#define IMG_NAME_SELECT_DAMMY4	R"(\dammy04.png)"			//選択肢のダミー画像4
#define IMG_NAME_SELECT_DAMMY5	R"(\dammy05.png)"			//選択肢のダミー画像5
#define IMG_NAME_SELECT_DAMMY6	R"(\dammy06.png)"			//選択肢のダミー画像6

#define SELECT_LEVEL_DRAW_X		20	//難易度の選択肢の描画開始X位置
#define SELECT_LEVEL_DRAW_Y		20	//難易度の選択肢の描画開始Y位置

#define SELECT_INTERVAL		20		//選択肢の間隔

//##################### 列挙型 #######################
enum CODE_SELECT_LEVEL
{
	CODE_LEVEL_SUM,					//難易度、和（足し算）
	CODE_LEVEL_DIFFERENCE,			//難易度、差（引き算）
	CODE_LEVEL_PRODUCT,				//難易度、積（掛け算）
	CODE_LEVEL_DEALER,				//難易度、商（割り算）
	CODE_LEVEL_SUM_DEFFERENCE,		//難易度、和差（足し算、引き算）
	CODE_LEVEL_PRODUCT_DEALER,		//難易度、積商（掛け算、割り算）
};

//##################### クラス定義 ######################
class SELECT
{

private:

	IMAGE* SelectImage;							//選択肢の画像

	std::vector<int> SelectCode;				//選択肢のコード番号

	int Choise_SelectCode;						//選んだ選択肢のコード番号

	bool IsCreateSelect;						//選択肢を作れたか
	bool IsChoise;								//選択したか

public:

	SELECT(const char *,const char *,int);		//コンストラクタ
	~SELECT();									//デストラクタ

	bool GetIsCreateSelect();					//選択肢を作れたか取得

	void SetInit();								//初期設定

	bool Add(const char*, const char*,int);		//選択肢を追加

	void Draw(int,int,int);						//選択肢を描画

};
