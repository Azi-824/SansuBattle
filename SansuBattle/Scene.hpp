//Scene.hpp
//各シーンの基になるクラス

#pragma once

//################### ヘッダファイル読み込み ######################
#include "Global.hpp"
#include "Image.hpp"
#include "Music.hpp"
#include "Font.hpp"

//################### マクロ定義 #########################

//################### 列挙型 #####################
enum GAME_SCENE
{
	SCENE_LOAD,			//ロードシーン
	SCENE_TITLE,		//タイトルシーン
	SCENE_SELECT,		//選択シーン
	SCENE_PLAY,			//プレイシーン
	SCENE_RANKING		//ランキングシーン
};

using std::vector;

//################### クラス定義 #########################
class Scene
{
protected:

	//クラス共通
	static int NowScene;		//現在のシーン
	static bool GameEnd;		//ゲーム終了フラグ
	static vector<Font*> font;	//フォント

	//インスタンス毎
	Image* back;	//背景画像
	Music* bgm;		//BGM
	bool IsLoad;	//読み込めたか

public:

	Scene();		//コンストラクタ
	~Scene();		//デストラクタ

	static int GetNowScene();	//現在のシーンを取得
	static bool IsGameEnd();	//ゲームエンドフラグを取得

	virtual void SetInit() = 0;		//初期設定
	virtual void Run() = 0;			//シーン毎の処理

};
