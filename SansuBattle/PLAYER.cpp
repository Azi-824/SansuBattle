//PLAYER.cpp
//プレイヤーを管理するクラス

//################### ヘッダファイル読み込み #####################
#include "PLAYER.hpp"

//################### クラス定義 ##################

//コンストラクタ
PLAYER::PLAYER(const char* dir, const char* name)
{

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

//HPを描画する
void PLAYER::DrawHP()
{
	for (int i = 0; i < this->HP; ++i)		//HPの分ループ
	{
		this->image->Draw(this->DrawX + i * this->image->GetWidth(), this->DrawY);	//HP画像描画
	}

	return;

}
