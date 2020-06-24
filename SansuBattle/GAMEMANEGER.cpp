//GameManeger.cpp
//ゲームのシステムを管理するクラス

//############### ヘッダファイル読み込み ################
#include "GameManeger.hpp"

//############### クラス定義 ################

//コンストラクタ
GameManeger::GameManeger()
{
	//オブジェクトの生成
	fps = new Fps(GAME_FPS_SPEED);	//FPSクラスのオブジェクトを生成
	keydown = new KeyDown();			//KEYDOWNクラスのオブジェクトを生成

	//メンバー変数初期化
	NowScene = (int)SCENE_LOAD;		//最初のシーンは、ロード画面
	IsLoad = false;					//読み込み、未完了
	GameMode = -1;					//ゲームモード初期化
	GameLevel = -1;					//ゲームレベル初期化
	GameEndFlg = false;				//ゲーム終了フラグ初期化
	return;

}

//デストラクタ
GameManeger::~GameManeger()
{
	//オブジェクトの破棄
	delete fps;				//fps破棄
	delete keydown;			//keydown破棄
	delete back;			//back破棄
	delete select_gamemode;	//level_select破棄
	delete select_level;	//stage_select破棄
	delete player;			//player破棄
	delete gamelimittime;	//gamelimittime破棄
	delete effect_atk;		//effect_atk破棄
	delete save;			//save破棄

	//音楽関係
	//BGM
	for (auto bgm : this->bgm)
	{
		delete bgm;		//bgm破棄
	}
	//プレイ画面のBGM
	for (auto bgm : bgm_play)
	{
		delete bgm;		//bgm_play破棄
	}

	//フォント関係
	Font::ReleaseFont();	//読み込んだフォントを開放
	for (int i = 0; i < font.size(); ++i)	//フォントハンドルの数分
		delete font.at(i);	//font破棄
	
	//問題関係
	for (int i = 0; i < question.size(); ++i)	//問題の種類分
		delete question.at(i);	//question破棄

	//敵関係
	for (int i = 0; i < enemy.size(); ++i)	//敵の数分
		delete enemy.at(i);	//enemyの破棄

	//スコア関係
	for (int i = 0; i < score.size(); ++i)	//スコアの種類分
		delete score.at(i);	//score破棄

	//vectorのメモリ解放を行う
	vector<Question*> v;		//空のvectorを作成する
	question.swap(v);		//空と中身を入れ替える

	//vectorのメモリ解放を行う
	vector<Enemy*> v2;		//空のvectorを作成する
	enemy.swap(v2);			//空と中身を入れ替える

	//vectorのメモリ解放を行う
	vector<Score*> v3;		//空のvectorを作成する
	score.swap(v3);			//空と中身を入れ替える

	//vectorのメモリ解放を行う
	vector<Font*> v4;		//空のvectorを作成する
	font.swap(v4);			//空と中身を入れ替える

	//vectorのメモリ解放を行う
	vector<Music*> v5;		//空のvectorを作成する
	bgm.swap(v5);			//空と中身を入れ替える

	//vectorのメモリ解放を行う
	vector<Music*> v6;		//空のvectorを作成する
	bgm_play.swap(v6);		//空と中身を入れ替える

	return;

}

//ゲーム内で使用するデータの読み込み処理
/*
戻り値：true：正常
戻り値：false：エラー、強制終了
*/
bool GameManeger::Load()
{

	//フォント関係
	if (Font::LoadFont(FONT_DIR, FONT_FILE_NAME, FONT_NAME) == false) { return false; }	//フォントを読み込み
	font.push_back(new Font((int)FONT_NAME_KOKUBAN, DEFAULT_FONTSIZE, FONT_BOLD_DEFAULT, DX_FONTTYPE_ANTIALIASING));		//フォントを管理するオブジェクトを生成
	font.push_back(new Font((int)FONT_NAME_KOKUBAN, FONTSIZE_DRAW_RANKING, FONT_BOLD_DEFAULT, DX_FONTTYPE_ANTIALIASING));	//こくばんフォント（ミニサイズ）作成
	for(int i = 0; i < font.size(); ++i)								//フォントハンドルの種類分
	if (font.at(i)->GetIsCreate() == false) { return false; }			//読み込み失敗
	NowFontHandle = font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle();	//使用するフォントをこくばんフォントに変更

	//時間関係
	gamelimittime = new Time();		//ゲームの制限時間を管理するオブジェクトを生成

	//画像関係
	//背景画像
	back = new Image(IMG_DIR_BACK, IMG_NAME_TITLE);		//背景画像を管理するオブジェクトを生成
	if (back->GetIsLoad() == false) { return false; }		//読み込み失敗
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_PLAY) == false) { return false; }		//プレイ画面の背景画像を追加
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_SELECT) == false) { return false; }	//選択画面の背景画像を追加
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_END) == false) { return false; }	//ダミー画像を追加

	//選択肢関係
	//難易度の選択肢
	select_gamemode = new Select(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM, Q_MODE_SUM);		//難易度の選択肢を管理するオブジェクトを生成
	if (select_gamemode->GetIsCreateSelect() == false) { return false; }			//読み込み失敗
	//選択肢の追加
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DIFFERENCE, Q_MODE_DIFFERENCE) == false) { return false; }		//ダミー画像追加
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRODUCT, Q_MODE_PRODUCT) == false) { return false; }		//ダミー画像追加
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DEALER, Q_MODE_DEALER) == false) { return false; }			//ダミー画像追加
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM_DIFF, Q_MODE_SUM_DIFFERENCE) == false) { return false; }	//ダミー画像追加
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRO_DEA, Q_MODE_PRODUCT_DEALER) == false) { return false; }	//ダミー画像追加

	//ステージの選択肢
	select_level = new Select(SELECT_IMG_DIR, IMG_NAME_SELECTLEVEL_EASY, STAGE_LEVEL_EASY);		//ステージの選択肢を管理するオブジェクトを生成
	if (select_level->GetIsCreateSelect() == false) { return false; }			//読み込み失敗
	//選択肢の追加
	if (select_level->Add(SELECT_IMG_DIR, IMG_NAME_SELECTLEVEL_NORMAL, STAGE_LEVEL_NORMAL) == false) { return false; }	//ダミー画像追加
	if (select_level->Add(SELECT_IMG_DIR, IMG_NAME_SELECTLEVEL_HARD, STAGE_LEVEL_HARD) == false) { return false; }	//ダミー画像追加


	//プレイヤー関係
	player = new Player();		//プレイヤーを管理するオブジェクトを生成

	//敵関係
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY_FIRST));	//敵を管理するオブジェクトを生成(1体目)
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY_SECOND));	//敵を管理するオブジェクトを生成(2体目)
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY_THIRD));	//敵を管理するオブジェクトを生成(3体目)
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
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_TITLE_BGM));					//BGMを管理するオブジェクトを生成
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_SELECT_BGM));					//選択肢画面のBGM追加
	for (auto bgm : this->bgm)
	{
		if (bgm->GetIsLoad() == false) { return false; }	//読み込み失敗
		bgm->SetInit(DX_PLAYTYPE_LOOP, 30);					//初期設定
	}

	bgm_play.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_ADD_BGM));					//BGM(プレイ画面)を管理するオブジェクトを生成
	bgm_play.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DIFF_BGM));				//プレイ画面（引き算）のBGM追加
	for (auto bgm : bgm_play)
	{
		if (bgm->GetIsLoad() == false) { return false; }	//読み込み失敗
		bgm->SetInit(DX_PLAYTYPE_LOOP, 30);					//初期設定
	}

	//問題関係
	//足し算
	question.push_back(new QuestionAdd());			//足し算の問題を管理するオブジェクトを生成
	question.push_back(new QuestionDifference());	//引き算の問題を管理するオブジェクトを生成

	//スコア関係
	//足し算
	score.push_back(new ScoreAdd());		//足し算のスコアを管理するオブジェクトを生成
	score.push_back(new ScoreDifference());	//引き算のスコアを管理するオブジェクトを生成

	//セーブデータ関係
	save = new SaveData();			//セーブデータを管理するオブジェクトを生成
	return true;	//読み込み成功
}

//ゲームのメインループ
/*
戻り値：true：正常
戻り値：false：エラー、強制終了
*/
bool GameManeger::GameMainLoop()
{
	if (ProcessMessage() != 0) { return false; }	//メッセージ処理の結果がエラーのとき、強制終了

	if (ClearDrawScreen() != 0) { return false; }	//画面を消去できなかったとき、強制終了

	keydown->KeyDownUpdate();	//キーの入力状態を更新する

	fps->Update();		//FPSの処理[更新]

	if (GameEndFlg) { return false; }		//ゲーム終了フラグが立ったら、強制終了

	//▼▼▼▼▼ゲームのシーンここから▼▼▼▼▼

	ProcesScene();		//各シーンの処理

	//▲▲▲▲▲ゲームのシーンここまで▲▲▲▲▲

	//this->fps->Draw(0, 0);		//FPS描画

	ScreenFlip();				//モニタのリフレッシュレートの速さで裏画面を再描画

	fps->Wait();			//FPSの処理[待つ]

	return true;				//正常

}

//各シーンの処理
void GameManeger::ProcesScene()
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

		Scene_ChoiseGameMode();		//処理

		Draw_Scene_ChoiseGameMode();	//描画

		break;				//難易度選択画面のときここまで

	case (int)SCENE_CHOISESTAGE:	//ステージ選択画面のとき

		Scene_ChoiseLevel();		//処理

		Draw_Scene_ChoiseLevel();	//描画

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
void GameManeger::SetInit()
{
	back->SetInit();			//画像初期設定
	select_gamemode->SetInit(SELECT_GAMEMODE_DRAW_X, SELECT_GAMEMODE_DRAW_Y, GAME_WIDTH, SELECT_GAMEMODE_INTERVAL_SIDE, SELECT_GAMEMODE_INTERVAL_VERTICAL);	//ゲームモードの選択肢初期設定
	select_level->SetInit(SELECT_LEVEL_DRAW_X, SELECT_LEVEL_DRAW_Y, GAME_WIDTH, SELECT_LEVEL_INTERVAL_SIDE);				//レベルの選択肢初期設定
	player->SetInit(PLAYER_HP_DRAW_X, PLAYER_HP_DRAW_Y);							//プレイヤー初期設定
	effect_atk->SetInit();															//エフェクト初期設定

	for (int i = 0; i < enemy.size(); ++i)
	{
		enemy.at(i)->SetInit();								//敵の初期設定
	}

	return;
}

//***************************** シーン毎の処理 ********************************
//ロード画面の処理
void GameManeger::Scene_Load()
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
void GameManeger::Draw_Scene_Load()
{

	if (IsLoad)	//読み込みが完了したら
	{
		DrawStringToHandle(TEST_TEXT_X, TEST_TEXT_Y, PUSH_TEXT, COLOR_WHITE, font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle());
	}
	else		//完了していなければ
	{
		DrawStringToHandle(TEST_TEXT_X, TEST_TEXT_Y, LOAD_TEXT, COLOR_WHITE, font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle());
	}

	return;
}

//タイトル画面の処理
void GameManeger::Scene_Title()
{

	back->ChengeImage((int)TITLE_BACK);	//背景画像を変更

	bgm.at((int)BGM_TYPE_TITLE)->Play();		//BGMを再生

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		bgm.at((int)BGM_TYPE_TITLE)->Stop();//再生中の音楽を止める
		NowScene = (int)SCENE_CHOISELEVEL;	//難易度選択画面へ
	}

	return;
}

//タイトル画面の描画処理
void GameManeger::Draw_Scene_Title()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	return;
}

//ゲームモード選択画面の処理
void GameManeger::Scene_ChoiseGameMode()
{

	back->ChengeImage((int)SELECT_BACK);	//背景画像を変更

	bgm.at((int)BGM_TYPE_SELECT)->Play();	//選択画面のBGMを再生

	select_gamemode->Operation(keydown);			//選択肢キー操作

	if (select_gamemode->GetIsChoise())			//選択したら
	{
		GameMode = select_gamemode->GetChoiseSelectCode();		//ゲームレベル設定

		//(読み込み成功時はtrueが返ってくるので、そのまま代入するとゲーム終了してしまうため、反転させている。）
		GameEndFlg = !(save->Load(GameMode));					//セーブデータ読み込み

		select_gamemode->Init();	//ゲームモードの選択肢初期化

		NowScene = (int)SCENE_CHOISESTAGE;						//ステージ選択画面へ
	}

	return;
}

//ゲームモード選択画面の描画処理
void GameManeger::Draw_Scene_ChoiseGameMode()
{
	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	select_gamemode->Draw();				//難易度の選択肢描画

	return;
}

//レベル選択画面の処理
void GameManeger::Scene_ChoiseLevel()
{

	select_level->Operation(keydown);		//選択肢キー操作

	if (select_level->GetIsChoise())		//選択したら
	{
		GameLevel = select_level->GetChoiseSelectCode();	//ゲームレベルを設定
		bgm.at((int)BGM_TYPE_SELECT)->Stop();				//再生中のBGMを止める
		for (int i = 0; i < enemy.size(); ++i)	//敵の数分ループ
		{
			enemy.at(i)->Init();			//敵初期化
		}
		player->Init();						//プレイヤー初期化
		score.at(GameMode)->ResetScore();	//スコアリセット
		question.at(GameMode)->Reset();		//問題関係リセット
		select_level->Init();				//レベルの選択肢初期化
		gamelimittime->SetTime();			//制限時間の計測開始
		NowScene = (int)SCENE_PLAY;			//プレイ画面へ
	}

	return;
}

//レベル選択画面の描画処理
void GameManeger::Draw_Scene_ChoiseLevel()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	select_level->Draw();		//ステージ選択肢描画

	return;
}

//プレイ画面の処理
void GameManeger::Scene_Play()
{

	back->ChengeImage((int)PLAY_BACK);	//背景画像を変更

	bgm_play.at(GameMode)->Play();			//プレイ画面のBGMを再生

	gamelimittime->UpdateLimitTime(GAME_LIMIT_TIME);	//制限時間の更新

	if (!question.at(GameMode)->GetIsCreate())	//問題を作成していなければ
	{
		question.at(GameMode)->CreateQuestion(GameLevel);	//問題を作成
	}

	if (question.at(GameMode)->CheckInputKey(keydown))	//キー入力が完了したら
	{
		if (question.at(GameMode)->JudgAnser())				//プレイヤーの回答が正解だったら
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
		enemy.at(Enemy::GetNowEnemyNum())->SendDamege();					//敵にダメージを与える
		score.at(GameMode)->CalcScore(GameLevel, gamelimittime->GetElapsedTime());	//スコア加算						
		gamelimittime->SetTime();											//制限時間の再計測
	}

	if (enemy.at(Enemy::GetNowEnemyNum())->GetHp() <= 0)		//敵のHPが0になったら
	{
		enemy.at(Enemy::GetNowEnemyNum())->SetIsArive(false);	//敵死亡
		if (enemy.at(Enemy::GetNowEnemyNum())->GetFadeEnd())	//フェードアウト終了したら
		{
			Enemy::NextEnemy();	//次の敵へ
		}
	}
	
	if (Enemy::GetNowEnemyNum() >= enemy.size() ||			//敵の数が、最大数を超えたら
		player->GetHp() <= 0)								//プレイヤーのHPが0になったら	
	{
		save->Add(score.at(GameMode)->GetScore());	//スコアを追加
		save->Sort();								//ソート処理
		bgm_play.at(GameMode)->Stop();				//再生中のBGMを止める
		NowScene = (int)SCENE_DRAWSCORE;			//スコア表示画面へ
	}

	return;
}

//プレイ画面の描画処理
void GameManeger::Draw_Scene_Play()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	player->DrawHp();				//プレイヤーHP描画

	if (Enemy::GetNowEnemyNum() < enemy.size())	//現在の敵が、敵の最大数位内だったら
	{
		enemy.at(Enemy::GetNowEnemyNum())->DrawCenter();	//敵キャラ描画
		enemy.at(Enemy::GetNowEnemyNum())->DrawHp();		//HP描画
	}

	question.at(GameMode)->DrawQuestion();				//問題文描画
	question.at(GameMode)->DrawInputNum();				//入力中の数字を描画

	score.at(GameMode)->DrawNowScore();	//現在のスコア描画

	gamelimittime->DrawLimitTime(GAME_LIMITTIME_DRAW_X, GAME_LIMITTIME_DRAW_Y, GAME_LIMIT_TIME);			//制限時間の描画

	effect_atk->DrawCenter((int)EFFECT_ATACK);	//攻撃エフェクト描画

	return;
}

//スコア表示画面の処理
void GameManeger::Scene_DrawScore()
{

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		NowScene = (int)SCENE_END;	//エンド画面へ
	}

	return;
}

//スコア表示画面の描画処理
void GameManeger::Draw_SceneDrawScore()
{
	NowFontHandle = font.at((int)HANDLE_TYPE_KOKUBAN_MINISIZE)->GetHandle();	//使用するフォントハンドル変更
	save->Draw(GameMode);														//データをランキング表示
	NowFontHandle = font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle();	//使用するフォントハンドル変更

	return;
}

//エンド画面の処理
void GameManeger::Scene_End()
{

	back->ChengeImage((int)END_BACK);	//背景画像を変更

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		NowScene = (int)SCENE_TITLE;	//タイトル画面へ
	}

	return;
}

//エンド画面の描画処理
void GameManeger::Draw_Scene_End()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	return;
}

//セーブ
bool GameManeger::Save()
{
	return save->Save(GameMode);	
}
