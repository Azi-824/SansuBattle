//GAMEMANEGER.hpp
//ゲームのシステムを管理するクラス

#pragma once

//############### ヘッダファイル読み込み ##################
#include "DxLib.h"
#include "FPS.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"
#include "SELECT.hpp"

//############### マクロ定義 ################
#define GAME_LEFT	  0		//画面の横の始点
#define GAME_TOP	  0		//画面の縦の始点
#define GAME_WIDTH	880		//画面の横の大きさ
#define GAME_HEIGHT	640		//画面の縦の大きさ
#define GAME_FPS_SPEED					   60

//テキスト関係
#define LOAD_TEXT			"NowLoading…"		//ロード画面のテキスト
#define PUSH_TEXT			"PushEnter"			//エンターキーを押す、のテキスト
#define TITLE_TEXT			"NowTitle"			//タイトル画面のテキスト
#define CHOISELEVEL_TEXT	"ChoiseLevel"		//難易度選択画面のテキスト
#define CHOISESTAGE_TEXT	"ChoiseStage"		//ステージ選択画面のテキスト
#define PLAY_TEXT			"NowPlay"			//プレイ画面のテキスト
#define DRAWSCORE_TEXT		"DrawScore"			//スコア表示画面のテキスト
#define END_TEXT			"NowEnd"			//エンド画面のテキスト

//座標関係
#define TEST_TEXT_X	30					//テスト用のテキスト描画X位置
#define TEST_TEXT_Y	30					//テスト用のテキスト描画Y位置

//色関係
#define COLOR_RED	GetColor(255,0,0)		//赤色
#define COLOR_GREEN	GetColor(0,255,0)		//緑色
#define COLOR_BLUE	GetColor(0,0,255)		//青色
#define COLOR_WHITE GetColor(255,255,255)	//白色
#define COLOR_BLACK GetColor(0,0,0)			//黒色

//############### 列挙型 ################
enum GAME_SCENE
{
	SCENE_LOAD,			//ロードシーン
	SCENE_TITLE,		//タイトルシーン
	SCENE_CHOISELEVEL,	//難易度選択シーン
	SCENE_CHOISESTAGE,	//ステージ選択シーン
	SCENE_PLAY,			//プレイシーン
	SCENE_DRAWSCORE,	//スコア表示シーン
	SCENE_END			//エンドシーン
};

//############### クラス定義 ################
class GAMEMANEGER
{

private:

	FPS *fps;					//fps
	KEYDOWN *keydown;			//キーボード関係
	IMAGE* back;				//背景画像
	SELECT* level_select;		//難易度選択肢

	int NowScene;				//現在のシーン
	bool IsLoad;				//読み込みが終わったか

public:

	GAMEMANEGER();				//コンストラクタ
	~GAMEMANEGER();				//デストラクタ

	bool Load();				//ゲームに使用するデータの読み込み処理
	bool GameMainLoop();		//ゲームのメインループ

	void ProcesScene();			//各シーンの処理


	//****************** シーン関係 *************************
	void Scene_Load();				//ロード画面の処理
	void Draw_Scene_Load();			//ロード画面の描画処理

	void Scene_Title();				//タイトル画面の処理
	void Draw_Scene_Title();		//タイトル画面の描画処理

	void Scene_ChoiseLevel();		//難易度選択画面の処理
	void Draw_Scene_ChoiseLevel();	//難易度選択画面の描画処理

	void Scene_ChoiseStage();		//ステージ選択画面の処理
	void Draw_Scene_ChoiseStage();	//ステージ選択画面の描画処理

	void Scene_Play();				//プレイ画面の処理
	void Draw_Scene_Play();			//プレイ画面の描画処理

	void Scene_DrawScore();			//スコア表示画面の処理
	void Draw_SceneDrawScore();		//スコア表示画面の描画処理
		
	void Scene_End();				//エンド画面の処理
	void Draw_Scene_End();			//エンド画面の描画処理

};
