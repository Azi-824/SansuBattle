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
void PLAYER::DrawHP()
{
	for (int i = 0; i < this->HP; ++i)		//HPの分ループ
	{
		this->image->Draw(this->DrawX + i * this->image->GetWidth(), this->DrawY);	//HP画像描画
	}

	return;

}
