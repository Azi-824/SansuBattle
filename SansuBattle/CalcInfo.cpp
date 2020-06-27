//CalcInfo.cpp
//問題の計算に必要な情報を管理するクラス

//############## ヘッダファイル読み込み ###############
#include "CalcInfo.hpp"

//############## クラス定義 ################

//コンストラクタ
CalcInfo::CalcInfo(vector<int> min, vector<int>max, vector<int>value_num)
{
	Min = min;				//最小値設定
	Max = max;				//最大値設定
	Value_Num = value_num;	//数設定
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
	Value_Num.swap(v3);

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

//数取得
int CalcInfo::GetValueNum(int level)
{
	return Value_Num.at(level);
}
