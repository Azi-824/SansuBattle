//CalcInfo.hpp
//問題の計算に必要な情報を管理するクラス

#pragma once

//############# ヘッダファイル読み込み ##############
#include "Global.hpp"
#include <vector>

//############# マクロ定義 ###############


using std::vector;

//############# クラス定義 ###############
class CalcInfo
{
private:

	vector<int>	Min;		//最小値
	vector<int> Max;		//最大値
	vector<int>	Value_Num;	//値の数

public:

	CalcInfo(vector<int>, vector<int>, vector<int>);	//コンストラクタ
	~CalcInfo();										//デストラクタ

	int GetMin(int);		//最小値取得
	int GetMax(int);		//最大値取得
	int GetValueNum(int);	//数取得

};
