//SAVEDATA.cpp
//セーブデータを管理するクラス

//################### ヘッダファイル読み込み ##################
#include "SAVEDATA.hpp"

//#################### クラス定義 #######################

//コンストラクタ
SAVEDATA::SAVEDATA()
{
	return;
}

//デストラクタ
SAVEDATA::~SAVEDATA()
{

	for (int i = 0; i < DataCode.size(); ++i)
	{
		delete DataCode.at(i);
	}

	//vectorのメモリ解放を行う
	std::vector<DATA*> v;			//空のvectorを作成する
	DataCode.swap(v);			//空と中身を入れ替える


	return;
}

//どのファイルを使用するか取得
const char* SAVEDATA::GetFileName(int gamelevel)
{
	switch (gamelevel)	//ゲームレベルごとにセーブするファイルを分ける
	{

	case (int)Q_LEVEL_SUM:		//足し算の時

		return SAVE_NAME_ADD;	//足し算用のファイルへ

		break;	//足し算の時ここまで

	case (int)Q_LEVEL_DIFFERENCE:		//引き算の時

		return SAVE_NAME_DIF;	//引き算用のファイルへ

		break;	//引き算の時ここまで

	case (int)Q_LEVEL_PRODUCT:		//掛け算の時

		return SAVE_NAME_PRO;	//掛け算用のファイルへ

		break;	//掛け算の時ここまで

	case (int)Q_LEVEL_DEALER:		//割り算の時

		return SAVE_NAME_DEA;	//割り算用のファイルへ

		break;	//割り算の時ここまで

	case (int)Q_LEVEL_SUM_DIFFERENCE:		//足し算、引き算の時

		return  SAVE_NAME_SUM_DIF;	//足し算、引き算用のファイルへ

		break;	//足し算、引き算の時ここまで

	case (int)Q_LEVEL_PRODUCT_DEALER:		//掛け算、割り算の時

		return SAVE_NAME_PRO_DEA;	//掛け算、割り算用のファイルへ

		break;	//掛け算、割り算の時ここまで

	default:
		break;
	}

}

//指定されたファイルが存在するか取得
//戻り値：bool：true　ファイルが存在する：false　ファイルが存在しない
bool SAVEDATA::CheckCreateFile(string filename)
{
	struct stat statbuf;			//ファイルの存在確認に使用

	if (stat(filename.c_str(), &statbuf) == 0)		//セーブデータ用のファイルが作成されている場合
		return true;	//存在する
	else	//ない場合
		return false;	//存在しない
}

//データ追加
void SAVEDATA::Add(int score)
{

	DATEDATA Date;		//現在時刻

	GetDateTime(&Date);	//現在時刻取得

	DataCode.push_back(new DATA(Date.Year,Date.Mon,Date.Day,score));	//データ情報追加

	return;

}

//セーブ
bool SAVEDATA::Save(int gamelevel)
{

	//struct stat statbuf;	//ディレクトリの存在確認に使用

	//if (stat(SAVEDATA_DIR, &statbuf) != 0)//セーブデータ用のフォルダが作成されていない場合（初めてのセーブの場合）
	//{
	//	_mkdir(SAVEDATA_DIR);	//セーブデータを格納するフォルダを作成
	//}

	std::string LoadFile;
	LoadFile += SAVEDATA_DIR;
	if (!CheckCreateFile(LoadFile))//セーブデータ用のフォルダが作成されていない場合（初めてのセーブの場合）
	{
		_mkdir(SAVEDATA_DIR);	//セーブデータを格納するフォルダを作成
	}
	LoadFile += GetFileName(gamelevel);


	std::ofstream ofs(LoadFile.c_str(), std::ios_base::ate);	//ファイルオープン

	if (!ofs)		//ファイルオープン失敗時
	{
		std::string ErrorMsg(DATA_ERROR_MSG);	//エラーメッセージ作成
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
	for (int i = 0; i < DataCode.size(); ++i)	//データの数だけループ
	{
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
bool SAVEDATA::Load(int gamelevel)
{
	std::string LoadFile;
	LoadFile += SAVEDATA_DIR;
	LoadFile += GetFileName(gamelevel);

	if (CheckCreateFile(LoadFile))	//読み込むファイルが存在する場合
	{
		std::ifstream ifs(LoadFile.c_str());	//ファイル読み取り

		if (!ifs)		//ファイルオープン失敗時
		{
			std::string ErrorMsg(DATA_ERROR_MSG);	//エラーメッセージ作成
			ErrorMsg += TEXT('\n');						//改行
			ErrorMsg += LoadFile;					//画像のパス

			MessageBox(
				NULL,
				ErrorMsg.c_str(),	//char * を返す
				TEXT(DATA_ERROR_TTILE),
				MB_OK);

			return false;	//読み込み失敗

		}


		std::string buf;
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

			DataCode.push_back(new DATA(yy, mm, dd, sc));		//データ追加

		}

	}

	return true;	//読み込み成功
}

//**************** ソート関係 ******************
//セーブデータを降順に並べ替える
void SAVEDATA::Sort()
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
void SAVEDATA::Draw()
{

	int Height = GetFontSize();		//高さ取得

	DrawString(DRAW_DATA_X, DRAW_DATA_Y, DRAW_DATA_TEXT_INDEX, COLOR_WHITE);		//ランキングタイトル描画

	for (int i = 0; i < DataCode.size();++i)
	{

		if (i >= DRAW_DATA_MAX)		//ランキング描画する最大数になったら
		{
			break;					//ループを抜ける
		}

		DrawFormatString(DRAW_DATA_X, DRAW_DATA_Y + (i + 1) * Height, COLOR_WHITE, DRAW_DATA_TEXT,
			i + 1,								//何位か
			DataCode.at(i)->GetScore(),	//スコア
			DataCode.at(i)->GetYear(),	//年
			DataCode.at(i)->GetMonth(),	//月
			DataCode.at(i)->GetDay());	//日
	}

	return;
}
