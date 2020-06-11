//CHARACTOR.hpp
//キャラクタークラス

#pragma once

//###################### ヘッダファイル読み込み ###################
#include "Global.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"

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
class CHARACTOR
{
protected:

	static IMAGE* image_hp;		//HP画像

	int DrawX;					//描画X位置
	int DrawY;					//描画Y位置

	int HP;						//HP

	bool IsArive;				//生きているか
	bool IsKeyOperation;		//キーボードで操作できるか
	bool IsLoad;				//読み込めたか

public:

	CHARACTOR();				//コンストラクタ
	~CHARACTOR();				//デストラクタ

	void SetIsArive(bool);		//生きているかを設定
	void SetKeyOperation(bool); //キーボードで操作できるか設定

	void SetImagePos(int, int);	//位置を設定する

	bool GetIsArive();			//生きているか取得
	bool GetKeyOperation();		//キーボードで操作できるか取得
	bool GetIsLoad();			//読み込めたか取得

	void Operation(KEYDOWN *);	//操作

	virtual void SetInit(int x = 0, int y = 0);		//初期設定

	void SendDamege();			//ダメージを与える

	virtual void DrawHp() = 0;	//HP描画

	int GetHp();				//HP取得

};

