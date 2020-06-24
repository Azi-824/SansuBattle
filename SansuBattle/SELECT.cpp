//Select.cpp
//選択肢を管理するクラス

//################# ヘッダファイル読み込み #######################
#include "Select.hpp"

//################# クラス定義 ########################

//インスタンスを生成
vector<Music*> Select::Key_se;	//キーボードの効果音

//コンストラクタ
Select::Select(const char* dir, const char* name,int code)
{

	//メンバー変数初期化
	Choise_SelectCode = CHOISE_NONE;	//選んだ選択肢のコードを初期化
	IsChoise = false;					//選択したか初期化
	DrawX = 0;							//描画開始X位置初期化
	DrawY = 0;							//描画開始Y位置初期化
	DrawWidth_Range = 0;				//描画幅の範囲初期化
	RowNum = 0;							//描画範囲の中で描画できる列の数初期化
	Interval_Side = 0;					//選択肢の間隔(横)初期化
	Interval_Vertical = 0;				//選択肢の間隔(縦)初期化
	//領域初期化
	rect.left = 0;
	rect.top = 0;
	rect.right = 0;
	rect.bottom = 0;

	if (Key_se.empty())	//キー操作の効果音が生成されていなかったら
	{
		Key_se.push_back(new Music(MUSIC_DIR_SE, SE_NAME_KETTEI));	//決定の効果音を追加
		Key_se.at((int)SE_KEY_KETTEI)->SetInit(DX_PLAYTYPE_BACK, 30);	//初期設定
	}

	SelectImage = new Image(dir, name);				//選択肢の画像を生成
	IsCreateSelect = SelectImage->GetIsLoad();		//画像を読み込めたか設定
	SelectCode.push_back(code);						//選択肢のコード番号を設定
	NowSelectCode = SelectCode.begin();				//現在選択しているコード番号を最初の選択肢に設定
}

//デストラクタ
Select::~Select()
{
	//vectorのメモリ解放を行う
	vector<int> v;				//空のvectorを作成する
	SelectCode.swap(v);			//空と中身を入れ替える

}

//選択肢を作れたか取得
bool Select::GetIsCreateSelect()
{
	return IsCreateSelect;
}

//選択したか取得
bool Select::GetIsChoise()
{
	return IsChoise;
}

//選んだ選択肢のコード番号を取得
int Select::GetChoiseSelectCode()
{
	return Choise_SelectCode;
}

//初期設定
/*
引数：int：描画開始X位置
引数：int：描画開始Y位置
引数：int：描画可能横幅
引数：int：選択肢の間隔(横)
引数：int：選択肢の間隔(縦)、デフォルトは0
*/
void Select::SetInit(int x, int y, int width,int interval_side,int interval_vertical)
{
	SelectImage->SetInit();	//画像初期設定

	DrawX = x;				//描画開始X位置設定
	DrawY = y;				//描画開始Y位置設定
	DrawWidth_Range = width;//描画幅の範囲を設定
	Interval_Side = interval_side;	//選択肢の間隔(横)を設定
	Interval_Vertical = interval_vertical;	//選択肢の間隔(縦)を設定

	//描画範囲の中で描画できる列の数を計算
	while (true)	//無限ループ
	{

		if (x + SelectImage->GetWidth() + Interval_Side > width)	//描画可能横幅を超えたら
		{
			break;	//ループを抜ける
		}

		x += SelectImage->GetWidth() + Interval_Side;			//Xの位置をずらす
		++RowNum;											//カウントアップ
	}

	return;
}

//初期化
void Select::Init()
{
	Choise_SelectCode = CHOISE_NONE;			//選んだ選択肢のコードを初期化
	IsChoise = false;							//選択したか初期化
	NowSelectCode = SelectCode.begin();			//現在選んでいる選択肢初期化

	return;
}

//選択肢を追加
bool Select::Add(const char* dir, const char* name,int code)
{
	IsCreateSelect = SelectImage->AddImage(dir, name);		//画像を追加
	SelectCode.push_back(code);									//選択肢コードを設定
	NowSelectCode = SelectCode.begin();						//現在選択しているコード番号を最初の選択肢に設定
	return IsCreateSelect;
}

//描画
void Select::Draw()
{

	int NowDrawX = DrawX, NowDrawY = DrawY;		//現在の描画位置
	int row_cnt = 0;					//列数のカウント

	for (int i = SelectCode.front(); i <= SelectCode.back(); ++i)		//選択肢の画像の数分ループ
	{

		if (row_cnt >= RowNum)		//列数が、描画できる範囲を超えたら
		{
			NowDrawX = DrawX;											//Xの描画位置を最初の位置へ
			NowDrawY += SelectImage->GetHeight() + Interval_Vertical;	//Yの描画位置を、画像の高さ＋間隔分下へずらす
			row_cnt = 0;												//カウントリセット
		}

		++row_cnt;	//カウントアップ

		if (i == *NowSelectCode)		//現在選択しているものだったら
		{
			//領域設定
			rect.left = NowDrawX - RECT_EXPANSION_VALUE;								//左上X
			rect.top = NowDrawY - RECT_EXPANSION_VALUE;									//左上Y
			rect.right = NowDrawX + SelectImage->GetWidth() + RECT_EXPANSION_VALUE;		//右下X
			rect.bottom = NowDrawY + SelectImage->GetHeight() + RECT_EXPANSION_VALUE;	//右下Y

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, RECT_TOUKA_VALUE * TOUKA_MAX_VALUE);	//透過させる
			DrawBox(rect.left, rect.top, rect.right, rect.bottom, COLOR_WHITE, TRUE);	//薄い四角形を描画
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//透過をやめる

			SelectImage->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}
		else		//それ以外は
		{
			SelectImage->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}

		NowDrawX += SelectImage->GetWidth() + Interval_Side;			//描画位置をずらす
		SelectImage->NextImage();									//次の画像へ

	}

	SelectImage->ChengeImageFront();	//描画する画像を先頭の画像に戻す
}

//キー操作
void Select::Operation(KeyDown* keydown)
{
	if (keydown->IsKeyDownOne(KEY_INPUT_LEFT))	//左矢印キーを押されたら
	{
		Prev();	//前の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RIGHT))	//右矢印キーを押されたら
	{
		Next();	//次の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_UP))		//上矢印キーを押されたら
	{
		Prev(RowNum);		//列の数分、前の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_DOWN))		//下矢印キーを押されたら
	{
		Next(RowNum);		//列の数分、次の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))	//エンターキーを押されたら
	{
		Choise_SelectCode = *NowSelectCode;	//現在選択している選択肢を設定
		IsChoise = true;							//選択した
		Key_se.at((int)SE_KEY_KETTEI)->Play(false);		//決定の効果音を鳴らす
	}

	return;

}

//次の選択肢へ
void Select::Next()
{

	if (*NowSelectCode < SelectCode.back())	//最後の選択肢じゃなければ
	{
		++NowSelectCode;	//次の選択肢へ
	}

	return;
}

//指定された分、次の選択肢へ
void Select::Next(int value)
{
	if (*NowSelectCode + value <= SelectCode.back())	//最後の選択肢じゃなければ
	{
		NowSelectCode += value;	//指定された分、次の選択肢へ
	}

	return;
}

//前の選択肢へ
void Select::Prev()
{
	if (*NowSelectCode > SelectCode.front())		//最初の選択肢じゃなければ
	{
		--NowSelectCode;	//前の選択肢へ
	}

	return;
}

//指定された分、前の選択肢へ
void Select::Prev(int value)
{
	if (*NowSelectCode - value >= SelectCode.front())		//最初の選択肢じゃなければ
	{
		NowSelectCode -= value;	//指定された分、前の選択肢へ
	}

	return;

}
