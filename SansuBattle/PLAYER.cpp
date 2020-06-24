//Player.cpp
//プレイヤーを管理するクラス

//################### ヘッダファイル読み込み #####################
#include "Player.hpp"

//################### クラス定義 ##################

//コンストラクタ
//引　数：const char *：画像のディレクトリ
//引　数：const char *：画像の名前
Player::Player()
{
	return;
}

//デストラクタ
Player::~Player()
{
	return;
}

//HPを描画する
void Player::DrawHp()
{
	for (int i = 0; i < HP; ++i)	//HPの分ループ
	{
		image_hp.at((int)HP_PLAYER)->Draw(PLAYER_HP_DRAW_X + i * image_hp.at((int)HP_PLAYER)->GetWidth(), PLAYER_HP_DRAW_Y);	//HP画像描画
	}
}
