/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* KEYDOWN.cpp     																				   */
/* KEYDOWNクラス																				   */
/* 一つのインスタンスのみにする																	   */

//########## ヘッダーファイル読み込み ##########
#include "KEYDOWN.hpp"

//########## クラスの定義 ##########

//インスタンスを生成
char KEYDOWN::AllKeyState[256];
int KEYDOWN::InputKeyCode;

//キーの入力状態を更新する
VOID KEYDOWN::KeyDownUpdate(VOID)
{
	char TempKey[256];			//一時的に、現在のキーの入力状態を格納する

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
			InputKeyCode = i;	//入力中のキーコードを保存
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//キーを押しているか、キーコードで判断する
BOOL KEYDOWN::IsKeyDown(int keycode)
{
	if (this->AllKeyState[keycode] != 0)
		return TRUE;
	else
		return FALSE;
}

//キーを押した瞬間だけtrueを返す
bool KEYDOWN::IsKeyDownOne(int keycode)
{
	if (this->AllKeyState[keycode] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//キー入力があるか取得
bool KEYDOWN::IsKeyInput()
{
	if (CheckHitKeyAll(DX_CHECKINPUT_KEY) == 0)	//キー入力があれば
	{
		return true;
	}
	else	//なければ
	{
		return false;
	}
}

//入力中のキーコードを取得
int KEYDOWN::GetInputKeyCode()
{
	return InputKeyCode;
}

//コンストラクタ
KEYDOWN::KEYDOWN()
{
}

//デストラクタ
KEYDOWN::~KEYDOWN()
{
}


//########## 外部オブジェクト ##########
extern KEYDOWN *keydown;