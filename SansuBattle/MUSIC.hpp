//Music.hpp
//音楽用クラス

/*
追加方法
・フォルダ名、ファイル名をマクロ定義する
・追加した音の種類ごとに、列挙型に追加する
　例：戦闘で使用するSEを追加した場合
    　BT_SE_TYPEに追加する
・Add処理を使用して、SEやBGMを追加することができる
*/

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

#define BGM_NAME_TITLE_BGM		R"(\title_bgm.mp3)"		//タイトルのBGMの名前
#define BGM_NAME_SELECT_BGM		R"(\select_bgm.mp3)"	//選択画面のBGMの名前
#define BGM_NAME_PLAY_ADD_BGM	R"(\play_add_bgm.mp3)"	//プレイ画面（足し算）のBGMの名前
#define BGM_NAME_PLAY_DIFF_BGM	R"(\play_diff_bgm.mp3)"	//プレイ画面（引き算）のBGMの名前
#define BGM_NAME_END_BGM		R"(\end_bgm.mp3)"		//エンド画面のBGMの名前

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

enum BGM_TYPE
{
	BGM_TYPE_TITLE,			//タイトルBGM
	BGM_TYPE_SELECT,		//選択画面のBGM
	BGM_TYPE_END			//エンドBGM
};

enum BGM_TYPE_PLAY
{
	BGM_PLAY_ADD			//足し算のBGM
};

//##################### クラス定義 ############################
class Music
{
private:

	std::string FilePath;		//ファイルパス
	std::string FileName;		//名前

	std::vector<int> Handle;	//ハンドル
	int PlayType;				//音の再生方法

	bool IsLoad;				//読み込めたか
	std::vector<bool> IsPlayed;	//再生済みか


public:

	Music(const char *, const char *);		//コンストラクタ

	~Music();								//デストラクタ

	bool GetIsLoad();						//読み込めたかを取得する
	bool GetIsPlay(int);					//音が再生されているか取得する
	int GetSize();							//音楽が何種類入っているか取得
	void SetInit(int, double);				//初期設定

	void ChengePlayType(int);				//音の再生方法を変更する
	void ChengeVolume(double,int);			//音量を変更する

	void Play(int,bool check =true);		//音を再生する
	void PlayOne(int,bool check = true);	//音を再生する(1回だけ)

	void PlayReset(int);					//再生済みかどうかをリセットする(指定されたものだけ)
	void PlayReset();						//再生済みがどうかをリセットする(全て)

	void Stop();							//音を止める(全て)
	void Stop(int);							//音を止める(指定されたものだけ)

	bool Add(const char*, const char*);		//音を追加する

};
