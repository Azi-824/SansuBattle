//ENEMY.cpp
//敵を管理するクラス

//############### ヘッダファイル読み込み ##################
#include "ENEMY.hpp"

//############### クラス定義 #####################

//インスタンスを生成
int ENEMY::NowEnemyNum = 0;

//コンストラクタ
//引　数：const char *：画像のディレクトリ
//引　数：const char *：画像の名前
ENEMY::ENEMY(const char* dir, const char* name)
{
	//画像生成
	this->NewImage(dir, name);

	return;
}

//デストラクタ
ENEMY::~ENEMY()
{
	return;
}

//次の敵へ
void ENEMY::NextEnemy()
{
	if (NowEnemyNum < ENEMY_MAX)	//現在の敵が、敵の最大数より少なければ
	{
		++NowEnemyNum;				//次の敵へ
	}
}

//現在の敵を初期化
void ENEMY::ResetNowEnemy()
{
	NowEnemyNum = 0;
}

//現在何体目の敵か取得
int ENEMY::GetNowEnemyNum()
{
	return NowEnemyNum;
}
