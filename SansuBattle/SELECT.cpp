//SELECT.cpp
//選択肢を管理するクラス

//################# ヘッダファイル読み込み #######################
#include "SELECT.hpp"

//################# クラス定義 ########################

//コンストラクタ
SELECT::SELECT(const char* dir, const char* name,int code)
{

	//メンバー変数初期化
	this->Choise_SelectCode = CHOISE_NONE;		//選んだ選択肢のコードを初期化
	this->IsChoise = false;						//選択したか初期化
	this->DrawX = 0;							//描画開始X位置初期化
	this->DrawY = 0;							//描画開始Y位置初期化
	this->DrawWidth_Range = 0;					//描画幅の範囲初期化
	this->RowNum = 0;							//描画範囲の中で描画できる列の数初期化

	this->SelectImage = new Image(dir, name);					//選択肢の画像を生成
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

//選択したか取得
bool SELECT::GetIsChoise()
{
	return this->IsChoise;
}

//選んだ選択肢のコード番号を取得
bool SELECT::GetChoiseSelectCode()
{
	return Choise_SelectCode;
}

//初期設定
/*
引数：int：描画開始X位置
引数：int：描画開始Y位置
引数：int：描画可能横幅
*/
void SELECT::SetInit(int x, int y, int width)
{
	this->SelectImage->SetInit();	//画像初期設定

	this->DrawX = x;				//描画開始X位置設定
	this->DrawY = y;				//描画開始Y位置設定
	this->DrawWidth_Range = width;	//描画幅の範囲を設定

	//描画範囲の中で描画できる列の数を計算
	while (true)	//無限ループ
	{

		if (x + this->SelectImage->GetWidth() + SELECT_INTERVAL > width)	//描画可能横幅を超えたら
		{
			break;	//ループを抜ける
		}

		x += this->SelectImage->GetWidth() + SELECT_INTERVAL;	//Xの位置をずらす
		++this->RowNum;											//カウントアップ
	}

	return;
}

//初期化
void SELECT::Init()
{
	this->Choise_SelectCode = CHOISE_NONE;			//選んだ選択肢のコードを初期化
	this->IsChoise = false;							//選択したか初期化
	this->NowSelectCode = this->SelectCode.begin();	//現在選んでいる選択肢初期化

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
void SELECT::Draw()
{

	int NowDrawX = this->DrawX, NowDrawY = this->DrawY;		//現在の描画位置
	int row_cnt = 0;					//列数のカウント

	for (int i = this->SelectCode.front(); i <= this->SelectCode.back(); ++i)		//選択肢の画像の数分ループ
	{

		if (row_cnt >= this->RowNum)		//列数が、描画できる範囲を超えたら
		{
			NowDrawX = this->DrawX;											//Xの描画位置を最初の位置へ
			NowDrawY += this->SelectImage->GetHeight() + SELECT_INTERVAL;	//Yの描画位置を、画像の高さ＋間隔分下へずらす
			row_cnt = 0;													//カウントリセット
		}

		++row_cnt;	//カウントアップ

		if (i == *this->NowSelectCode)		//現在選択しているものだったら
		{
			//後で修正
			DrawBox(NowDrawX - 10, NowDrawY - 10, NowDrawX + 10, NowDrawY + 10, GetColor(255, 255, 255), TRUE);		//左上に四角形を描画
			this->SelectImage->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}
		else		//それ以外は
		{
			this->SelectImage->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}

		NowDrawX += this->SelectImage->GetWidth() + SELECT_INTERVAL;	//描画位置をずらす
		this->SelectImage->NextImage();									//次の画像へ

	}

	this->SelectImage->ChengeImageFront();	//描画する画像を先頭の画像に戻す
}

//キー操作
void SELECT::Operation(KeyDown* keydown)
{
	if (keydown->IsKeyDownOne(KEY_INPUT_LEFT))	//左矢印キーを押されたら
	{
		this->Prev();	//前の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RIGHT))	//右矢印キーを押されたら
	{
		this->Next();	//次の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_UP))		//上矢印キーを押されたら
	{
		this->Prev(this->RowNum);		//列の数分、前の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_DOWN))		//下矢印キーを押されたら
	{
		this->Next(this->RowNum);		//列の数分、次の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))	//エンターキーを押されたら
	{
		this->Choise_SelectCode = *this->NowSelectCode;	//現在選択している選択肢を設定
		this->IsChoise = true;							//選択した
	}

	return;

}

//次の選択肢へ
void SELECT::Next()
{

	if (*this->NowSelectCode < this->SelectCode.back())	//最後の選択肢じゃなければ
	{
		++this->NowSelectCode;	//次の選択肢へ
	}

	return;
}

//指定された分、次の選択肢へ
void SELECT::Next(int value)
{
	if (*this->NowSelectCode + value <= this->SelectCode.back())	//最後の選択肢じゃなければ
	{
		this->NowSelectCode += value;	//指定された分、次の選択肢へ
	}

	return;
}

//前の選択肢へ
void SELECT::Prev()
{
	if (*this->NowSelectCode > this->SelectCode.front())		//最初の選択肢じゃなければ
	{
		--this->NowSelectCode;	//前の選択肢へ
	}

	return;
}

//指定された分、前の選択肢へ
void SELECT::Prev(int value)
{
	if (*this->NowSelectCode - value >= this->SelectCode.front())		//最初の選択肢じゃなければ
	{
		this->NowSelectCode -= value;	//指定された分、前の選択肢へ
	}

	return;

}
