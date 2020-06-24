//Player.hpp
//プレイヤーを管理するクラス

#pragma once

//##################### ヘッダファイル読み込み #######################
#include "Charactor.hpp"

//##################### マクロ定義 #########################
#define IMG_DIR_PLAYER	R"(.\MY_IMG\Player)"		//プレイヤーの画像のディレクトリ

#define IMG_NAME_HP		R"(\hp.png)"				//HP画像の名前


//##################### クラス定義 #########################
class Player : public Charactor		//キャラクタークラスを継承
{
private:

public:

	Player();	//コンストラクタ
	~Player();							//デストラクタ

};
