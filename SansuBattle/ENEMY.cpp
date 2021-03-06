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
	image = new Image(dir, name);	//画像生成
	IsLoad = image->GetIsLoad();	//読み込めたか

	DrawHp_type = HP_ENEMY;			//HPのタイプは敵

	return;
}

//デストラクタ
Enemy::~Enemy()
{
	delete image;	//image破棄
	return;
}

//初期設定
void Enemy::SetInit(int x, int y)
{
	image->SetInit();		//敵キャラ画像初期設定
	for (auto img : image_hp)
	{
		img->SetInit();		//初期設定
	}
	DrawX = x;				//描画X位置
	DrawY = y;				//描画Y位置
	IsArive = true;			//生きている
	IsKeyOperation = true;	//キーボード操作できる

}

//初期化
void Enemy::Init()
{
	NowEnemyNum = 0;	//現在の敵の数を初期化
	HP = HP_INIT_VALUE;	//HP初期化
	IsArive = true;		//生きている
	image->SetIsFade(false);	//フェードアウトしない。
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
	image->Draw(DrawX, DrawY);	//描画
}

//中央に描画
void Enemy::DrawCenter()
{
	if (IsArive)	//生きていれば
	{
		image->DrawCenter();		//中央に描画
	}
	else			//死んでいれば
	{
		image->SetIsFade(true);	//フェードアウト開始
		image->DrawCenter();	//中央に描画
	}
}

//フェードアウト終了したか取得
bool Enemy::GetFadeEnd()
{
	return image->GetFadeEnd();
}
