//CHARACTOR.cpp
//キャラクタークラス

//################# ヘッダファイル読み込み #####################
#include "CHARACTOR.hpp"

//################ クラス定義 ########################

//インスタンス生成
IMAGE* CHARACTOR::image_hp;

//コンストラクタ
CHARACTOR::CHARACTOR()
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
		image_hp = new IMAGE(IMG_DIR_CHARA, IMG_NAME_PLAYER_HP);	//プレイヤーのHP画像
		image_hp->AddImage(IMG_DIR_CHARA, IMG_NAME_ENEMY_HP);		//敵のHP画像
	}

	return;
}

//デストラクタ
CHARACTOR::~CHARACTOR()
{
	return;
}

//生きているか設定
void CHARACTOR::SetIsArive(bool Isarive)
{
	this->IsArive = Isarive;
	return;
}

//キーボードで操作できるか設定
void CHARACTOR::SetKeyOperation(bool Iskeyoperation)
{
	this->IsKeyOperation = IsKeyOperation;
	return;
}

//位置を設定する
void CHARACTOR::SetImagePos(int x, int y)
{
	this->DrawX = x;	
	this->DrawY = y;
	return;
}

//生きているか取得
bool CHARACTOR::GetIsArive()
{
	return this->IsArive;
}

//キーボード操作できるか取得
bool CHARACTOR::GetKeyOperation()
{
	return this->IsKeyOperation;
}

//読み込めたか取得
bool CHARACTOR::GetIsLoad()
{
	return this->IsLoad;
}

//操作
void CHARACTOR::Operation(KEYDOWN *keydown)
{
	return;
}

//初期化設定
void CHARACTOR::SetInit(int x,int y)
{

	image_hp->SetInit();	//HP画像初期設定
	DrawX = x;				//描画X位置
	DrawY = y;				//描画Y位置
	IsArive = true;			//生きている
	IsKeyOperation = true;	//キーボード操作できる

}

//ダメージを与える
void CHARACTOR::SendDamege()
{
	if (this->HP > 0)		//HPが0じゃなければ
	{
		--this->HP;			//ダメージを与える
	}

	return;

}

//HP取得
int CHARACTOR::GetHp()
{
	return HP;
}