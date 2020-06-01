//ENEMY.cpp
//敵を管理するクラス

//############### ヘッダファイル読み込み ##################
#include "ENEMY.hpp"

//############### クラス定義 #####################

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

//画像描画
void ENEMY::DrawImage()
{
	this->image->Draw(this->DrawX, this->DrawY);	//画像を描画
	return;
}
