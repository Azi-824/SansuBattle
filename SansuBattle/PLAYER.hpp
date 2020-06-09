//PLAYER.hpp
//プレイヤーを管理するクラス

#pragma once

//##################### ヘッダファイル読み込み #######################
#include "CHARACTOR.hpp"

//##################### マクロ定義 #########################
#define IMG_DIR_PLAYER	R"(.\MY_IMG\Player)"		//プレイヤーの画像のディレクトリ

#define IMG_NAME_HP		R"(\hp.png)"				//HP画像の名前

#define PLAYER_HP_DRAW_X		20	//HPの描画開始X位置
#define PLAYER_HP_DRAW_Y		50	//HPの描画開始Y位置

//##################### クラス定義 #########################
class PLAYER : public CHARACTOR		//キャラクタークラスを継承
{
private:

public:

	PLAYER(const char*, const char*);	//コンストラクタ
	~PLAYER();							//デストラクタ

	void Draw() override;				//HPを描画する

};
