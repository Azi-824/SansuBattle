//Scene.cpp

//############# ヘッダファイル読み込み ###############
#include "Scene.hpp"

//############## クラス定義 ################

int Scene::NowScene = 0;	//現在のシーン
bool Scene::GameEnd = false;//ゲームエンドフラグ
vector<Font*> Scene::font;	//フォント
int Scene::GameLevel = -1;	//ゲームレベル
int Scene::GameMode = -1;	//ゲームモード

//コンストラクタ
Scene::Scene()
{
	back = new Image();	//インスタンス生成
	bgm = new Music();	//インスタンス生成

	//フォント関係
	if (font.empty())	//フォントを作成していなかったら
	{
		font.push_back(new Font(FONT_NAME_KOKUBAN, F_SIZE_NORMAL, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));		//フォントを管理するオブジェクトを生成
		font.push_back(new Font(FONT_NAME_KOKUBAN, F_SIZE_MINI, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));		//こくばんフォント（ミニサイズ）作成
		font.push_back(new Font(FONT_NAME_KOKUBAN, F_SIZE_RANKING, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));//こくばんフォント（ランキングサイズ）作成
		for (auto f : font)
		{
			if (!f->GetIsCreate()) { IsLoad = false; return; }	//読み込み失敗
		}
	}

	IsLoad = false;		//読み込めたか
}

//デストラクタ
Scene::~Scene()
{
	delete back;	//back破棄
	delete bgm;		//bgm破棄
	Font::ReleaseFont();	//読み込んだフォントを開放
}

//現在のシーンを取得
int Scene::GetNowScene()
{
	return NowScene;
}

//ゲームエンドフラグを取得
bool Scene::IsGameEnd()
{
	return GameEnd;
}
