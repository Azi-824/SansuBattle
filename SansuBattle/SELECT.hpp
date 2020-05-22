//SELECT.hpp
//選択肢を管理するクラス

#pragma once

//#################### ヘッダファイル読み込み #####################
#include "DxLib.h"
#include "IMAGE.hpp"
#include <vector>

//##################### マクロ定義 ######################

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

	bool Add(const char*, const char*);			//選択肢を追加

};
