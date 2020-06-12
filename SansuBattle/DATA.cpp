//DATA.cpp
//データを管理するクラス

//################# ヘッダファイル読み込み ##################
#include "DATA.hpp"

//################# クラス定義 ###################

//コンストラクタ
DATA::DATA(int year,int month,int day,int score)
{

	Year = year;		//年
	Month = month;		//月
	Day = day;			//日
	Score = score;		//スコア

	return;
}

//デストラクタ
DATA::~DATA()
{
	return;
}

//年取得
int DATA::GetYear()
{
	return Year;
}

//月取得
int DATA::GetMonth()
{
	return Month;
}

//日取得
int DATA::GetDay()
{
	return Day;
}

//スコア取得
int DATA::GetScore()
{
	return Score;
}
