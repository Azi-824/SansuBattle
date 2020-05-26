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

	SELECT(const char *,const char *);			//コンストラクタ
	~SELECT();									//デストラクタ

	bool GetIsCreateSelect();					//選択肢を作れたか取得

	void SetInit();								//初期設定

	bool Add(const char*, const char*);			//選択肢を追加

	void Draw(int,int,int);						//選択肢を描画

};
