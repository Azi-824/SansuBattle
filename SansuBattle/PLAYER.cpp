//PLAYER.cpp
//プレイヤーを管理するクラス

//################### ヘッダファイル読み込み #####################
#include "PLAYER.hpp"

//################### クラス定義 ##################

//コンストラクタ
//引　数：const char *：画像のディレクトリ
//引　数：const char *：画像の名前
PLAYER::PLAYER(const char* dir, const char* name)
{

	//HP画像生成 
	this->NewImage(dir, name);		//HP画像を生成
	return;

}

//デストラクタ
PLAYER::~PLAYER()
{
	return;
}

//HPを描画する
void PLAYER::DrawHp()
{
	image_hp->ChengeImage((int)HP_PLAYER);	//HPの画像の種類をプレイヤーの画像へ
	for (int i = 0; i < HP; ++i)	//HPの分ループ
	{
		image_hp->Draw(PLAYER_HP_DRAW_X + i * image_hp->GetWidth(), PLAYER_HP_DRAW_Y);	//HP画像描画
	}
}
