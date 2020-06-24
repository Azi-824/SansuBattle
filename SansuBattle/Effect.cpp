//Effect.cpp
//エフェクトクラス

//################## ヘッダファイル読み込み ##################
#include "Effect.hpp"

//################## クラス定義 #######################

//コンストラクタ
/*
引　数：const char *：画像のディレクトリ
引　数：const char *：画像の名前
引　数：int：画像の総分割数
引　数：int：画像の横向きの分割数
引　数：int：画像の縦向きの分割数
引　数：int：画像の分割された横の大きさ
引　数：int：画像の分割された縦の大きさ
引　数：double：次の画像に変更する速さ
引　数：bool：アニメーションをループするかどうか
*/
Effect::Effect(const char* dir, const char* name, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed, bool IsLoop,Music* se)
{
	//メンバー変数初期化
	IsLoad = false;			//読み込めたか？
	IsDrawEnd = false;		//描画終了したか?
	IsFadein = false;		//フェードイン処理を行わない
	IsFadeout = false;		//フェードアウト処理を行わない
	IsCreateSe = false;		//効果音のオブジェクトを作成していない
	Width = 0;				//横幅を初期化
	Height = 0;				//高さを初期化

	//画像を読み込み
	std::string LoadfilePath;		//画像のファイルパスを作成
	LoadfilePath += dir;
	LoadfilePath += name;

	vector<int> work(SplitNumALL);	//分割読み込みで得たハンドルを格納する配列を総分割数で初期化

	//画像を分割して読み込み
	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SplitNumY, SplitWidth, SplitHeight, &work.front());
	Handle = work;

	if (Handle.front() == -1)	//画像が読み込めなかったとき
	{
		std::string ErrorMsg(EFFECT_ERROR_MSG);	//エラーメッセージ作成
		ErrorMsg += TEXT('\n');						//改行
		ErrorMsg += LoadfilePath;					//画像のパス

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * を返す
			TEXT(EFFECT_ERROR_TTILE),
			MB_OK);

		return;
	}

	ChangeMaxCnt = (GAME_FPS_SPEED * changeSpeed);
	ChangeCnt = 0;	//アニメーションするフレームのカウント

	NextChangeSpeed = changeSpeed;	//画像を変える速さ

	IsAnimeLoop = IsLoop;		//アニメーションがループするか
	IsAnimeStop = false;		//アニメーションを動かす
	IsDraw = false;				//描画してよいか（最初は描画しない）

	Handle_itr = Handle.begin();	//先頭要素をイテレータに設定

	Se = se;			//効果音追加

	IsLoad = true;		//読み込めた

	//vectorのメモリ解放を行う
	vector<int> v;			//空のvectorを作成する
	work.swap(v);			//空と中身を入れ替える

	return;

}

//デストラクタ
Effect::~Effect()
{

	DeleteGraph(Handle.front());

	delete Se;	//Se破棄

	//vectorのメモリ解放を行う
	vector<int> v;			//空のvectorを作成する
	Handle.swap(v);			//空と中身を入れ替える

	return;

}

//幅を取得
int Effect::GetWidth()
{
	return Width;
}

//高さを取得
int Effect::GetHeight()
{
	return Height;
}

//読み込めた？
bool Effect::GetIsLoad(void)
{
	return IsLoad;
}

//アニメーションはストップしたかを取得
bool  Effect::GetIsAnimeStop()
{
	return IsAnimeStop;
}

//描画終了したかどうか取得
bool Effect::GetIsDrawEnd()
{
	return IsDrawEnd;
}

//描画終了したか設定
void Effect::SetIsDrawEnd(bool isend)
{
	IsDrawEnd = isend;
	return;
}

//アニメーションがストップしたかをリセット
void Effect::ResetIsAnime()
{
	IsAnimeStop = false;
	IsDrawEnd = false;
	return;
}

//描画
/*
引数：int：Xの描画位置
引数：int：Yの描画位置
*/
void Effect::Draw(int x, int y)
{

	if (IsDraw)		//描画してよければ
	{
		if (IsAnimeStop == false)	//アニメーションをストップさせないなら
		{
			DrawGraph(x, y, *Handle_itr, TRUE);	//イテレータ(ポインタ)を使用して描画
			Se->PlayOne(false);	//効果音再生
		}
		else
		{
			Se->PlayReset();	//再生状態リセット
			IsDrawEnd = true;	//描画終了
		}

		if (ChangeCnt == ChangeMaxCnt)	//次の画像を表示する時がきたら
		{
			//this->Handle.end()は、最後の要素の１個次のイテレータを返すので、-1している。
			if (Handle_itr == Handle.end() - 1)	//イテレータ(ポインタ)が最後の要素のときは
			{
				//アニメーションをループしないなら
				if (IsAnimeLoop == false)
				{
					IsAnimeStop = true;	//アニメーションを止める
				}

				//次回の描画に備えて、先頭の画像に戻しておく
				Handle_itr = Handle.begin();	//イテレータ(ポインタ)を要素の最初に戻す
			}
			else
			{
				++Handle_itr;	//次のイテレータ(ポインタ)(次の画像)に移動する
			}

			ChangeCnt = 0;	//カウント初期化
		}
		else
		{
			++ChangeCnt;	//カウントアップ
		}

	}

}

//画面中央に描画
void Effect::DrawCenter()
{

	if (IsDraw)	//描画してよければ
	{
		if (IsAnimeStop == false)	//アニメーションをストップさせないなら
		{
			DrawGraph((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), *Handle_itr, TRUE);	//イテレータ(ポインタ)を使用して描画
			Se->PlayOne(false);				//効果音再生
		}
		else
		{
			Se->PlayReset();	//再生状態リセット
			IsDrawEnd = true;		//描画終了
		}

		if (ChangeCnt == ChangeMaxCnt)	//次の画像を表示する時がきたら
		{
			//this->Handle.end()は、最後の要素の１個次のイテレータを返すので、-1している。
			if (Handle_itr == Handle.end() - 1)	//イテレータ(ポインタ)が最後の要素のときは
			{
				//アニメーションをループしないなら
				if (IsAnimeLoop == false)
				{
					IsAnimeStop = true;	//アニメーションを止める
				}

				//次回の描画に備えて、先頭の画像に戻しておく
				Handle_itr = Handle.begin();	//イテレータ(ポインタ)を要素の最初に戻す
			}
			else
			{
				++Handle_itr;	//次のイテレータ(ポインタ)(次の画像)に移動する
			}

			ChangeCnt = 0;	//カウント初期化
		}
		else
		{
			++ChangeCnt;	//カウントアップ
		}

	}

}

//初期設定
void Effect::SetInit(void)
{
	GetGraphSize(Handle.front(), &Width, &Height);		//サイズ取得
	Se->SetInit(DX_PLAYTYPE_BACK, 30);					//初期設定
}

//フェードアウトをするか設定
void Effect::SetIsFadeout(bool isfadeout)
{
	IsFadeout = isfadeout;
	return;
}

//フェードインをするか設定
void Effect::SetIsFadein(bool isfadein)
{
	IsFadein = isfadein;
	return;
}

//フェードアウトエフェクト
//引数：int：透過させたい範囲のX位置
//引数：int：透過させたい範囲のY位置
//引数：int：透過させたい範囲の横幅
//引数：int：透過させたい範囲の高さ
//戻り値：bool：フェードアウトが終了したか
//true：終了：false：終了していない
bool Effect::FadeOut(int x, int y, int width, int height)
{

	static int cnt = 0;				//カウント用
	static bool end_flg = false;	//フェード終了フラグ

	if (IsFadeout)		//フェードアウトするとき
	{

		if (!end_flg)	//フェードアウト終了していなければ
		{
			//60フレーム分、待つ
			if (cnt < FADE_MAX_CNT)
			{
				++cnt;	//カウントアップ
			}
			else
			{
				end_flg = true;	//フェード終了
			}

			//フェードアウトの処理
			double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//透過%を計算
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//透過させる
			DrawBox(x, y, width, height, COLOR_BLACK, TRUE);						//真っ暗な画面にする
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる

		}
		else if (end_flg)	//フェードアウト終了したら
		{
			IsFadeout = false;	//フェードアウトしない
			cnt = 0;			//カウントリセット
			end_flg = false;	//終了フラグリセット
		}

	}
	else		//フェードアウトをしない時
	{
		cnt = 0;			//カウントリセット
		end_flg = false;	//終了フラグリセット
		return true;		//フェードアウトは終わっている
	}

	return end_flg;

}

//フェードインエフェクト
//引数：int：透過させたい範囲のX位置
//引数：int：透過させたい範囲のY位置
//引数：int：透過させたい範囲の横幅
//引数：int：透過させたい範囲の高さ
//戻り値：bool：フェードインが終了したか
//true：終了：false：終了していない
bool Effect::FadeIn(int x, int y, int width, int height)
{
	static int cnt = FADE_MAX_CNT;	//カウント用
	static bool end_flg = false;	//フェード終了フラグ

	if (IsFadein)		//フェードインするとき
	{

		if (!end_flg)	//フェードイン終了していなければ
		{
			//60フレーム分、待つ
			if (cnt > 0)
			{
				--cnt;	//カウントダウン
			}
			else
			{
				end_flg = true;	//フェード終了
			}

			//フェードインの処理
			double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//透過%を計算
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//透過させる
			DrawBox(x, y, width, height, COLOR_BLACK, TRUE);						//真っ暗な画面にする
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる

		}
		else if (end_flg)	//フェードイン終了したら
		{
			cnt = FADE_MAX_CNT;		//カウントリセット
			end_flg = false;		//エンドフラグリセット
			IsFadein = false;	//フェードインしない
		}

	}
	else		//フェードインをしない時
	{
		cnt = FADE_MAX_CNT;	//カウントリセット
		end_flg = false;	//終了フラグリセット
		return true;		//フェードインは終わっている
	}

	return end_flg;

}

//描画してよいか設定
//引数：bool：描画してよいか
//引数：int：描画するエフェクトの種類
void Effect::SetIsDraw(bool isdraw)
{
	IsDraw = isdraw;
}

//描画してよいか取得
//引数：int：描画するエフェクトの種類
bool Effect::GetIsDraw()
{
	return IsDraw;
}
