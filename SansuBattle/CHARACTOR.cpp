//Charactor.cpp
//キャラクタークラス

//################# ヘッダファイル読み込み #####################
#include "Charactor.hpp"

//################ クラス定義 ########################

//インスタンス生成
vector<Image*> Charactor::image_hp;	//HP画像

//コンストラクタ
Charactor::Charactor()
{
	//メンバー変数初期化
	DrawX = 0;			//X位置初期化
	DrawY = 0;			//Y位置初期化
	IsArive = true;		//生きているか初期化
	IsKeyOperation = true;//キー操作可能か初期化
	HP = HP_INIT_VALUE;	//HP初期化
	DrawHp_type = -1;	//描画するHPの種類
	IsLoad = false;		//読み込めたか初期化

	if (image_hp.empty())	//HP画像が作成されていなければ
	{
		image_hp.push_back(new Image(IMG_DIR_CHARA, IMG_NAME_PLAYER_HP));//プレイヤーのHP画像
		image_hp.push_back(new Image(IMG_DIR_CHARA, IMG_NAME_ENEMY_HP));//プ敵のHP画像
	}

	return;
}

//デストラクタ
Charactor::~Charactor(){}

//初期化
void Charactor::Init()
{
	HP = HP_INIT_VALUE;	//HP初期化
	IsArive = true;		//生きている
}

//生きているか設定
void Charactor::SetIsArive(bool Isarive)
{
	IsArive = Isarive;
}

//生きているか取得
bool Charactor::GetIsArive()
{
	return IsArive;
}

//読み込めたか取得
bool Charactor::GetIsLoad()
{
	return IsLoad;
}

//初期設定
void Charactor::SetInit(int x,int y)
{
	for (auto img : image_hp)
	{
		img->SetInit();	//初期設定
	}
	DrawX = x;				//描画X位置
	DrawY = y;				//描画Y位置
	IsArive = true;			//生きている
	IsKeyOperation = true;	//キーボード操作できる

}

//ダメージを与える
void Charactor::SendDamege()
{
	if (HP > 0)		//HPが0じゃなければ
	{
		--HP;			//ダメージを与える
	}

}

//HP取得
int Charactor::GetHp()
{
	return HP;
}

//HP描画
void Charactor::DrawHp()
{
	for (int i = 0; i < HP; ++i)	//HPの分ループ
	{
		image_hp.at(DrawHp_type)->Draw(DrawX + i * image_hp.at(DrawHp_type)->GetWidth(), DrawY);	//HP画像描画
	}

}
