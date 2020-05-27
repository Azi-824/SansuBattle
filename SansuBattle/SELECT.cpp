//SELECT.cpp
//選択肢を管理するクラス

//################# ヘッダファイル読み込み #######################
#include "SELECT.hpp"

//################# クラス定義 ########################

//コンストラクタ
SELECT::SELECT(const char* dir, const char* name,int code)
{

	//メンバー変数初期化
	this->Choise_SelectCode = -1;		//選んだ選択肢のコードを初期化
	this->IsChoise = false;				//選択したか初期化

	this->SelectImage = new IMAGE(dir, name);					//選択肢の画像を生成
	this->IsCreateSelect = this->SelectImage->GetIsLoad();		//画像を読み込めたか設定
	this->SelectCode.push_back(code);							//選択肢のコード番号を設定
	this->NowSelectCode = this->SelectCode.begin();				//現在選択しているコード番号を最初の選択肢に設定

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

//初期設定
void SELECT::SetInit()
{
	this->SelectImage->SetInit();	//画像初期設定
	return;
}

//選択肢を追加
bool SELECT::Add(const char* dir, const char* name,int code)
{
	this->IsCreateSelect = this->SelectImage->AddImage(dir, name);		//画像を追加
	this->SelectCode.push_back(code);									//選択肢コードを設定
	this->NowSelectCode = this->SelectCode.begin();						//現在選択しているコード番号を最初の選択肢に設定
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

	int NowDrawX = x, NowDrawY = y;		//現在の描画位置

	for (int i = this->SelectCode.front(); i <= this->SelectCode.back(); ++i)		//選択肢の画像の数分ループ
	{
		if (NowDrawX + this->SelectImage->GetWidth() + SELECT_INTERVAL > width)	//描画可能横幅を超えたら
		{
			NowDrawX = x;	//Xの描画位置を最初の位置へ
			NowDrawY = y + this->SelectImage->GetHeight() + SELECT_INTERVAL;	//Yの描画位置を、画像の高さ＋間隔分下へずらす
		}

		if (i == *this->NowSelectCode)		//現在選択しているものだったら
		{
			DrawBox(NowDrawX - 10, NowDrawY - 10, NowDrawX + 10, NowDrawY + 10, GetColor(255, 255, 255), TRUE);
			this->SelectImage->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}
		else		//それ以外は
		{
			this->SelectImage->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}

		NowDrawX += this->SelectImage->GetWidth() + SELECT_INTERVAL;	//描画位置をずらす
		this->SelectImage->NextImage();					//次の画像へ

	}

	this->SelectImage->ChengeImageFront();	//描画する画像を先頭の画像に戻す
}
