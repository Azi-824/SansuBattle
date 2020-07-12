//Music.hpp
//音楽用クラス

#pragma once

//##################### ヘッダファイル読み込み #######################
#include "Global.hpp"
#include <string>
#include <vector>

//##################### マクロ定義：ファイルパス、名前 ###################
#define MUSIC_DIR_SE			R"(.\MY_MUSIC\SE)"			//SEのファイル名
#define MUSIC_DIR_BGM			R"(.\MY_MUSIC\BGM)"			//BGMのファイル名
#define MUSIC_DIR_EFFECT		R"(.\MY_MUSIC\Effect)"		//エフェクトのファイル名

#define SE_NAME_EFFECT_ATK		R"(\atack.mp3)"			//攻撃エフェクトの効果音

#define BGM_NAME_TITLE_BGM			R"(\title_bgm.mp3)"		//タイトルのBGMの名前
#define BGM_NAME_SELECT_BGM			R"(\select_bgm.mp3)"	//選択画面のBGMの名前
//プレイ画面
#define BGM_NAME_PLAY_SUM_BGM			R"(\play_add_bgm.mp3)"			//プレイ画面（足し算）のBGMの名前
#define BGM_NAME_PLAY_DIFF_BGM			R"(\play_diff_bgm.mp3)"			//プレイ画面（引き算）のBGMの名前
#define BGM_NAME_PLAY_PRO_BGM			R"(\play_pro_bgm.mp3)"			//プレイ画面（掛け算）のBGMの名前
#define BGM_NAME_PLAY_DEA_BGM			R"(\play_dealer_bgm.mp3)"		//プレイ画面（割り算）のBGMの名前
#define BGM_NAME_PLAY_SUM_DIF_BGM		R"(\play_sum_dif_bgm.mp3)"		//プレイ画面（足し算、引き算）のBGMの名前
#define BGM_NAME_PLAY_PRO_DEA_BGM		R"(\play_pro_dea_bgm.mp3)"		//プレイ画面（掛け算、割り算）のBGMの名前
#define BGM_NAME_PLAY_SUM_PRO_BGM		R"(\play_sum_pro_bgm.mp3)"		//プレイ画面（+*）のBGMの名前
#define BGM_NAME_PLAY_SUM_DEA_BGM		R"(\play_sum_dea_bgm.mp3)"		//プレイ画面（+/）のBGMの名前
#define BGM_NAME_PLAY_DIF_PRO_BGM		R"(\play_dif_pro_bgm.mp3)"		//プレイ画面（-*）のBGMの名前
#define BGM_NAME_PLAY_SUM_DIF_PRO_BGM	R"(\play_sum_dif_pro_bgm.mp3)"	//プレイ画面（+-*）のBGMの名前
#define BGM_NAME_PLAY_SUM_DIF_DEA_BGM	R"(\play_sum_dif_dea_bgm.mp3)"	//プレイ画面（+-/）のBGMの名前
#define BGM_NAME_PLAY_ALL_BGM			R"(\play_all_bgm.mp3)"			//プレイ画面（+-*/）のBGMの名前

#define BGM_NAME_END_BGM			R"(\end_bgm.mp3)"		//エンド画面のBGMの名前

#define SE_NAME_KETTEI			R"(\kettei.mp3)"		//決定の効果音SE

//##################### マクロ定義：エラーメッセージ ######################
#define MUSIC_ERROR_TITLE "MUSIC_ERROR"					//エラータイトル
#define MUSIC_ERROR_MSG	"音が読み込めませんでした"		//エラーメッセージ

//##################### マクロ定義 ##########################
#define VOLUME_MAX		255	//音量の最大値

//##################### 列挙型 #########################
enum SE_EFFECT
{
	SE_EFFECT_ATACK			//攻撃エフェクトの効果音
};

enum SE_KEY
{
	SE_KEY_KETTEI			//キー操作（決定）の効果音
};

enum BGM_TYPE
{
	BGM_TYPE_TITLE,			//タイトルBGM
	BGM_TYPE_SELECT,		//選択画面のBGM
	BGM_TYPE_END			//エンドBGM
};

using std::string;

//##################### クラス定義 ############################
class Music
{
private:

	string FilePath;		//ファイルパス
	string FileName;		//名前

	int Handle;				//ハンドル
	int PlayType;			//音の再生方法

	bool IsLoad;			//読み込めたか
	bool IsPlayed;			//再生済みか


public:

	Music(const char *, const char *);		//コンストラクタ

	~Music();								//デストラクタ

	bool GetIsLoad();						//読み込めたかを取得する
	bool GetIsPlay();					//音が再生されているか取得する
	void SetInit(int, double);				//初期設定

	void ChengePlayType(int);				//音の再生方法を変更する
	void ChengeVolume(double);			//音量を変更する

	void Play(bool check =true);		//音を再生する
	void PlayOne(bool check = true);	//音を再生する(1回だけ)

	void PlayReset();						//再生済みがどうかをリセットする(全て)

	void Stop();							//音を止める(全て)

};
