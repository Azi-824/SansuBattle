//Time.cpp
//時間を管理するクラス

//################## ヘッダファイル読み込み ################
#include "Time.hpp"

//################## クラス定義 ##################

//コンストラクタ
Time::Time()
{
	//メンバー変数初期化
	this->StartTime = 0;		//計測開始時間初期化
	this->ElapsedTime = 0;		//経過時間初期化
	this->NowLimitTime = 0;		//残りの制限時間初期化

	return;
}

//デストラクタ
Time::~Time()
{
	return;
}

//計測開始
void Time::SetTime()
{
	//ミリ秒単位で取得するため、1/1000倍して、秒単位に変換する
	this->StartTime = GetNowCount() / 1000;	//計測開始時間設定
	return;
}

//経過時間更新
void Time::UpdateElpasedTime()
{
	//ミリ秒単位で取得するため、1/1000倍して、秒単位に変換する
	this->ElapsedTime = (GetNowCount() / 1000) - this->StartTime;	//経過時間を更新
	return;
}

//制限時間更新
//引数：int：制限時間
void Time::UpdateLimitTime(int limit_time)
{
	this->UpdateElpasedTime();	//経過時間を更新
	this->NowLimitTime = limit_time - this->ElapsedTime;	//残りの制限時間を更新
	return;
}

//経過時間描画
//引数：int：描画X位置
//引数：int：描画Y位置
void Time::DrawElapsedTime(int x, int y)
{
	this->UpdateElpasedTime();	//経過時間を更新
	DrawFormatString(x, y, COLOR_WHITE, "%d", this->ElapsedTime);	//経過時間を描画
	return;
}

//制限時間描画
//引数：int：描画X位置
//引数：int：描画Y位置
//引数：int：制限時間
void Time::DrawLimitTime(int x, int y,int limit_time)
{
	this->UpdateLimitTime(limit_time);	//残りの制限時間更新
	DrawFormatString(x, y, COLOR_WHITE, "%d", this->NowLimitTime);	//制限時間を描画
	return;
}
