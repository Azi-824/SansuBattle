//DATA..hpp
//データを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ###################
#include "Global.hpp"

//################### マクロ定義 #####################

//################### クラス定義 #####################
class DATA
{

private:

	int Year;		//年
	int Month;		//月
	int Day;		//日
	int Score;		//スコア

public:

	DATA(int,int,int,int);			//コンストラクタ
	~DATA();						//デストラクタ

	int GetYear();		//年取得
	int GetMonth();		//月取得
	int GetDay();		//日取得
	int GetScore();		//スコア取得

};
