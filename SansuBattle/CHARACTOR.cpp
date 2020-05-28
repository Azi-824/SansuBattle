//CHARACTOR.cpp
//キャラクタークラス

//################# ヘッダファイル読み込み #####################
#include "CHARACTOR.hpp"

//################ クラス定義 ########################
//コンストラクタ
CHARACTOR::CHARACTOR()
{
	//メンバー変数初期化
	this->DrawX = 0;			//X位置初期化
	this->DrawY = 0;			//Y位置初期化
	this->IsArive = true;		//生きているか初期化
	this->IsKeyOperation = true;//キー操作可能か初期化

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

//操作
void CHARACTOR::Operation(KEYDOWN *keydown)
{
	return;
}

//初期化設定
bool CHARACTOR::SetInit()
{

	this->IsArive = true;			//生きている
	this->IsKeyOperation = true;	//キーボード操作できる

	return true;

}
