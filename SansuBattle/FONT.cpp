//FONT.cpp
//フォントクラス

//############### ヘッダファイル読み込み ####################
#include "FONT.hpp"

//############### クラスの定義 #####################

//インスタンス背性
vector<string> FONT::LoadFontName;	//読み込んだフォントの名前
vector<string> FONT::FilePath;		//読み込んだフォントのパス

//コンストラクタ
//引　数：int：読み込むフォントの名前
//引　数：int：フォントのサイズ
//引　数：int：フォントの太さ
//引　数：int：フォントのタイプ
FONT::FONT(int fontname, int size, int bold, int fonttype)
{
								
	Handle = CreateFontToHandle(LoadFontName.at(fontname).c_str(), size, bold, fonttype);	//フォントハンドルを作成
	//Handle = CreateFontToHandle(NULL,size, bold, fonttype);	//フォントハンドルを作成

	if (Handle == -1)		//ハンドル作成失敗
		IsCreate = false;	//作成失敗
	else					//ハンドル作成成功
		IsCreate = true;	//作成成功

	return;

}

//デストラクタ	
FONT::~FONT()
{
	//vectorのメモリ解放を行う
	std::vector<std::string> v;			//空のvectorを作成する
	this->FilePath.swap(v);				//空と中身を入れ替える

}

//フォントを読み込み
bool FONT::LoadFont(const char* dir, const char* name, const char* fontname)
{
	string LoadFilePath = dir;
	LoadFilePath += name;

	//フォント読み込み
	if (AddFontResourceEx(LoadFilePath.c_str(), FR_PRIVATE, NULL) <= 0)		//読み込み失敗
	{
		string ErroeMsg(FONT_ERROR_MSG);	//エラーメッセージ作成
		ErroeMsg += TEXT('\n');				//改行
		ErroeMsg += LoadFilePath;			//フォントのパス

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * を返す
			TEXT(FONT_ERROR_TITLE),
			MB_OK);

		return false;	//読み込み失敗

	}

	LoadFontName.push_back(fontname);	//読み込んだフォントの名前を追加
	FilePath.push_back(LoadFilePath);	//読み込んだフォントのパスを追加

	return true;

}

//読み込んだフォントを開放
bool FONT::ReleaseFont()
{
	for (int i = 0; i < LoadFontName.size(); ++i)
	{
		if (RemoveFontResourceEx(FilePath.at(i).c_str(), FR_PRIVATE, NULL) == 0)	//失敗時
		{
			MessageBox(NULL, "remove failure", "", MB_OK);				//エラーメッセージ
			return false;
		}

	}
	return true;
}

//フォントハンドル作成
int FONT::GetHandle()
{
	return Handle;
}

//フォントハンドルを作成できたか取得
bool FONT::GetIsCreate()
{
	return IsCreate;
}