//CalcInfo.cpp
//問題の計算に必要な情報を管理するクラス

//############## ヘッダファイル読み込み ###############
#include "CalcInfo.hpp"

//############## クラス定義 ################

//コンストラクタ
CalcInfo::CalcInfo(vector<int> min, vector<int>max, vector<int>calc_num)
{
	Min = min;				//最小値設定
	Max = max;				//最大値設定
	CalcNum = calc_num;		//計算回数設定
}

//デストラクタ
CalcInfo::~CalcInfo()
{
	//vectorの解放
	vector<int> v;
	Min.swap(v);
	vector<int> v2;
	Max.swap(v2);
	vector<int> v3;
	CalcNum.swap(v3);

}

//最小値取得
int CalcInfo::GetMin(int level)
{
	return Min.at(level);
}

//最大値取得
int CalcInfo::GetMax(int level)
{
	return Max.at(level);
}

//計算回数取得
int CalcInfo::GetCalcNum(int level)
{
	return CalcNum.at(level);
}
