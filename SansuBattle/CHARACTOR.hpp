//CHARACTOR.hpp
//キャラクタークラス

#pragma once

//###################### ヘッダファイル読み込み ###################
#include "DxLib.h"
#include "main.hpp"
#include "KEYDOWN.hpp"


//###################### マクロ定義 #######################

//###################### クラス定義 #######################
class CHARACTOR
{
private:

	int DrawX;					//描画X位置
	int DrawY;					//描画Y位置

	bool IsArive;				//生きているか
	bool IsKeyOperation;		//キーボードで操作できるか

public:

	CHARACTOR();				//コンストラクタ
	~CHARACTOR();				//デストラクタ

	void SetIsArive(bool);		//生きているかを設定
	void SetKeyOperation(bool); //キーボードで操作できるか設定

	void SetImagePos(int, int);	//位置を設定する

	bool GetIsArive();			//生きているか取得
	bool GetKeyOperation();		//キーボードで操作できるか取得

	void Operation(KEYDOWN *);	//操作

	bool SetInit();				//初期設定

};

