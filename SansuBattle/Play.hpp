//Play.hpp
//プレイ画面の処理

#pragma once

//############### ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Question.hpp"
#include "Time.hpp"

//############### マクロ定義 #################
#define LIMIT_DRAW_X	740		//ゲームの制限時間描画X位置
#define LIMIT_DRAW_Y	10		//ゲームの制限時間描画Y位置
#define LIMIT_TIME		30		//ゲームの制限時間
#define MISS_MINUS_TIME	5		//間違えたときの減る時間

using std::vector;

//############### 列挙型 ##################
enum SE_KIND
{
	SE_FALSE,		//不正解の時の効果音
	SE_DAMEGE		//ダメージを受けたときの効果音
};

//############### クラス定義 #################
class Play : public Scene	//Sceneクラスを継承
{
private:

	Player* player;				//プレイヤー
	vector<Enemy*> enemy;		//敵
	vector<Question*> quesiton;	//問題
	Time* limit;				//制限時間
	vector<Music*> se;			//効果音

	void Start() override;		//シーンが変わるごとに1回だけ行う処理

public:

	Play();						//コンストラクタ
	~Play();					//デストラクタ

	void SetInit() override;	//初期設定
	void Run() override;		//プレイ画面の処理

};
