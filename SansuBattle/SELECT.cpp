//Select.cpp
//選択の処理

//############# ヘッダファイル読み込み ###############
#include "Select.hpp"

//############# クラス定義 ################

//コンストラクタ
Select::Select()
{
	//画像関係
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_SELECT)) { IsLoad = false; return; }	//背景画像読み込み

	//BGM
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_SELECT)) { IsLoad = false; return; }	//BGM読み込み

	//**************************** ボタン ***************************
	//ボタンの画像を読み込み
	//モード
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_IMG_NAME));
	for (auto i : mode_img) { 
		if (!i->GetIsLoad())
		{
			IsLoad = false;
			return;
		}
	}	//読み込み成功したか

	//レベル
	mode_img.push_back(new Image(BT_IMG_DIR, BT_EASY_IMG_NAME));
	for (auto i : level_img) {
		if (!i->GetIsLoad())
		{
			IsLoad = false;
			return;
		}
	}	//読み込み成功したか

	//ボタン作成
	for (auto i : mode_img){ mode.push_back(new Button(i)); }		//モード
	for (auto i : level_img) { level.push_back(new Button(i)); }	//レベル

}

//デストラクタ
Select::~Select()
{
	
	for (auto b : mode) { delete b; }
	//vectorの開放
	vector<Button*> v;
	v.swap(mode);

	for (auto b : level) { delete b; }
	//vectorの開放
	vector<Button*> v2;
	v2.swap(level);

	//ボタンの画像は、ボタンの破棄と一緒に破棄されるため
	//vectorの開放のみ行う
	vector<Image*> v3;
	v3.swap(level_img);
	vector<Image*> v4;
	v4.swap(level_img);


}

//初期設定
void Select::SetInit()
{
	back->SetInit();	//背景画像初期設定
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM初期設定

	//**************** ボタン ******************
	for (auto b : mode) { b->SetInit(20, 20); }
	for (auto b : level) { b->SetInit(20, 20); }
}


//選択画面の処理
void Select::Run()
{

	bgm->Play();	//BGMを流す
	back->Draw(GAME_LEFT, GAME_TOP);//背景描画

	for (auto b : mode)
	{
		b->Draw();
	}

	for (auto b : level)
	{
		b->Draw();
	}

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		bgm->Stop();			//BGMを止める
		NowScene = SCENE_PLAY;	//プレイ画面へ
	}


}