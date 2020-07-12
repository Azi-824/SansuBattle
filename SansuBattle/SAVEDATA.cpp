//SaveData.cpp
//セーブデータを管理するクラス

//################### ヘッダファイル読み込み ##################
#include "SaveData.hpp"

//#################### クラス定義 #######################

vector<string> SaveData::FileNameTable;	//ファイル名のテーブル
vector<string> SaveData::TextTable;		//テキストのテーブル

//コンストラクタ
SaveData::SaveData()
{
	if (FileNameTable.empty())	//テーブルが作成されていなければ
	{
		//テーブルの作成を行う
		CreateTable();
	}
	return;
}

//デストラクタ
SaveData::~SaveData()
{

	for (int i = 0; i < DataCode.size(); ++i)
	{
		delete DataCode.at(i);
	}

	//vectorのメモリ解放を行う
	vector<Data*> v;			//空のvectorを作成する
	DataCode.swap(v);			//空と中身を入れ替える


	return;
}

//テーブルの作成
void SaveData::CreateTable()
{
	//ファイル名のテーブルを作成
	FileNameTable = { SAVE_NAME_SUM ,	//足し算
		SAVE_NAME_DIF,			//引き算
		SAVE_NAME_PRO,			//掛け算
		SAVE_NAME_DEA,			//割り算
		SAVE_NAME_SUM_DIF,		//+-
		SAVE_NAME_PRO_DEA,		//*/
		SAVE_NAME_SUM_PRO,		//+*
		SAVE_NAME_SUM_DEA,		//+/
		SAVE_NAME_DIF_PRO,		// /*
		SAVE_NAME_SUM_DIF_PRO,	//+-*
		SAVE_NAME_SUM_DIF_DEA,	//+-/
		SAVE_NAME_ALL			//+-*/
	};

	//テキストのテーブルを作成
	TextTable = { TEXT_GAMEMODE_SUM,	//+
		TEXT_GAMEMODE_DIF,				//-
		TEXT_GAMEMODE_PRO,				//*
		TEXT_GAMEMODE_DEA,				// /
		TEXT_GAMEMODE_SUM_DIF,			//+-
		TEXT_GAMEMODE_PRO_DEA,			//*/
		TEXT_GAMEMODE_SUM_PRO,			//+*
		TEXT_GAMEMODE_SUM_DEA,			//+/
		TEXT_GAMEMODE_DIF_PRO,			//-*
		TEXT_GAMEMODE_SUM_DIF_PRO,		//+-*
		TEXT_GAMEMODE_SUM_DIF_DEA,		//+-/
		TEXT_GAMEMODE_ALL				//+-*/
	};

}

//指定されたファイルが存在するか取得
//戻り値：bool：true　ファイルが存在する：false　ファイルが存在しない
bool SaveData::CheckCreateFile(string filename)
{
	struct stat statbuf;			//ファイルの存在確認に使用

	if (stat(filename.c_str(), &statbuf) == 0)		//セーブデータ用のファイルが作成されている場合
		return true;	//存在する
	else	//ない場合
		return false;	//存在しない
}

//データ追加
void SaveData::Add(int score)
{

	DATEDATA Date;		//現在時刻

	GetDateTime(&Date);	//現在時刻取得

	DataCode.push_back(new Data(Date.Year,Date.Mon,Date.Day,score));	//データ情報追加

	return;

}

//セーブ
bool SaveData::Save(int gamemode)
{
	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	if (!CheckCreateFile(LoadFile))//セーブデータ用のフォルダが作成されていない場合（初めてのセーブの場合）
	{
		_mkdir(SAVEDATA_DIR);	//セーブデータを格納するフォルダを作成
	}
	LoadFile += FileNameTable.at(gamemode);

	std::ofstream ofs(LoadFile.c_str(), std::ios_base::ate);	//ファイルオープン

	if (!ofs)		//ファイルオープン失敗時
	{
		string ErrorMsg(DATA_ERROR_MSG);	//エラーメッセージ作成
		ErrorMsg += TEXT('\n');						//改行
		ErrorMsg += LoadFile;					//画像のパス

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * を返す
			TEXT(DATA_ERROR_TTILE),
			MB_OK);

		return false;		//セーブ失敗

	}

	//セーブデータを書き込む
	for (int i = 0; i < SAVE_MAX; ++i)	//保存する最大数までループ
	{

		if (i >= DataCode.size())	//データの個数に達したら
			break;

		ofs << DataCode.at(i)->GetYear() << ',';				//年、書き出し
		ofs << DataCode.at(i)->GetMonth() << ',';				//月、書き出し
		ofs << DataCode.at(i)->GetDay() << ',';				//日、書き出し
		if (i == DataCode.size() - 1)	//最後の書き込みだったら
		{
			//終端文字を付ける
			ofs << DataCode.at(i)->GetScore() << '\0';			//勝ち数、書き出し
		}
		else	//最後の書き込みじゃなければ
		{
			//改行する
			ofs << DataCode.at(i)->GetScore() << '\n';			//勝ち数、書き出し
		}


	}

	return true;		//セーブ成功
}

//読み込み
bool SaveData::Load(int gamemode)
{

	DataCode.clear();	//データをリセット

	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	LoadFile += FileNameTable.at(gamemode);

	if (CheckCreateFile(LoadFile))	//読み込むファイルが存在する場合
	{
		std::ifstream ifs(LoadFile.c_str());	//ファイル読み取り

		if (!ifs)		//ファイルオープン失敗時
		{
			string ErrorMsg(DATA_ERROR_MSG);	//エラーメッセージ作成
			ErrorMsg += TEXT('\n');						//改行
			ErrorMsg += LoadFile;					//画像のパス

			MessageBox(
				NULL,
				ErrorMsg.c_str(),	//char * を返す
				TEXT(DATA_ERROR_TTILE),
				MB_OK);

			return false;	//読み込み失敗

		}


		string buf;
		int yy = 0, mm = 0, dd = 0, sc = 0;		//年、月、日、スコア

		while (!ifs.eof())				//最後の行まで読み込み
		{
			std::getline(ifs, buf, ',');		//カンマまで読み込み
			yy = atoi(buf.c_str());			//年読み込み

			std::getline(ifs, buf, ',');	//カンマまで読み込み
			mm = atoi(buf.c_str());			//月読み込み

			std::getline(ifs, buf, ',');	//カンマまで読み込み
			dd = atoi(buf.c_str());			//日読み込み

			std::getline(ifs, buf, '\n');	//改行まで読み込み
			sc = atoi(buf.c_str());			//スコア読み込み

			DataCode.push_back(new Data(yy, mm, dd, sc));		//データ追加

		}

	}

	return true;	//読み込み成功
}

//**************** ソート関係 ******************
//セーブデータを降順に並べ替える
void SaveData::Sort()
{

	for (int i = 0; i < DataCode.size(); ++i)
	{
		for (int j = DataCode.size() - 1; j > i; --j)
		{
			if (DataCode.at(j)->GetScore() > DataCode.at(j - 1)->GetScore())
			{
				auto temp = DataCode.at(j);
				DataCode.at(j) = DataCode.at(j - 1);
				DataCode.at(j - 1) = temp;
			}
		}
	}

	return;
}

//データ描画
void SaveData::Draw(int gamemode)
{

	int Height = GetFontSizeToHandle(NowFontHandle);		//高さ取得

	string text_gamemode = TEXT_GAMEMODE;	//ゲームモードのテキスト
	text_gamemode += TextTable.at(gamemode);	//ゲームモード毎のテキストを取得

	DrawStringToHandle(DRAW_DATA_X, DRAW_DATA_Y, text_gamemode.c_str(), COLOR_WHITE, NowFontHandle);		//ランキングタイトル描画

	for (int i = 0; i < DataCode.size();++i)
	{

		if (i >= DRAW_DATA_MAX)		//ランキング描画する最大数になったら
		{
			break;					//ループを抜ける
		}

		DrawFormatStringToHandle(DRAW_DATA_X, DRAW_DATA_Y + (i + 1) * Height, COLOR_WHITE, NowFontHandle, DRAW_DATA_TEXT,
			i + 1,						//何位か
			DataCode.at(i)->GetScore(),	//スコア
			DataCode.at(i)->GetYear(),	//年
			DataCode.at(i)->GetMonth(),	//月
			DataCode.at(i)->GetDay());	//日
	}

	return;
}
