//Effect.hpp
//エフェクトを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ######################
#include "Global.hpp"
#include <vector>
#include <string>
#include "MUSIC.hpp"

//###################### マクロ定義：ファイルパス、名前 ######################
#define EFFECT_DIR				R"(.\MY_EFFECT)"				//エフェクトの画像ファイルの場所

#define EFFECT_NAME_ATACK		R"(\Atack.png)"					//攻撃エフェクトの画像の名前

//###################### マクロ定義：エラーメッセージ ########################
#define EFFECT_ERROR_TTILE	"EFFECT_ERROR"						//エラータイトル
#define EFFECT_ERROR_MSG	"エフェクトが読み込めませんでした"	//エラーメッセージ

//###################### マクロ定義 #################################

//********************** サイズ ************************
#define EFFECT_ATACK_WIDTH		240	//分割幅
#define EFFECT_ATACK_HEIGHT		240	//分割高さ


//********************** 分割数 **************************
#define EFFECT_ATACK_YOKO_CNT		7	//横分割数
#define EFFECT_ATACK_TATE_CNT		1	//縦分割数

//************************ 総分割数 **************************
#define EFFECT_ATACK_ALL_CNT	EFFECT_ATACK_YOKO_CNT * EFFECT_ATACK_TATE_CNT	//総分割数

//************************ 描画速度 ***************************
#define EFFECT_ATACK_SPEED		0.08

//###################### 列挙型 ##########################
enum EFFECT_KIND
{
	EFFECT_ATACK		//攻撃エフェクト
};
//################### クラス定義 #########################
class Effect
{
private:

	std::vector<std::vector<int>> Handle;				//ハンドル
	std::vector<std::vector<int>::iterator> Handle_itr;	//ハンドルのイテレータ

	MUSIC* Se;							//エフェクト効果音

	std::vector<int> Width;				//幅
	std::vector<int> Height;			//高さ

	std::vector<double> NextChangeSpeed;		//アニメーションを変更する速さ(秒)
	int ChangeCnt;								//アニメーションするフレームのカウント
	std::vector<int> ChangeMaxCnt;				//アニメーションするフレームの最大値

	std::vector<bool> IsAnimeLoop;			//アニメーションはループする？
	std::vector<bool> IsAnimeStop;			//アニメーションはストップしたか？
	std::vector<bool> IsDraw;				//描画してよいか

	bool IsDrawEnd;				//描画終了したか

	bool IsLoad;				//読み込めたか？
	bool IsCreateSe;			//効果音のオブジェクトを作成したか

	bool IsFadeout;				//フェードアウト処理を行うか
	bool IsFadein;				//フェードイン処理を行うか

public:

	Effect(const char*, const char*, int, int, int, int, int, double, bool);	//コンストラクタ	

	~Effect();					//デストラクタ

	int GetWidth(int);			//幅を取得
	int GetHeight(int);			//高さを取得

	bool GetIsLoad(void);		//読み込めた？

	bool GetIsAnimeStop(int);	//アニメーションはストップしたかを取得

	bool GetIsDrawEnd();		//描画終了したか取得

	void SetIsDrawEnd(bool);	//描画終了したか設定

	void ResetIsAnime(int);		//アニメーションがストップしたかをリセット

	void Draw(int, int, int);	//描画
	void DrawCenter(int);		//画面中央に描画

	bool Add(const char*, const char*, int, int, int, int, int, double, bool);	//エフェクト追加
	bool AddSe(const char*, const char*);	//効果音追加

	void SetInit();						//初期設定

	void SetIsFadeout(bool);			//フェードアウトをするか設定
	void SetIsFadein(bool);				//フェードインをするか設定

	bool FadeOut(int, int, int, int);		//フェードアウトエフェクト
	bool FadeIn(int, int, int, int);	//フェードインエフェクト

	void SetIsDraw(bool, int);			//描画してよいか設定
	bool GetIsDraw(int);				//描画してよいか取得

};
