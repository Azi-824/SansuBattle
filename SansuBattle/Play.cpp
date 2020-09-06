//Play.cpp
//プレイ画面の処理

//################# ヘッダファイル読み込み #################
#include "Play.hpp"

//################ クラス定義 ################

//コンストラクタ
Play::Play()
{

	//画像関係
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { IsLoad = false; return; }	//背景画像読み込み

	//BGM
	bgm.front()->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM);				//BGM追加（+）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DIF));			//BGM追加（-）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_PRO));			//BGM追加（*）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DEA));			//BGM追加（/）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DIF));		//BGM追加（+-）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_PRO_DEA));		//BGM追加（*/）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_PRO));		//BGM追加（+*）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DEA));		//BGM追加（+/）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DIF_PRO));		//BGM追加（-*）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DIF_PRO));	//BGM追加（+-*）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DIF_DEA));	//BGM追加（+-/）
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_ALL));			//BGM追加（ + -*/ ）
	for (auto b : bgm) { if (!b->GetIsLoad()) { IsLoad = false; return; } }	//読み込み失敗

	//********************* キャラクター ******************************
	//プレイヤー
	player = new Player();	//プレイヤー生成

	//敵
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//敵1体目生成
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY02));	//敵2体目生成
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY03));	//敵3体目生成

	//時間
	limit = new Time(LIMIT_TIME);		//制限時間

	IsLoad = true;	//読み込み成功

}

//デストラクタ
Play::~Play()
{
	delete player;		//player破棄
	delete limit;		//limit破棄
	
	//敵
	for (auto e : enemy) { delete e; }	//enemy破棄
	vector<Enemy*> v;
	v.swap(enemy);	
}

//初期設定
void Play::SetInit()
{

	font.at(HANDLE_NR)->Chenge();	//フォントハンドルをノーマルに変更

	back->SetInit();	//背景画像初期設定
	for (auto b : bgm) { b->SetInit(DX_PLAYTYPE_LOOP, VOL_DEF); }	//BGM初期設定

	//プレイヤー
	if (!player->SetInit()) { IsLoad = false; return; }	//初期設定
	//敵
	for (auto e : enemy)
	{
		if (!e->SetInit()) { IsLoad = false; return; }	//初期設定
	}
}

//プレイ画面の処理
void Play::Run()
{
	static bool start = false;
	if (!start)
	{
		quesiton.push_back(new Question(GameMode, GameLevel));	//問題を作成
		limit->SetTime();		//制限時間の計測開始
		start = true;
	}

	bgm.at(GameMode)->Play();			//BGMを流す
	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	player->Draw();								//プレイヤー（HP）描画
	enemy.at(Enemy::GetNowEnemyNum())->Draw();	//敵キャラ描画

	quesiton.back()->DrawQuestion();	//問題描画

	player->DrawInputNum();			//入力中の値を描画

	limit->UpdateLimitTime();			//制限時間の更新
	limit->DrawLimitTime(LIMIT_DRAW_X, LIMIT_DRAW_Y);	//制限時間描画

	if (player->CheckInputKey())	//キー入力が完了したら
	{
		if (quesiton.back()->JudgAnser(player->GetAns()))	//プレイヤーの回答が正解だったら
		{
			enemy.at(Enemy::GetNowEnemyNum())->SetDamegeFlg(true);		//敵にダメージフラグを立てる
		}
		else		//不正解だったら
		{
			//play_se.at(SE_PLAY_FALSE)->Play();				//不正解の効果音
			limit->MinusLimitTime(MISS_MINUS_TIME);		//制限時間を減らす
			player->InpReset();							//入力情報リセット
		}

	}

	if (enemy.at(Enemy::GetNowEnemyNum())->GetIsEffectEnd())	//エフェクト終了したら
	{
		enemy.at(Enemy::GetNowEnemyNum())->SendDamege();		//敵にダメージを与える
		player->InpReset();										//入力情報リセット
		quesiton.push_back(new Question(GameMode, GameLevel));	//次の問題を生成
		limit->SetTime();		//制限時間の再計測開始
	}

	if (limit->GetIsLimit())	//制限時間を超えたら
	{
		player->SendDamege();	//プレイヤーにダメージを与える
		quesiton.push_back(new Question(GameMode, GameLevel));	//次の問題を作成
		limit->SetTime();		//制限時間の再計測開始
	}

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		bgm.at(GameMode)->Stop();	//BGMを止める
		NowScene = SCENE_RANKING;	//ランキング画面へ
	}

}
