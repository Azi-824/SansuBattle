//GAMEMANEGER.cpp
//ゲームのシステムを管理するクラス

//############### ヘッダファイル読み込み ################
#include "GAMEMANEGER.hpp"

//############### クラス定義 ################

//コンストラクタ
GAMEMANEGER::GAMEMANEGER()
{
	//オブジェクトの生成
	fps = new FPS(GAME_FPS_SPEED);	//FPSクラスのオブジェクトを生成
	keydown = new KEYDOWN();			//KEYDOWNクラスのオブジェクトを生成

	//メンバー変数初期化
	NowScene = (int)SCENE_LOAD;		//最初のシーンは、ロード画面
	IsLoad = false;					//読み込み、未完了
	GameLevel = -1;					//ゲームのレベル初期化
	return;

}

//デストラクタ
GAMEMANEGER::~GAMEMANEGER()
{
	//オブジェクトの破棄
	delete fps;				//fps破棄
	delete keydown;			//keydown破棄
	delete back;			//back破棄
	delete level_select;	//level_select破棄
	delete stage_select;	//stage_select破棄
	delete player;			//player破棄
	delete font;			//font破棄
	delete gamelimittime;	//gamelimittime破棄
	delete effect_atk;		//effect_atk破棄
	delete bgm;				//bgm破棄

	
	//問題関係
	for (int i = 0; i < quesiton.size(); ++i)	//問題の種類分
	{
		delete quesiton.at(i);	//question破棄
	}

	//敵関係
	for (int i = 0; i < enemy.size(); ++i)	//敵の数分
	{
		delete enemy.at(i);	//enemyの破棄
	}

	//スコア関係
	for (int i = 0; i < score.size(); ++i)	//スコアの種類分
	{
		delete score.at(i);	//score破棄
	}

	//vectorのメモリ解放を行う
	std::vector<Q_BASE*> v;		//空のvectorを作成する
	quesiton.swap(v);			//空と中身を入れ替える

	//vectorのメモリ解放を行う
	std::vector<ENEMY*> v2;		//空のvectorを作成する
	enemy.swap(v2);				//空と中身を入れ替える

	//vectorのメモリ解放を行う
	std::vector<ScoreBase*> v3;		//空のvectorを作成する
	score.swap(v3);					//空と中身を入れ替える

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
	font = new FONT(FONT_DIR, FONT_FILE_NAME, FONT_NAME);		//フォントを管理するオブジェクトを生成
	if (font->GetIsLoad() == false) { return false; }			//読み込み失敗

	//時間関係
	gamelimittime = new Time();		//ゲームの制限時間を管理するオブジェクトを生成

	//画像関係
	//背景画像
	back = new IMAGE(IMG_DIR_BACK, IMG_NAME_TITLE);		//背景画像を管理するオブジェクトを生成
	if (back->GetIsLoad() == false) { return false; }		//読み込み失敗
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_PLAY) == false) { return false; }	//プレイ画面の背景画像を追加
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_DAMMY) == false) { return false; }	//ダミー画像を追加

	//選択肢関係
	//難易度の選択肢
	level_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM, Q_LEVEL_SUM);		//難易度の選択肢を管理するオブジェクトを生成
	if (level_select->GetIsCreateSelect() == false) { return false; }			//読み込み失敗
	//選択肢の追加
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DIFFERENCE, Q_LEVEL_DIFFERENCE) == false) { return false; }		//ダミー画像追加
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRODUCT, Q_LEVEL_PRODUCT) == false) { return false; }		//ダミー画像追加
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DEALER, Q_LEVEL_DEALER) == false) { return false; }			//ダミー画像追加
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM_DIFF, Q_LEVEL_SUM_DIFFERENCE) == false) { return false; }	//ダミー画像追加
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRO_DEA, Q_LEVEL_PRODUCT_DEALER) == false) { return false; }	//ダミー画像追加

	//ステージの選択肢
	stage_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY01, STAGE_LEVEL_EASY);		//ステージの選択肢を管理するオブジェクトを生成
	if (stage_select->GetIsCreateSelect() == false) { return false; }			//読み込み失敗
	//選択肢の追加
	if (stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY02, STAGE_LEVEL_NORMAL) == false) { return false; }	//ダミー画像追加
	if (stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY03, STAGE_LEVEL_HARD) == false) { return false; }	//ダミー画像追加


	//プレイヤー関係
	player = new PLAYER();		//プレイヤーを管理するオブジェクトを生成

	//敵関係
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_FIRST));	//敵を管理するオブジェクトを生成(1体目)
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_SECOND));	//敵を管理するオブジェクトを生成(2体目)
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_THIRD));	//敵を管理するオブジェクトを生成(3体目)
	for (int i = 0; i < enemy.size(); ++i)	//敵の数だけ
	{
		if (enemy.at(i)->GetIsLoad() == false) { return false; }		//読み込み失敗
	}

	//エフェクト関係
	effect_atk = new Effect(EFFECT_DIR, EFFECT_NAME_ATACK, EFFECT_ATACK_ALL_CNT, EFFECT_ATACK_YOKO_CNT, EFFECT_ATACK_TATE_CNT, EFFECT_ATACK_WIDTH, EFFECT_ATACK_HEIGHT, EFFECT_ATACK_SPEED, false);	//攻撃エフェクトを管理するオブジェクトを生成
	if (effect_atk->GetIsLoad() == false) { return false; }//読み込み失敗
	if (effect_atk->AddSe(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_ATK) == false) { return false; }	//効果音追加

	//音楽関係
	//BGM
	bgm = new MUSIC(MUSIC_DIR_BGM, BGM_NAME_TITLE_BGM);								//BGMを管理するオブジェクトを生成
	if (bgm->GetIsLoad() == false) { return false; }								//読み込み失敗
	if (bgm->Add(MUSIC_DIR_BGM, BGM_NAME_SELECT_BGM) == false) { return false; }	//選択画面のBGM追加

	//問題関係
	//足し算
	quesiton.push_back(new Q_ADD());	//足し算の問題を管理するオブジェクトを生成

	//スコア関係
	//足し算
	score.push_back(new ScoreAdd());	//足し算のスコアを管理するオブジェクトを生成

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

	keydown->KeyDownUpdate();	//キーの入力状態を更新する

	fps->Update();		//FPSの処理[更新]

	//▼▼▼▼▼ゲームのシーンここから▼▼▼▼▼

	ProcesScene();		//各シーンの処理

	//▲▲▲▲▲ゲームのシーンここまで▲▲▲▲▲

	//this->fps->Draw(0, 0);		//FPS描画

	ScreenFlip();				//モニタのリフレッシュレートの速さで裏画面を再描画

	fps->Wait();			//FPSの処理[待つ]

	return true;				//正常

}

//各シーンの処理
void GAMEMANEGER::ProcesScene()
{
	switch (NowScene)		//現在のシーンの描画処理を実行
	{

	case (int)SCENE_LOAD:	//ロード画面のとき

		Scene_Load();			//ロード画面の処理

		Draw_Scene_Load();	//ロード画面の描画処理

		break;				//ロード画面のときここまで

	case (int)SCENE_TITLE:	//タイトル画面のとき

		Scene_Title();		//処理

		Draw_Scene_Title();	//描画

		break;				//タイトル画面のときここまで

	case (int)SCENE_CHOISELEVEL:	//難易度選択画面のとき

		Scene_ChoiseLevel();		//処理

		Draw_Scene_ChoiseLevel();	//描画

		break;				//難易度選択画面のときここまで

	case (int)SCENE_CHOISESTAGE:	//ステージ選択画面のとき

		Scene_ChoiseStage();		//処理

		Draw_Scene_ChoiseStage();	//描画

		break;				//ステージ選択画面のときここまで

	case (int)SCENE_PLAY:	//プレイ画面のとき

		Scene_Play();			//処理

		Draw_Scene_Play();	//描画

		break;				//プレイ画面のときここまで

	case (int)SCENE_DRAWSCORE:	//スコア表示画面のとき

		Scene_DrawScore();		//処理

		Draw_SceneDrawScore();	//描画

		break;				//スコア表示画面のときここまで

	case (int)SCENE_END:	//エンド画面のとき

		Scene_End();		//処理

		Draw_Scene_End();	//描画

		break;				//エンド画面のときここまで

	default:
		break;
	}

	return;	

}

//初期設定
void GAMEMANEGER::SetInit()
{
	back->SetInit();			//画像初期設定
	level_select->SetInit(SELECT_LEVEL_DRAW_X, SELECT_LEVEL_DRAW_Y, GAME_WIDTH);	//難易度の選択肢初期設定
	stage_select->SetInit(SELECT_STAGE_DRAW_X, SELECT_STAGE_DRAW_Y, GAME_WIDTH);	//ステージの選択肢初期設定
	player->SetInit(PLAYER_HP_DRAW_X, PLAYER_HP_DRAW_Y);							//プレイヤー初期設定
	effect_atk->SetInit();															//エフェクト初期設定

	for (int i = 0; i < enemy.size(); ++i)
	{
		enemy.at(i)->SetInit();								//敵の初期設定
	}

	//音楽関係
	bgm->ChengeVolume(30, (int)BGM_TYPE_TITLE);	//タイトルBGMの音量を30%にする
	bgm->ChengeVolume(30, (int)BGM_TYPE_SELECT);//選択画面のBGMの音量を30%にする
	bgm->ChengePlayType(DX_PLAYTYPE_LOOP);		//BGMの再生方法をループ再生に変更

	return;
}

//***************************** シーン毎の処理 ********************************
//ロード画面の処理
void GAMEMANEGER::Scene_Load()
{
	if (IsLoad)	//読み込みが完了していたら
	{
		if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
		{
			NowScene = (int)SCENE_TITLE;	//タイトル画面へ
		}
	}
	else		//読み込みが完了していなかったら
	{
		if (GetASyncLoadNum() == 0)	//非同期で読み込んでいる処理が終わったら
		{

			SetUseASyncLoadFlag(FALSE);	//同期読み込みに設定

			SetInit();			//初期設定

			IsLoad = true;		//読み込み完了
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

	back->ChengeImage((int)TITLE_BACK);	//背景画像を変更

	bgm->Play((int)BGM_TYPE_TITLE);		//BGMを再生

	level_select->Init();	//難易度の選択肢初期化
	stage_select->Init();	//ステージの選択肢初期化

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		bgm->Stop();								//再生中の音楽を止める
		NowScene = (int)SCENE_CHOISELEVEL;	//難易度選択画面へ
	}

	return;
}

//タイトル画面の描画処理
void GAMEMANEGER::Draw_Scene_Title()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	return;
}

//難易度選択画面の処理
void GAMEMANEGER::Scene_ChoiseLevel()
{

	bgm->Play((int)BGM_TYPE_SELECT);	//選択画面のBGMを再生

	level_select->Operation(keydown);			//選択肢キー操作

	if (level_select->GetIsChoise())			//選択したら
	{
		GameLevel = level_select->GetChoiseSelectCode();		//ゲームレベル設定
		NowScene = (int)SCENE_CHOISESTAGE;						//ステージ選択画面へ
	}

	return;
}

//難易度選択画面の描画処理
void GAMEMANEGER::Draw_Scene_ChoiseLevel()
{

	level_select->Draw();	//難易度の選択肢描画

	return;
}

//ステージ選択画面の処理
void GAMEMANEGER::Scene_ChoiseStage()
{

	stage_select->Operation(keydown);		//選択肢キー操作

	if (stage_select->GetIsChoise())		//選択したら
	{
		bgm->Stop();						//再生中のBGMを止める
		for (int i = 0; i < enemy.size(); ++i)	//敵の数分ループ
		{
			enemy.at(i)->Init();			//敵初期化
		}
		gamelimittime->SetTime();			//制限時間の計測開始
		NowScene = (int)SCENE_PLAY;			//プレイ画面へ
	}

	return;
}

//ステージ選択画面の描画処理
void GAMEMANEGER::Draw_Scene_ChoiseStage()
{

	stage_select->Draw();		//ステージ選択肢描画

	return;
}

//プレイ画面の処理
void GAMEMANEGER::Scene_Play()
{

	back->ChengeImage((int)PLAY_BACK);	//背景画像を変更

	gamelimittime->UpdateLimitTime(GAME_LIMIT_TIME);	//制限時間の更新

	if (!Q_BASE::GetIsCreate())	//問題を作成していなければ
	{
		quesiton.at(GameLevel)->CreateQuestion();	//問題を作成
	}

	if (Q_BASE::CheckInputKey(keydown))	//キー入力が完了したら
	{
		if (Q_BASE::JudgAnser())				//プレイヤーの回答が正解だったら
		{
			effect_atk->SetIsDraw(true,(int)EFFECT_ATACK);			//アニメーションの描画を開始する
		}
		else		//不正解だったら
		{
			player->SendDamege();	//プレイヤーにダメージを与える
		}

	}

	if (effect_atk->GetIsDrawEnd())							//アニメーション描画が終わったら
	{
		effect_atk->SetIsDraw(false, (int)EFFECT_ATACK);					//アニメーションを描画しない
		effect_atk->ResetIsAnime((int)EFFECT_ATACK);						//アニメーション状態をリセット
		enemy.at(ENEMY::GetNowEnemyNum())->SendDamege();					//敵にダメージを与える
		score.at(GameLevel)->CalcScore(gamelimittime->GetElapsedTime());	//スコア加算						
		gamelimittime->SetTime();											//制限時間の再計測
	}

	if (enemy.at(ENEMY::GetNowEnemyNum())->GetHp() <= 0)		//敵のHPが0になったら
	{
		enemy.at(ENEMY::GetNowEnemyNum())->SetIsArive(false);	//敵死亡
		if (enemy.at(ENEMY::GetNowEnemyNum())->GetFadeEnd())	//フェードアウト終了したら
		{
			ENEMY::NextEnemy();	//次の敵へ
		}
	}
	
	if (ENEMY::GetNowEnemyNum() >= enemy.size() ||			//敵の数が、最大数を超えたら
		player->GetHp() <= 0)								//プレイヤーのHPが0になったら	
	{
		NowScene = (int)SCENE_DRAWSCORE;		//スコア表示画面へ
	}

	return;
}

//プレイ画面の描画処理
void GAMEMANEGER::Draw_Scene_Play()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	player->DrawHp();				//プレイヤーHP描画

	if (ENEMY::GetNowEnemyNum() < enemy.size())	//現在の敵が、敵の最大数位内だったら
	{
		enemy.at(ENEMY::GetNowEnemyNum())->DrawCenter();	//敵キャラ描画
		enemy.at(ENEMY::GetNowEnemyNum())->DrawHp();		//HP描画
	}

	Q_BASE::DrawQuestion();				//問題文描画
	Q_BASE::DrawInputNum();				//入力中の数字を描画

	ScoreBase::DrawNowScore();			//現在のスコア描画

	gamelimittime->DrawLimitTime(GAME_LIMITTIME_DRAW_X, GAME_LIMITTIME_DRAW_Y, GAME_LIMIT_TIME);			//制限時間の描画

	effect_atk->DrawCenter((int)EFFECT_ATACK);	//攻撃エフェクト描画

	return;
}

//スコア表示画面の処理
void GAMEMANEGER::Scene_DrawScore()
{

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		NowScene = (int)SCENE_END;	//エンド画面へ
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

	back->ChengeImage((int)DAMMY_BACK);	//背景画像を変更

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		NowScene = (int)SCENE_TITLE;	//タイトル画面へ
	}

	return;
}

//エンド画面の描画処理
void GAMEMANEGER::Draw_Scene_End()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}
