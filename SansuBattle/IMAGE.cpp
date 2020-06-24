/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Image.cpp     																				　 */
/*       																						　 */

//########## ヘッダーファイル読み込み ##########
#include "Image.hpp"

//########## クラスの定義 ##########

//コンストラクタ
//引　数：const char *：画像のディレクトリ
//引　数：const char *：画像の名前
Image::Image(const char *dir,const char *name)
{
	//メンバ変数を初期化
	FilePath = "";	//パス
	FileName = "";	//名前
	
	IsLoad = false;	//読み込めたか？

	//画像を読み込み
	string LoadfilePath;	//画像のファイルパスを作成
	LoadfilePath += dir;
	LoadfilePath += name;

	Handle = LoadGraph(LoadfilePath.c_str());//画像を読み込み
	
	if (Handle == -1)	//画像が読み込めなかったとき
	{
		string ErroeMsg(IMAGE_ERROR_MSG);	//エラーメッセージ作成
		ErroeMsg += TEXT('\n');				//改行
		ErroeMsg += LoadfilePath;			//画像のパス

		MessageBox(
			NULL, 
			ErroeMsg.c_str(),	//char * を返す
			TEXT(IMAGE_ERROR_TITLE),
			MB_OK);

		return;
	}

	FilePath = LoadfilePath;		//画像のパスを設定
	FileName = name;				//画像の名前を設定

	IsLoad = true;		//読み込めた

	IsDraw = true;	//描画してよい

	IsFade = false;	//フェードアウトしない
	FadeEnd = false;//フェードエフェクトが終わっていない

	return;
}

//デストラクタ
Image::~Image()
{
	//for (int handle : this->Handle)
	//{
	//	DeleteGraph(handle);		//読み込んだ画像を削除
	//}

	DeleteGraph(Handle);	//読み込んだ画像を削除

	//vectorのメモリ解放を行う
	//std::vector<int> v;			//空のvectorを作成する
	//this->Handle.swap(v);		//空と中身を入れ替える

	//std::vector<int>v2;
	//this->Width.swap(v2);

	//std::vector<int>v3;
	//this->Height.swap(v3);

	//std::vector<bool>v4;
	//this->IsDraw.swap(v4);

	//std::vector<bool>v5;
	//this->IsFade.swap(v5);

	//std::vector<bool>v6;
	//this->FadeEnd.swap(v6);

	//return;
}

//ファイルの名前を取得
std::string Image::GetFileName(void)
{
	return FileName;
}

//サイズを設定する
void Image::SetInit(void)
{
	//Width.resize(Handle.size());	//サイズ変更
	//Height.resize(Handle.size());	//サイズ変更
	//画像の数だけループする
	//for (int i = 0; i < this->Handle.size(); ++i)
	//{
	//	GetGraphSize(this->Handle[i], &this->Width[i], &this->Height[i]);	//画像サイズ取得
	//}

	GetGraphSize(Handle, &Width, &Height);	//画像サイズ取得
	return;
}

//画像数を取得する
//int Image::GetSize(void)
//{
//	return this->Handle.size();
//}

//幅を取得
int Image::GetWidth()
{
	return Width;
}

//高さを取得
int Image::GetHeight()
{
	return Height;
}

//読み込めた？
bool Image::GetIsLoad(void)
{
	return IsLoad;
}

//描画してよいか設定
void Image::SetIsDraw(bool isdraw)
{
	IsDraw = isdraw;
	FadeEnd = false;	//フェードアウト終了フラグリセット
}

//画像を描画
void Image::Draw(int x, int y)
{

	static int cnt = FADE_MAX_CNT;				//カウント用

	if (IsFade)	//フェードアウトするときは
	{
		if (!FadeEnd)	//フェードアウト終了していなければ
		{

			if (IsDraw)	//描画してよければ
			{
				
				//60フレーム分、待つ
				if (cnt > 0)
				{
					--cnt;	//カウントアップ
				}
				else
				{
					FadeEnd = true;	//フェード終了
				}

				//フェードアウトの処理
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//透過%を計算
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//透過させる
				DrawGraph(x, y, Handle, TRUE);											//画像を描画
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる


			}


		}
		else 		//フェードアウト終了したら
		{
			IsDraw = false;			//描画しない
			cnt = FADE_MAX_CNT;		//カウントリセット
			IsFade = false;			//フェードアウトしない
		}

	}
	else		//フェードアウトしない時は
	{
		cnt = FADE_MAX_CNT;		//カウントリセット

		if (IsDraw)	//描画してよければ
		{
			DrawGraph(x, y, Handle, TRUE);	//画像を描画
		}

	}
	

	return;

}

//画像を描画（中央）
//引数：int：画面の横幅：デフォルトはゲーム画面の横幅
//引数：int：描画する高さ：デフォルトはゲーム画面の高さ
void Image::DrawCenter(int width,int height)
{

	int x = 0, y = 0;	//描画するX位置,Y位置
	x = (width / 2) - (Width / 2);			//画面中央になるように計算
	y = (height / 2) - (Height / 2);		//画面中央になるように計算

	static int cnt = FADE_MAX_CNT;				//カウント用

	if (IsFade)	//フェードアウトするときは
	{
		if (!FadeEnd)	//フェードアウト終了していなければ
		{

			if (IsDraw)	//描画してよければ
			{

				//60フレーム分、待つ
				if (cnt > 0)
				{
					--cnt;	//カウントアップ
				}
				else
				{
					FadeEnd = true;	//フェード終了
				}

				//フェードアウトの処理
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//透過%を計算
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//透過させる
				DrawGraph(x, y, Handle, TRUE);					//画像を描画
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる


			}


		}
		else 		//フェードアウト終了したら
		{
			IsDraw = false;	//描画しない
			cnt = FADE_MAX_CNT;				//カウントリセット
			IsFade = false;	//フェードアウトしない
		}

	}
	else		//フェードアウトしない時は
	{
		cnt = FADE_MAX_CNT;		//カウントリセット

		if (IsDraw)	//描画してよければ
		{
			DrawGraph(x, y, Handle, TRUE);	//画像を描画
		}

	}



	return;
}

//画像を追加
//引　数：const char *：画像のディレクトリ
//引　数：const char *：画像の名前
//bool Image::AddImage(const char *dir, const char *name)
//{
//
//	this->IsLoad = false;	//読み込めていない
//
//	//画像を読み込み
//	std::string LoadfilePath;	//画像のファイルパスを作成
//	LoadfilePath += dir;
//	LoadfilePath += name;
//
//	this->Handle.push_back(LoadGraph(LoadfilePath.c_str()));	//画像を読み込み
//
//
//	if (this->Handle.back() == -1)	//画像が読み込めなかったとき
//	{
//		std::string ErroeMsg(IMAGE_ERROR_MSG);	//エラーメッセージ作成
//		ErroeMsg += TEXT('\n');					//改行
//		ErroeMsg += LoadfilePath;				//画像のパス
//
//		MessageBox(
//			NULL,
//			ErroeMsg.c_str(),	//char * を返す
//			TEXT(IMAGE_ERROR_TITLE),
//			MB_OK);
//
//		return false;
//	}
//
//	this->IsLoad = true;		//読み込めた
//
//	this->IsDraw.push_back(true);	//描画してよい
//	this->IsFade.push_back(false);	//フェードアウトしない
//	this->FadeEnd.push_back(false);	//フェードエフェクトが終わっていない
//
//	this->ImageKind = this->Handle.size();	//読み込んだ数を取得
//
//	return true;
//
//}
//
////描画する画像を変更
//void Image::ChengeImage(int kind)
//{
//	this->Draw_Num = kind;
//	return;
//}
//
////描画する画像を一つ次の画像へ
//void Image::NextImage()
//{
//	if (this->Draw_Num < this->Handle.size() - 1)	//描画する画像が最後の画像じゃなければ
//	{
//		++this->Draw_Num;	//次の画像へ
//	}
//	return;
//}
//
////描画する画像を指定された数、次の画像へ
//void Image::NextImage(int value)
//{
//	if (this->Draw_Num + value < this->Handle.size() - 1)	//描画する画像が最後の画像じゃなければ
//	{
//		this->Draw_Num += value;	//指定された数、次の画像へ
//	}
//	return;
//}
//
////描画する画像を一つ前の画像へ
//void Image::PrevImage()
//{
//	if (this->Draw_Num > 0)	//描画する画像が最初の画像じゃなければ
//	{
//		--this->Draw_Num;	//前の画像へ
//	}
//	return;
//}
//
////描画する画像を指定された数、前の画像へ
//void Image::PrevImage(int value)
//{
//	if (this->Draw_Num - value > 0)	//描画する画像が最初の画像じゃなければ
//	{
//		this->Draw_Num -= value;		//前の画像へ
//	}
//	return;
//}
//
////描画する画像を先頭の画像へ
//void Image::ChengeImageFront()
//{
//	this->Draw_Num = 0;	//先頭の画像へ
//	return;
//}

//フェードアウトするか設定
void Image::SetIsFade(bool isfade)
{
	IsFade = isfade;
	FadeEnd = false;	//フェードアウト終了フラグリセット

	return;
}

//フェードエフェクトが終了しているか取得
bool Image::GetFadeEnd()
{
	return FadeEnd;
}
