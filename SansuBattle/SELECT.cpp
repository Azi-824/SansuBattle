//Select.cpp
//選択肢を管理するクラス

//################# ヘッダファイル読み込み #######################
#include "Select.hpp"

//################# クラス定義 ########################

//インスタンスを生成
vector<Music*> Select::Key_se;	//キーボードの効果音
vector<Image*> Select::Arrow;	//矢印の画像

//コンストラクタ
Select::Select(vector<Image*>image)
{

	//メンバー変数初期化
	Choise_SelectCode = CHOISE_NONE;	//選んだ選択肢のコードを初期化
	IsChoise = false;					//選択したか初期化
	IsBack = false;						//戻るか初期化
	IsNextPage = false;					//次のページへ行けるか初期化
	PageMax = 0;						//ページ数初期化
	NowPage = PAGE_START;				//現在のページ初期化
	DrawX = 0;							//描画開始X位置初期化
	DrawY = 0;							//描画開始Y位置初期化
	RowNum = 0;							//描画範囲の中で描画できる列の数初期化
	LineNum = 0;						//描画範囲の中で描画できる行の数初期化
	Interval_Side = 0;					//選択肢の間隔(横)初期化
	Interval_Vertical = 0;				//選択肢の間隔(縦)初期化
	//領域初期化
	rect.left = 0;
	rect.top = 0;
	rect.right = 0;
	rect.bottom = 0;

	if (Key_se.empty())	//キー操作の効果音が生成されていなかったら
	{
		Key_se.push_back(new Music(MUSIC_DIR_SE, SE_NAME_KETTEI));	//決定の効果音を追加
		Key_se.at((int)SE_KEY_KETTEI)->SetInit(DX_PLAYTYPE_BACK, 30);	//初期設定
	}

	if (Arrow.empty())	//矢印の画像が生成されていなかったら
	{
		Arrow.push_back(new Image(SELECT_IMG_DIR, IMG_NAME_ARROW_RIGHT));	//矢印（右）追加
		Arrow.push_back(new Image(SELECT_IMG_DIR, IMG_NAME_ARROW_LEFT));	//矢印（左）追加

		for (auto img : Arrow)
		{
			img->SetInit();	//初期設定
		}
	}

	SelectImage = image;				//選択肢の画像を生成
	/*
	修正案が思いついたら、修正
	*/
	for (int i = 0; i < SelectImage.size(); ++i)
	{
		SelectCode.push_back(i);		//選択肢のコード番号を設定
	}
	NowSelectCode = SelectCode.begin();	//現在選択しているコード番号を最初の選択肢に設定
}

//デストラクタ
Select::~Select()
{

	for (auto img : SelectImage)
	{
		delete img;	//SelectImage破棄
	}

	//vectorのメモリ解放を行う
	vector<int> v;				//空のvectorを作成する
	SelectCode.swap(v);			//空と中身を入れ替える

	//vectorのメモリ解放を行う
	vector<Image*> v2;				//空のvectorを作成する
	SelectImage.swap(v2);			//空と中身を入れ替える

}

//選択したか取得
bool Select::GetIsChoise()
{
	return IsChoise;
}

//戻るか取得
bool Select::GetIsBack()
{
	return IsBack;
}

//選んだ選択肢のコード番号を取得
int Select::GetChoiseSelectCode()
{
	return Choise_SelectCode;
}

//初期設定
/*
引数：int：描画開始X位置
引数：int：描画開始Y位置
引数：int：選択肢の間隔(横)
引数：int：選択肢の間隔(縦)、デフォルトは0
*/
void Select::SetInit(int x, int y, int interval_side,int interval_vertical)
{
	for (auto img : SelectImage)
	{
		img->SetInit();		//画像初期設定
	}

	DrawX = x;				//描画開始X位置設定
	DrawY = y;				//描画開始Y位置設定
	Interval_Side = interval_side;	//選択肢の間隔(横)を設定
	Interval_Vertical = interval_vertical;	//選択肢の間隔(縦)を設定

	//描画範囲の中で描画できる列の数を計算
	while (true)	//無限ループ
	{

		x += SelectImage.front()->GetWidth() + Interval_Side;			//Xの位置をずらす

		if (x > GAME_WIDTH)	//描画可能横幅を超えたら
			break;			//ループ終了

		++RowNum;			//カウントアップ
	}

	//描画範囲の中で描画できる行の数を計算
	while (true)	//無限ループ
	{
		y += SelectImage.front()->GetHeight() + Interval_Vertical;	//yの位置をずらす

		if (y > GAME_HEIGHT)	//描画可能高さを超えたら
			break;				//ループ終了

		++LineNum;				//カウントアップ
	}

	//選択肢をすべて描画するのに、何ページ必要か計算
	int one_page = RowNum * LineNum;	//1ページに入る選択肢の数
	do
	{
		++PageMax;	//ページ数増加
	} while ((one_page * PageMax) < SelectCode.size());	
	NowPage = PAGE_START;	//先頭のページを現在のページに設定

}

//初期化
void Select::Init()
{
	Choise_SelectCode = CHOISE_NONE;			//選んだ選択肢のコードを初期化
	IsChoise = false;							//選択したか初期化
	IsBack = false;								//戻るか初期化
	NowSelectCode = SelectCode.begin();			//現在選んでいる選択肢初期化
	DrawX += (GAME_WIDTH * (NowPage - 1));		//描画位置を戻す
	NowPage = PAGE_START;						//ページを戻す

	return;
}

//選択肢を追加
void Select::Add(Image* image)
{
	SelectImage.push_back(image);				//選択肢の画像追加
	SelectCode.push_back(SelectImage.size());	//選択肢コードを設定
	NowSelectCode = SelectCode.begin();			//現在選択しているコード番号を最初の選択肢に設定
}

//描画
void Select::Draw()
{

	int NowDrawX = DrawX, NowDrawY = DrawY;		//現在の描画位置
	int row_cnt = 0;							//列数のカウント
	int line_cnt = 0;							//行数のカウント
	int now_page = 0;							//ページカウント
	int cnt = 0;

	for (auto img : SelectImage)
	{
		if (row_cnt >= RowNum)		//列数が、描画できる範囲を超えたら
		{
			NowDrawX = DrawX + GAME_WIDTH * now_page;			//Xの描画位置を最初の位置へ
			NowDrawY += img->GetHeight() + Interval_Vertical;	//Yの描画位置を、画像の高さ＋間隔分下へずらす
			++line_cnt;											//カウントアップ
			row_cnt = 0;										//カウントリセット
		}

		if (line_cnt >= LineNum)	//行数が、描画できる範囲を超えたら
		{
			NowDrawX = DrawX + GAME_WIDTH;		//Xの位置を1画面分ずらした位置へ
			NowDrawY = DrawY;					//Yの位置を最初の位置へ
			++now_page;							//カウントアップ
			line_cnt = 0;						//カウントリセット
		}

		++row_cnt;	//カウントアップ

		if (cnt == *NowSelectCode)		//現在選択しているものだったら
		{
			//領域設定
			rect.left = NowDrawX - RECT_EXPANSION_VALUE;						//左上X
			rect.top = NowDrawY - RECT_EXPANSION_VALUE;							//左上Y
			rect.right = NowDrawX + img->GetWidth() + RECT_EXPANSION_VALUE;		//右下X
			rect.bottom = NowDrawY + img->GetHeight() + RECT_EXPANSION_VALUE;	//右下Y

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, RECT_TOUKA_VALUE * TOUKA_MAX_VALUE);	//透過させる
			DrawBox(rect.left, rect.top, rect.right, rect.bottom, COLOR_WHITE, TRUE);	//薄い四角形を描画
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//透過をやめる

			img->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}
		else		//それ以外は
		{
			img->Draw(NowDrawX, NowDrawY);	//選択肢画像を描画
		}

		NowDrawX += img->GetWidth() + Interval_Side;			//描画位置をずらす
		++cnt;	//カウントアップ

	}

	enum ARROW_TYPE
	{
		ARROW_RIGHT,	//右
		ARROW_LEFT		//左
	};

	//UIの描画
	if (NowPage == PAGE_START)	//最初のページなら
	{
		//右矢印のみ描画
		Arrow.at(ARROW_RIGHT)->DrawCenterY(ARROW_RIGHT_DRAW_X);
	}
	else if (NowPage == PageMax)	//最後のページなら
	{
		//左矢印のみ描画
		Arrow.at(ARROW_LEFT)->DrawCenterY(ARROW_LEFT_DRAW_X);
	}
	else		//それ以外なら
	{
		//両方とも描画
		Arrow.at(ARROW_RIGHT)->DrawCenterY(ARROW_RIGHT_DRAW_X);
		Arrow.at(ARROW_LEFT)->DrawCenterY(ARROW_LEFT_DRAW_X);
	}
			
}

//キー操作
void Select::Operation(KeyDown* keydown)
{
	if (keydown->IsKeyDownOne(KEY_INPUT_LEFT))	//左矢印キーを押されたら
	{
		if (CheckIsPrevPage())	//前のページへ行けるときは
		{
			PrevPage();	//前のページへ
		}
		else		//行けない時は
		{
			Prev();	//前の選択肢へ
		}
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RIGHT))	//右矢印キーを押されたら
	{
		if (CheckIsNextPage())	//次のページへ行けるときは
		{
			NextPage();	//次のページへ
		}
		else		//行けない時は
		{
			Next();	//次の選択肢へ
		}
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_UP))		//上矢印キーを押されたら
	{
		Prev(RowNum);		//列の数分、前の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_DOWN))		//下矢印キーを押されたら
	{
		Next(RowNum);		//列の数分、次の選択肢へ
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))	//エンターキーを押されたら
	{
		Choise_SelectCode = *NowSelectCode;				//現在選択している選択肢を設定
		IsChoise = true;								//選択した
		Key_se.at((int)SE_KEY_KETTEI)->Play(false);		//決定の効果音を鳴らす
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_BACK))		//バックスペースキーを押されたら
	{
		IsBack = true;	//戻る
	}

	return;

}

//次のページへ行けるか確認
bool Select::CheckIsNextPage()
{
	int distance = NowSelectCode - SelectCode.begin();	//距離を取得

	if (NowPage < PageMax && (distance + 1) % RowNum == 0)	//最後のページじゃなく、右端の選択肢を選んでいるとき
	{
		return true;		//次のページへ行ける
	}
	else		//それ以外の時は
	{
		return false;		//次のページへ行けない
	}

}

//前のページへ行けるか確認
bool Select::CheckIsPrevPage()
{
	int distance = NowSelectCode - SelectCode.begin();	//距離を取得

	if (NowPage > PAGE_START && distance % RowNum == 0)	//最初のページじゃなく、左端の選択肢を選んでいるとき
	{
		return true;		//前のページへ行ける
	}
	else		//それ以外の時は
	{
		return false;		//前のページへ行けない
	}

}

//次のページへ
void Select::NextPage()
{
	Next(RowNum + 1);		//次のページの選択へ
	++NowPage;				//次のページへ
	DrawX -= GAME_WIDTH;	//描画位置を1ページ分ずらす
}

//前のページへ
void Select::PrevPage()
{
	Prev(RowNum + 1);		//前のページの選択へ
	--NowPage;				//前のページへ
	DrawX += GAME_WIDTH;	//描画位置をを1ページ分ずらす
}

//次の選択肢へ
void Select::Next()
{

	if (*NowSelectCode < SelectCode.back())	//最後の選択肢じゃなければ
	{
		++NowSelectCode;	//次の選択肢へ
	}
	return;
}

//指定された分、次の選択肢へ
void Select::Next(int value)
{
	int distance = std::distance(SelectCode.begin(), NowSelectCode);		//現在選択している要素までの距離を取得
	distance += value;														//指定された分距離を加算
	int distance_max = std::distance(SelectCode.begin(), SelectCode.end());	//選択肢の最大の距離を取得
	if (distance < distance_max)	//選択肢の範囲内なら
	{
		NowSelectCode += value;	//指定された分、次の選択肢へ
	}

}

//前の選択肢へ
void Select::Prev()
{
	if (*NowSelectCode > SelectCode.front())		//最初の選択肢じゃなければ
	{
		--NowSelectCode;	//前の選択肢へ
	}

	return;
}

//指定された分、前の選択肢へ
void Select::Prev(int value)
{
	int distance = std::distance(SelectCode.begin(), NowSelectCode);			//現在選択している要素までの距離を取得
	distance -= value;															//指定された分距離を減算
	int distance_min = std::distance(SelectCode.begin(), SelectCode.begin());	//選択肢の最小の距離を取得

	if (distance > distance_min)	//選択肢の範囲内なら
	{
		NowSelectCode -= value;	//指定された分、前の選択肢へ
	}

}
