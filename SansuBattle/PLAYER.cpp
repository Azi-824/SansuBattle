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
	image_hp->ChengeImage((int)HP_PLAYER);	//HPの画像の種類をプレイヤーの画像へ
	for (int i = 0; i < HP; ++i)	//HPの分ループ
	{
		image_hp->Draw(PLAYER_HP_DRAW_X + i * image_hp->GetWidth(), PLAYER_HP_DRAW_Y);	//HP画像描画
	}
}
