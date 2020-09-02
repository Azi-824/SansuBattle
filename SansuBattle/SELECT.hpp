//Select.hpp
//選択画面の処理

#pragma once

//############# ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Button.hpp"
#include "Group.hpp"

//############# マクロ定義 ##############
#define ARROW_RIGHT_DRAW_X		620		//矢印（右）の描画X位置
#define ARROW_LEFT_DRAW_X		50		//矢印（左）の描画X位置

#define START_DRAW_X			70		//スタートの描画X位置
#define START_DRAW_Y			400		//スタートの描画Y位置

//############# クラス定義 ##############
class Select : public Scene	//Sceneを継承
{
private:

	vector<Button*> mode;		//ゲームモード
	vector<Image*> mode_img;	//ゲームモード画像
	vector<Button*> level;		//ゲームレベル
	vector<Image*> level_img;	//ゲームレベル画像

	Group* mode_group;			//ゲームモードのグループ
	Group* level_group;			//ゲームレベルのグループ

public:

	Select();			//コンストラクタ
	~Select();			//デストラクタ

	void SetInit() override;	//初期設定
	void Run() override;		//選択画面の処理

};
