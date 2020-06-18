//CHARACTOR.hpp
//キャラクタークラス

#pragma once

//###################### ヘッダファイル読み込み ###################
#include "Global.hpp"
#include "KeyDown.hpp"
#include "Image.hpp"

//###################### マクロ定義 #######################
#define IMG_DIR_CHARA			R"(.\MY_IMG\Charactor)"		//キャラクターの画像のディレクトリ

#define IMG_NAME_PLAYER_HP		R"(\player_hp.png)"			//プレイヤーHP画像の名前
#define IMG_NAME_ENEMY_HP		R"(\enemy_hp.png)"			//敵のHPの画像の名前


#define HP_INIT_VALUE	5	//HPの初期値

//###################### 列挙型 #################
enum HP_IMG_KIND
{
	HP_PLAYER,		//プレイヤーのHP
	HP_ENEMY		//敵のHP
};

//###################### クラス定義 #######################
class Charactor
{
protected:

	static Image* image_hp;		//HP画像

	int DrawX;					//描画X位置
	int DrawY;					//描画Y位置

	int HP;						//HP

	bool IsArive;				//生きているか
	bool IsKeyOperation;		//キーボードで操作できるか
	bool IsLoad;				//読み込めたか

public:

	Charactor();				//コンストラクタ
	~Charactor();				//デストラクタ

	virtual void Init();		//初期化

	void SetIsArive(bool);		//生きているかを設定

	bool GetIsArive();			//生きているか取得
	bool GetIsLoad();			//読み込めたか取得

	virtual void SetInit(int x = 0, int y = 0);		//初期設定

	void SendDamege();			//ダメージを与える

	virtual void DrawHp() = 0;	//HP描画

	int GetHp();				//HP取得

};

