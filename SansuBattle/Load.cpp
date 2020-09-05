//Load.cpp
//ロード画面のクラス

//############## ヘッダファイル読み込み #################
#include "Load.hpp"

//############## クラス定義 ################

//コンストラクタ
Load::Load()
{
	//メンバー初期化
	IsGameStart = false;	//ゲームスタートできるか

	IsLoad = true;

}

//デストラクタ
Load::~Load(){}

//初期設定
void Load::SetInit(){}

//読み込み画面の処理
void Load::Run()
{
	if (IsGameStart)	//ゲームスタートできるなら
	{
		if (Mouse::OnLeftClick())	//左クリックされたら
		{
			NowScene = SCENE_TITLE;	//タイトル画面へ
		}

	}

	if (GetASyncLoadNum() == 0)	//非同期で読み込んでいる処理が終わったら
	{

		SetUseASyncLoadFlag(FALSE);	//同期読み込みに設定

		IsGameStart = true;		//ゲームスタートできる
	}

	DrawStringToHandle(TEXT_DISCRIPTION_X, TEXT_DISCRIPTION_Y, TEXT_DISCRIPTION, GetColor(255, 255, 255), Font::GetNowHandle());

}
