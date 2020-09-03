//Player.cpp
//プレイヤーを管理するクラス

//################### ヘッダファイル読み込み #####################
#include "Player.hpp"

//################### クラス定義 ##################

//コンストラクタ
Player::Player()
{
	hp_img->Load(IMG_DIR_PLAYER, IMG_NAME_HP);	//HP画像生成
	HP_X = 0;//HP描画X位置
	HP_Y = 0;//HP描画Y位置
	reverse = false;			//反転描画するか
}

//デストラクタ
Player::~Player(){}

//初期設定
bool Player::SetInit()
{
	if (!hp_img->GetIsLoad()) { return false; }	//読み込み失敗
	hp_img->SetInit();	//画像初期設定
	HP_X = GAME_WIDTH - hp_img->GetWidth();	//HP描画X位置
	HP_Y = PLAYER_HP_DRAW_Y;				//HP描画Y位置
	reverse = true;	//反転描画
	return true;	//読み込み成功
}
