//CHARACTOR.hpp
//キャラクタークラス

#pragma once

//###################### ヘッダファイル読み込み ###################
#include "Global.hpp"
#include "KeyDown.hpp"
#include "Image.hpp"
#include <vector>

//###################### マクロ定義 #######################
#define IMG_DIR_CHARA			R"(.\MY_IMG\Charactor)"		//キャラクターの画像のディレクトリ

#define IMG_NAME_PLAYER_HP		R"(\player_hp.png)"			//プレイヤーHP画像の名前
#define IMG_NAME_ENEMY_HP		R"(\enemy_hp.png)"			//敵のHPの画像の名前


#define HP_INIT_VALUE	5	//HPの初期値

#define PLAYER_HP_DRAW_X		20	//HPの描画開始X位置
#define PLAYER_HP_DRAW_Y		400	//HPの描画開始Y位置

#define ENEMY_HP_DRAW_X		20		//HPの描画開始X位置
#define ENEMY_HP_DRAW_Y		20		//HPの描画開始Y位置

//###################### 列挙型 #################
enum HP_IMG_KIND
{
	HP_PLAYER,		//プレイヤーのHP
	HP_ENEMY		//敵のHP
};

using std::vector;

//###################### クラス定義 #######################
class Charactor
{
protected:

	static vector<Image*> image_hp;		//HP画像

	int DrawX;					//描画X位置
	int DrawY;					//描画Y位置

	int HP;						//HP
	int DrawHp_type;			//描画するHP画像のタイプ

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

	void DrawHp();				//HP描画

	int GetHp();				//HP取得

};

