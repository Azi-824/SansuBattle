//PLAYER.hpp
//プレイヤーを管理するクラス

#pragma once

//##################### ヘッダファイル読み込み #######################
#include "CHARACTOR.hpp"

//##################### マクロ定義 #########################
#define IMG_DIR_PLAYER	R"(.\MY_IMG\Player)"		//プレイヤーの画像のディレクトリ

#define IMG_NAME_HP		R"(\hp.png)"				//HP画像の名前

#define HP_INIT_VALUE	5	//HPの初期値

//##################### クラス定義 #########################
class PLAYER : public CHARACTOR		//キャラクタークラスを継承
{
private:

	int HP;							//HP

	bool IsImageLoad;				//画像を読み込めたか

public:

	PLAYER(const char*, const char*);	//コンストラクタ
	~PLAYER();							//デストラクタ

	bool GetIsLoad();					//読み込めたか取得

	void SendDamege();					//ダメージを与える

};
