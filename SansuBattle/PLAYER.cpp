//PLAYER.cpp
//プレイヤーを管理するクラス

//################### ヘッダファイル読み込み #####################
#include "PLAYER.hpp"

//################### クラス定義 ##################

//コンストラクタ
PLAYER::PLAYER(const char* dir, const char* name)
{
	//メンバー変数初期化
	this->HP = HP_INIT_VALUE;		//HP初期化

	//HP画像生成 
	this->IsImageLoad = this->NewImage(dir, name);		//HP画像を生成
	return;

}

//デストラクタ
PLAYER::~PLAYER()
{
	return;
}

//読み込めたか取得
bool PLAYER::GetIsLoad()
{
	return this->IsImageLoad;
}

//ダメージを与える
void PLAYER::SendDamege()
{
	if (this->HP > 0)		//HPが0じゃなければ
	{
		--this->HP;			//ダメージを与える
	}

	return;

}
