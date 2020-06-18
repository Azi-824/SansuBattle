//Charactor.cpp
//キャラクタークラス

//################# ヘッダファイル読み込み #####################
#include "Charactor.hpp"

//################ クラス定義 ########################

//インスタンス生成
Image* Charactor::image_hp;	//HP画像

//コンストラクタ
Charactor::Charactor()
{
	//メンバー変数初期化
	this->DrawX = 0;			//X位置初期化
	this->DrawY = 0;			//Y位置初期化
	this->IsArive = true;		//生きているか初期化
	this->IsKeyOperation = true;//キー操作可能か初期化
	this->HP = HP_INIT_VALUE;	//HP初期化
	this->IsLoad = false;		//読み込めたか初期化

	if (image_hp == NULL)	//HP画像が作成されていなければ
	{
		image_hp = new Image(IMG_DIR_CHARA, IMG_NAME_PLAYER_HP);	//プレイヤーのHP画像
		image_hp->AddImage(IMG_DIR_CHARA, IMG_NAME_ENEMY_HP);		//敵のHP画像
	}

	return;
}

//デストラクタ
Charactor::~Charactor()
{
	return;
}

//初期化
void Charactor::Init()
{
	HP = HP_INIT_VALUE;	//HP初期化
	IsArive = true;		//生きている
}

//生きているか設定
void Charactor::SetIsArive(bool Isarive)
{
	this->IsArive = Isarive;
	return;
}

//生きているか取得
bool Charactor::GetIsArive()
{
	return this->IsArive;
}

//読み込めたか取得
bool Charactor::GetIsLoad()
{
	return this->IsLoad;
}

//初期化設定
void Charactor::SetInit(int x,int y)
{

	image_hp->SetInit();	//HP画像初期設定
	DrawX = x;				//描画X位置
	DrawY = y;				//描画Y位置
	IsArive = true;			//生きている
	IsKeyOperation = true;	//キーボード操作できる

}

//ダメージを与える
void Charactor::SendDamege()
{
	if (this->HP > 0)		//HPが0じゃなければ
	{
		--this->HP;			//ダメージを与える
	}

	return;

}

//HP取得
int Charactor::GetHp()
{
	return HP;
}