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
	DrawHp_type = HP_PLAYER;	//HPのタイプはプレイヤー
	return;
}

//デストラクタ
Player::~Player()
{
	return;
}
