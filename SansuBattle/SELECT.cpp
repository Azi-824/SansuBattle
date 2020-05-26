//SELECT.cpp
//選択肢を管理するクラス

//################# ヘッダファイル読み込み #######################
#include "SELECT.hpp"

//################# クラス定義 ########################

//コンストラクタ
SELECT::SELECT(const char* dir, const char* name)
{

	//メンバー変数初期化
	this->Choise_SelectCode = -1;		//選んだ選択肢のコードを初期化
	this->IsChoise = false;				//選択したか初期化

	this->SelectImage = new IMAGE(dir, name);					//選択肢の画像を生成
	this->IsCreateSelect = this->SelectImage->GetIsLoad();		//画像を読み込めたか設定
	this->SelectCode.push_back(this->SelectCode.size());		//選択肢のコード番号を設定

	return;
}

//デストラクタ
SELECT::~SELECT()
{
	//vectorのメモリ解放を行う
	std::vector<int> v;				//空のvectorを作成する
	this->SelectCode.swap(v);		//空と中身を入れ替える

	return;

}

//選択肢を作れたか取得
bool SELECT::GetIsCreateSelect()
{
	return this->IsCreateSelect;
}

//選択肢を追加
bool SELECT::Add(const char* dir, const char* name)
{
	this->IsCreateSelect = this->SelectImage->AddImage(dir, name);		//画像を追加
	this->SelectCode.push_back(this->SelectCode.size());				//選択肢コードを設定
	return this->IsCreateSelect;
}

//描画
/*
引数：int：描画開始X位置
引数：int：描画開始Y位置
引数：int：描画可能横幅
*/
void SELECT::Draw(int x, int y, int width)
{

}
