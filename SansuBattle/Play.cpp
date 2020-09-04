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
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY)) { IsLoad = false; return; }	//BGM読み込み

	//********************* キャラクター ******************************
	//プレイヤー
	player = new Player();	//プレイヤー生成

	//敵
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//敵1体目生成
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//敵2体目生成
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//敵3体目生成

	IsLoad = true;	//読み込み成功

}

//デストラクタ
Play::~Play()
{
	delete player;		//player破棄
	
	//敵
	for (auto e : enemy) { delete e; }	//enemy破棄
	vector<Enemy*> v;
	v.swap(enemy);	
}

//初期設定
void Play::SetInit()
{
	back->SetInit();	//背景画像初期設定
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM初期設定

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

	bgm->Play();	//BGMを流す
	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	player->Draw();	//プレイヤー（HP）描画
	enemy.at(Enemy::GetNowEnemyNum())->Draw();	//敵キャラ描画

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		bgm->Stop();				//BGMを止める
		NowScene = SCENE_RANKING;	//ランキング画面へ
	}

}
