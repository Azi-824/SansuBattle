//Data.cpp
//データを管理するクラス

//################# ヘッダファイル読み込み ##################
#include "Data.hpp"

//################# クラス定義 ###################

//コンストラクタ
Data::Data(int year,int month,int day,int score)
{

	Year = year;		//年
	Month = month;		//月
	Day = day;			//日
	Score = score;		//スコア

	return;
}

//デストラクタ
Data::~Data()
{
	return;
}

//年取得
int Data::GetYear()
{
	return Year;
}

//月取得
int Data::GetMonth()
{
	return Month;
}

//日取得
int Data::GetDay()
{
	return Day;
}

//スコア取得
int Data::GetScore()
{
	return Score;
}
