//CHARACTOR.hpp
//キャラクタークラス

#pragma once

//###################### ヘッダファイル読み込み ###################
#include "DxLib.h"
#include "main.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"

//###################### マクロ定義 #######################
#define HP_INIT_VALUE	5	//HPの初期値

//###################### クラス定義 #######################
class CHARACTOR
{
protected:

	IMAGE* image;				//画像

	int DrawX;					//描画X位置
	int DrawY;					//描画Y位置

	int HP;						//HP

	bool IsArive;				//生きているか
	bool IsKeyOperation;		//キーボードで操作できるか
	bool IsLoad;				//読み込めたか

public:

	CHARACTOR();				//コンストラクタ
	~CHARACTOR();				//デストラクタ

	void NewImage(const char*, const char*);	//新しい画像を読み込む

	void SetIsArive(bool);		//生きているかを設定
	void SetKeyOperation(bool); //キーボードで操作できるか設定

	void SetImagePos(int, int);	//位置を設定する

	bool GetIsArive();			//生きているか取得
	bool GetKeyOperation();		//キーボードで操作できるか取得
	bool GetIsLoad();			//読み込めたか取得

	void Operation(KEYDOWN *);	//操作

	bool SetInit(int,int);		//初期設定

	void SendDamege();			//ダメージを与える

};

