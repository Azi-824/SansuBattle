//GAMEMANEGER.cpp
//ゲームのシステムを管理するクラス

//############### ヘッダファイル読み込み ################
#include "GAMEMANEGER.hpp"

//############### クラス定義 ################

//コンストラクタ
GAMEMANEGER::GAMEMANEGER()
{
	//オブジェクトの生成
	this->fps = new FPS(GAME_FPS_SPEED);	//FPSクラスのオブジェクトを生成
	this->keydown = new KEYDOWN();			//KEYDOWNクラスのオブジェクトを生成

	//メンバー変数初期化
	this->NowScene = (int)SCENE_LOAD;		//最初のシーンは、ロード画面
	this->IsLoad = false;					//読み込み、未完了

	return;

}

//デストラクタ
GAMEMANEGER::~GAMEMANEGER()
{
	//オブジェクトの破棄
	delete this->fps;			//fps破棄
	delete this->keydown;		//keydown破棄
	delete this->back;			//back破棄
	delete this->level_select;	//level_select破棄

	return;

}

//ゲーム内で使用するデータの読み込み処理
/*
戻り値：true：正常
戻り値：false：エラー、強制終了
*/
bool GAMEMANEGER::Load()
{
	//画像関係
	this->back = new IMAGE(IMG_DIR_BACK, IMG_NAME_TITLE);		//背景画像を管理するオブジェクトを生成
	if (this->back->GetIsLoad() == false) { return false; }		//読み込み失敗

	//選択肢関係
	this->level_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY1);		//難易度の選択肢を管理するオブジェクトを生成
	if (this->level_select->GetIsCreateSelect() == false) { return false; }			//読み込み失敗
	//選択肢の追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY2) == false) { return false; }		//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY3) == false) { return false; }		//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY4) == false) { return false; }		//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY5) == false) { return false; }		//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY6) == false) { return false; }		//ダミー画像追加

	return true;	//読み込み成功
}

//ゲームのメインループ
/*
戻り値：true：正常
戻り値：false：エラー、強制終了
*/
bool GAMEMANEGER::GameMainLoop()
{
	if (ProcessMessage() != 0) { return false; }	//メッセージ処理の結果がエラーのとき、強制終了

	if (ClearDrawScreen() != 0) { return false; }	//画面を消去できなかったとき、強制終了

	this->keydown->KeyDownUpdate();	//キーの入力状態を更新する

	this->fps->Update();		//FPSの処理[更新]

	//▼▼▼▼▼ゲームのシーンここから▼▼▼▼▼

	this->ProcesScene();		//各シーンの処理

	//▲▲▲▲▲ゲームのシーンここまで▲▲▲▲▲

	this->fps->Draw(0, 0);		//FPS描画

	ScreenFlip();				//モニタのリフレッシュレートの速さで裏画面を再描画

	this->fps->Wait();			//FPSの処理[待つ]

	return true;				//正常

}

//各シーンの処理
void GAMEMANEGER::ProcesScene()
{
	switch (this->NowScene)		//現在のシーンの描画処理を実行
	{

	case (int)SCENE_LOAD:	//ロード画面のとき

		this->Draw_Scene_Load();	//ロード画面の描画処理

		this->Scene_Load();			//ロード画面の処理

		break;				//ロード画面のときここまで

	case (int)SCENE_TITLE:	//タイトル画面のとき

		this->Draw_Scene_Title();	//描画

		this->Scene_Title();		//処理

		break;				//タイトル画面のときここまで

	case (int)SCENE_CHOISELEVEL:	//難易度選択画面のとき

		this->Draw_Scene_ChoiseLevel();	//描画

		this->Scene_ChoiseLevel();		//処理

		break;				//難易度選択画面のときここまで

	case (int)SCENE_CHOISESTAGE:	//ステージ選択画面のとき

		this->Draw_Scene_ChoiseStage();	//描画

		this->Scene_ChoiseStage();		//処理

		break;				//ステージ選択画面のときここまで

	case (int)SCENE_PLAY:	//プレイ画面のとき

		this->Draw_Scene_Play();	//描画

		this->Scene_Play();		//処理

		break;				//プレイ画面のときここまで

	case (int)SCENE_DRAWSCORE:	//スコア表示画面のとき

		this->Draw_SceneDrawScore();	//描画

		this->Scene_DrawScore();		//処理

		break;				//スコア表示画面のときここまで

	case (int)SCENE_END:	//エンド画面のとき

		this->Draw_Scene_End();	//描画

		this->Scene_End();		//処理

		break;				//エンド画面のときここまで

	default:
		break;
	}

	return;	

}

//***************************** シーン毎の処理 ********************************
//ロード画面の処理
void GAMEMANEGER::Scene_Load()
{
	if (this->IsLoad)	//読み込みが完了していたら
	{
		if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
		{
			this->NowScene = (int)SCENE_TITLE;	//タイトル画面へ
		}
	}

	if (GetASyncLoadNum() == 0)	//非同期で読み込んでいる処理が終わったら
	{

		SetUseASyncLoadFlag(FALSE);	//同期読み込みに設定

		this->IsLoad = true;		//読み込み完了
	}

	return;		
}

//ロード画面の描画処理
void GAMEMANEGER::Draw_Scene_Load()
{

	if (IsLoad)	//読み込みが完了したら
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, PUSH_TEXT, COLOR_WHITE);	//プッシュ、のテキストを描画
	}
	else		//完了していなければ
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, LOAD_TEXT, COLOR_WHITE);	//読み込み中のテキストを描画
	}

	return;
}

//タイトル画面の処理
void GAMEMANEGER::Scene_Title()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		this->NowScene = (int)SCENE_CHOISELEVEL;	//難易度選択画面へ
	}

	return;
}

//タイトル画面の描画処理
void GAMEMANEGER::Draw_Scene_Title()
{

	this->back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

//難易度選択画面の処理
void GAMEMANEGER::Scene_ChoiseLevel()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		this->NowScene = (int)SCENE_CHOISESTAGE;	//ステージ選択画面へ
	}

	return;
}

//難易度選択画面の描画処理
void GAMEMANEGER::Draw_Scene_ChoiseLevel()
{

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, CHOISELEVEL_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

//ステージ選択画面の処理
void GAMEMANEGER::Scene_ChoiseStage()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		this->NowScene = (int)SCENE_PLAY;	//プレイ画面へ
	}

	return;
}

//ステージ選択画面の描画処理
void GAMEMANEGER::Draw_Scene_ChoiseStage()
{

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, CHOISESTAGE_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

//プレイ画面の処理
void GAMEMANEGER::Scene_Play()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		this->NowScene = (int)SCENE_DRAWSCORE;	//スコア表示画面へ
	}

	return;
}

//プレイ画面の描画処理
void GAMEMANEGER::Draw_Scene_Play()
{

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

//スコア表示画面の処理
void GAMEMANEGER::Scene_DrawScore()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		this->NowScene = (int)SCENE_END;	//エンド画面へ
	}

	return;
}

//スコア表示画面の描画処理
void GAMEMANEGER::Draw_SceneDrawScore()
{

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, DRAWSCORE_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}


//エンド画面の処理
void GAMEMANEGER::Scene_End()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		this->NowScene = (int)SCENE_TITLE;	//タイトル画面へ
	}

	return;
}

//エンド画面の描画処理
void GAMEMANEGER::Draw_Scene_End()
{

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

