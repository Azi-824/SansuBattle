//Enemy.cpp
//敵を管理するクラス

//############### ヘッダファイル読み込み ##################
#include "Enemy.hpp"

//############### クラス定義 #####################

//インスタンスを生成
int Enemy::NowEnemyNum = 0;

//コンストラクタ
//引　数：const char *：画像のディレクトリ
//引　数：const char *：画像の名前
Enemy::Enemy(const char* dir, const char* name)
{
	//画像生成
	img = new Image(dir, name);	//画像生成
	hp_img->Load(IMG_DIR_ENEMY, IMG_NAME_ENEMY_HP);	//HP画像生成

	HP_X = ENEMY_HP_DRAW_X;//HP描画X位置
	HP_Y = ENEMY_HP_DRAW_Y;//HP描画Y位置

}

//デストラクタ
Enemy::~Enemy()
{
	delete img;	//img破棄
}

//初期設定
bool Enemy::SetInit()
{
	if (!hp_img->GetIsLoad()) { return false; }	//読み込み失敗
	if (!img->GetIsLoad()) { return false; }	//読み込み失敗
	img->SetInit();		//敵キャラ画像初期設定
	hp_img->SetInit();		//HP
}

//初期化
void Enemy::Init()
{
	NowEnemyNum = 0;	//現在の敵の数を初期化
	HP = HP_INIT_VALUE;	//HP初期化
	IsArive = true;		//生きている
	img->SetIsFade(false);	//フェードアウトしない。
}

//次の敵へ
void Enemy::NextEnemy()
{
	if (NowEnemyNum < ENEMY_MAX)	//現在の敵が、敵の最大数より少なければ
	{
		++NowEnemyNum;				//次の敵へ
	}
}

//現在何体目の敵か取得
int Enemy::GetNowEnemyNum()
{
	return NowEnemyNum;
}

//描画
void Enemy::Draw()
{

	//HP描画
	for (int i = 0; i < HP; ++i)
	{
		if (reverse)	//反転描画するとき
		{
			hp_img->Draw(HP_X - i * hp_img->GetWidth(), HP_Y);	//反転描画
		}
		else	//通常描画のとき
		{
			hp_img->Draw(HP_X + i * hp_img->GetWidth(), HP_Y);	//HP描画
		}
	}

	//敵描画
	if (IsArive)	//生きていれば
	{
		img->DrawCenter();		//中央に描画
	}
	else			//死んでいれば
	{
		img->SetIsFade(true);	//フェードアウト開始
		img->DrawCenter();		//中央に描画
	}
}

//フェードアウト終了したか取得
bool Enemy::GetFadeEnd()
{
	return img->GetFadeEnd();
}
