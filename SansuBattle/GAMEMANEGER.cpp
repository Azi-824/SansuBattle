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
	delete this->stage_select;	//stage_select破棄
	delete this->player;		//player破棄
	delete this->enemy;			//enemy破棄
	delete this->q_add;			//q_add破棄
	delete this->font;			//font破棄
	delete this->gamelimittime;	//gamelimittime破棄

	return;

}

//ゲーム内で使用するデータの読み込み処理
/*
戻り値：true：正常
戻り値：false：エラー、強制終了
*/
bool GAMEMANEGER::Load()
{

	//フォント関係
	this->font = new FONT(FONT_DIR, FONT_FILE_NAME, FONT_NAME);		//フォントを管理するオブジェクトを生成
	if (this->font->GetIsLoad() == false) { return false; }			//読み込み失敗

	//時間関係
	this->gamelimittime = new Time();		//ゲームの制限時間を管理するオブジェクトを生成

	//画像関係
	//背景画像
	this->back = new IMAGE(IMG_DIR_BACK, IMG_NAME_TITLE);		//背景画像を管理するオブジェクトを生成
	if (this->back->GetIsLoad() == false) { return false; }		//読み込み失敗
	if (this->back->AddImage(IMG_DIR_BACK, IMG_NAME_PLAY) == false) { return false; }	//プレイ画面の背景画像を追加
	if (this->back->AddImage(IMG_DIR_BACK, IMG_NAME_DAMMY) == false) { return false; }	//ダミー画像を追加

	//選択肢関係
	//難易度の選択肢
	this->level_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY1, CODE_LEVEL_SUM);		//難易度の選択肢を管理するオブジェクトを生成
	if (this->level_select->GetIsCreateSelect() == false) { return false; }			//読み込み失敗
	//選択肢の追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY2, CODE_LEVEL_DIFFERENCE) == false) { return false; }		//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY3, CODE_LEVEL_PRODUCT) == false) { return false; }			//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY4, CODE_LEVEL_DEALER) == false) { return false; }			//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY5, CODE_LEVEL_SUM_DEFFERENCE) == false) { return false; }	//ダミー画像追加
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY6, CODE_LEVEL_PRODUCT_DEALER) == false) { return false; }	//ダミー画像追加

	//ステージの選択肢
	this->stage_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY01, CODE_STAGE_EASY);		//ステージの選択肢を管理するオブジェクトを生成
	if (this->stage_select->GetIsCreateSelect() == false) { return false; }			//読み込み失敗
	//選択肢の追加
	if (this->stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY02, CODE_STAGE_NORMAL) == false) { return false; }	//ダミー画像追加
	if (this->stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY03, CODE_STAGE_HARD) == false) { return false; }	//ダミー画像追加


	//プレイヤー関係
	this->player = new PLAYER(IMG_DIR_PLAYER, IMG_NAME_HP);		//プレイヤーを管理するオブジェクトを生成
	if (this->player->GetIsLoad() == false) { return false; }	//読み込み失敗

	//敵関係
	this->enemy = new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY);		//敵を管理するオブジェクトを生成
	if (this->enemy->GetIsLoad() == false) { return false; }	//読み込み失敗

	//問題関係
	//足し算
	this->q_add = new Q_ADD();			//足し算の問題を管理するオブジェクトを生成

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

	//this->fps->Draw(0, 0);		//FPS描画

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

		this->Scene_Load();			//ロード画面の処理

		this->Draw_Scene_Load();	//ロード画面の描画処理

		break;				//ロード画面のときここまで

	case (int)SCENE_TITLE:	//タイトル画面のとき

		this->Scene_Title();		//処理

		this->Draw_Scene_Title();	//描画

		break;				//タイトル画面のときここまで

	case (int)SCENE_CHOISELEVEL:	//難易度選択画面のとき

		this->Scene_ChoiseLevel();		//処理

		this->Draw_Scene_ChoiseLevel();	//描画

		break;				//難易度選択画面のときここまで

	case (int)SCENE_CHOISESTAGE:	//ステージ選択画面のとき

		this->Scene_ChoiseStage();		//処理

		this->Draw_Scene_ChoiseStage();	//描画

		break;				//ステージ選択画面のときここまで

	case (int)SCENE_PLAY:	//プレイ画面のとき

		this->Scene_Play();			//処理

		this->Draw_Scene_Play();	//描画

		break;				//プレイ画面のときここまで

	case (int)SCENE_DRAWSCORE:	//スコア表示画面のとき

		this->Scene_DrawScore();		//処理

		this->Draw_SceneDrawScore();	//描画

		break;				//スコア表示画面のときここまで

	case (int)SCENE_END:	//エンド画面のとき

		this->Scene_End();		//処理

		this->Draw_Scene_End();	//描画

		break;				//エンド画面のときここまで

	default:
		break;
	}

	return;	

}

//初期設定
void GAMEMANEGER::SetInit()
{
	this->back->SetInit();			//画像初期設定
	this->level_select->SetInit(SELECT_LEVEL_DRAW_X, SELECT_LEVEL_DRAW_Y, GAME_WIDTH);	//難易度の選択肢初期設定
	this->stage_select->SetInit(SELECT_STAGE_DRAW_X, SELECT_STAGE_DRAW_Y, GAME_WIDTH);	//ステージの選択肢初期設定
	this->player->SetInit(PLAYER_HP_DRAW_X, PLAYER_HP_DRAW_Y);							//プレイヤー初期設定
	this->enemy->SetInit(ENEMY_DRAW_X, ENEMY_DRAW_Y);									//敵の初期設定

	this->q_add->CreateQuestion();	//足し算の問題を生成

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
	else		//読み込みが完了していなかったら
	{
		if (GetASyncLoadNum() == 0)	//非同期で読み込んでいる処理が終わったら
		{

			SetUseASyncLoadFlag(FALSE);	//同期読み込みに設定

			this->SetInit();			//初期設定

			this->IsLoad = true;		//読み込み完了
		}

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

	this->back->ChengeImage((int)TITLE_BACK);	//背景画像を変更

	this->level_select->Init();	//難易度の選択肢初期化
	this->stage_select->Init();	//ステージの選択肢初期化

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

	this->level_select->Operation(keydown);			//選択肢キー操作

	if (this->level_select->GetIsChoise())			//選択したら
	{
		this->NowScene = (int)SCENE_CHOISESTAGE;	//ステージ選択画面へ
	}

	return;
}

//難易度選択画面の描画処理
void GAMEMANEGER::Draw_Scene_ChoiseLevel()
{

	this->level_select->Draw();	//難易度の選択肢描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, CHOISELEVEL_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

//ステージ選択画面の処理
void GAMEMANEGER::Scene_ChoiseStage()
{

	this->stage_select->Operation(keydown);		//選択肢キー操作

	if (this->stage_select->GetIsChoise())		//選択したら
	{
		this->gamelimittime->SetTime();			//制限時間の計測開始
		this->NowScene = (int)SCENE_PLAY;		//プレイ画面へ
	}

	return;
}

//ステージ選択画面の描画処理
void GAMEMANEGER::Draw_Scene_ChoiseStage()
{

	this->stage_select->Draw();		//ステージ選択肢描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, CHOISESTAGE_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

//プレイ画面の処理
void GAMEMANEGER::Scene_Play()
{

	this->back->ChengeImage((int)PLAY_BACK);	//背景画像を変更

	this->gamelimittime->UpdateElpasedTime();	//経過時間の更新

	if (!this->q_add->CheckInputKey(this->keydown))		//キー入力中だったら
	{
		//ゲームの処理（時間経過等）
	}
	else							//キー入力が終了したら
	{
		if (this->q_add->JudgAnser())	//プレイヤーの回答が正解だったら
		{
			this->NowScene = (int)SCENE_DRAWSCORE;	//スコア表示画面へ
		}

	}

	return;
}

//プレイ画面の描画処理
void GAMEMANEGER::Draw_Scene_Play()
{

	this->back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	this->player->DrawHP();				//プレイヤーHP描画

	this->enemy->DrawImage();			//敵キャラ描画

	this->q_add->DrawQuestion();		//問題描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	this->gamelimittime->DrawElapsedTime(GAME_LIMITTIME_DRAW_X, GAME_LIMITTIME_DRAW_Y);			//制限時間の描画

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

	this->back->ChengeImage((int)DAMMY_BACK);	//背景画像を変更

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		this->NowScene = (int)SCENE_TITLE;	//タイトル画面へ
	}

	return;
}

//エンド画面の描画処理
void GAMEMANEGER::Draw_Scene_End()
{

	this->back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}
