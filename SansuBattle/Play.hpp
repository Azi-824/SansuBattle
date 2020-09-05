//Play.hpp
//プレイ画面の処理

#pragma once

//############### ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Question.hpp"

//############### マクロ定義 #################
#define GAME_LIMIT_DRAW_X	680		//ゲームの制限時間描画X位置
#define GAME_LIMIT_DRAW_Y	10		//ゲームの制限時間描画Y位置
#define GAME_LIMIT_TIME		60		//ゲームの制限時間

using std::vector;

//############### クラス定義 #################
class Play : public Scene	//Sceneクラスを継承
{
private:

	Player* player;			//プレイヤー
	vector<Enemy*> enemy;	//敵
	vector<Question*> quesiton;	//問題

public:

	Play();		//コンストラクタ
	~Play();			//デストラクタ

	void SetInit() override;	//初期設定
	void Run() override;	//プレイ画面の処理

};
