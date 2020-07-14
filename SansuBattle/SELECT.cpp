//Select.cpp
//�I�������Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� #######################
#include "Select.hpp"

//################# �N���X��` ########################

//�C���X�^���X�𐶐�
vector<Music*> Select::Key_se;	//�L�[�{�[�h�̌��ʉ�
vector<Image*> Select::Arrow;	//���̉摜

//�R���X�g���N�^
Select::Select(vector<Image*>image)
{

	//�����o�[�ϐ�������
	Choise_SelectCode = CHOISE_NONE;	//�I�񂾑I�����̃R�[�h��������
	IsChoise = false;					//�I��������������
	IsBack = false;						//�߂邩������
	IsNextPage = false;					//���̃y�[�W�֍s���邩������
	PageMax = 0;						//�y�[�W��������
	NowPage = PAGE_START;				//���݂̃y�[�W������
	DrawX = 0;							//�`��J�nX�ʒu������
	DrawY = 0;							//�`��J�nY�ʒu������
	RowNum = 0;							//�`��͈͂̒��ŕ`��ł����̐�������
	LineNum = 0;						//�`��͈͂̒��ŕ`��ł���s�̐�������
	Interval_Side = 0;					//�I�����̊Ԋu(��)������
	Interval_Vertical = 0;				//�I�����̊Ԋu(�c)������
	//�̈揉����
	rect.left = 0;
	rect.top = 0;
	rect.right = 0;
	rect.bottom = 0;

	if (Key_se.empty())	//�L�[����̌��ʉ�����������Ă��Ȃ�������
	{
		Key_se.push_back(new Music(MUSIC_DIR_SE, SE_NAME_KETTEI));	//����̌��ʉ���ǉ�
		Key_se.at((int)SE_KEY_KETTEI)->SetInit(DX_PLAYTYPE_BACK, 30);	//�����ݒ�
	}

	if (Arrow.empty())	//���̉摜����������Ă��Ȃ�������
	{
		Arrow.push_back(new Image(SELECT_IMG_DIR, IMG_NAME_ARROW_RIGHT));	//���i�E�j�ǉ�
		Arrow.push_back(new Image(SELECT_IMG_DIR, IMG_NAME_ARROW_LEFT));	//���i���j�ǉ�

		for (auto img : Arrow)
		{
			img->SetInit();	//�����ݒ�
		}
	}

	SelectImage = image;				//�I�����̉摜�𐶐�
	/*
	�C���Ă��v��������A�C��
	*/
	for (int i = 0; i < SelectImage.size(); ++i)
	{
		SelectCode.push_back(i);		//�I�����̃R�[�h�ԍ���ݒ�
	}
	NowSelectCode = SelectCode.begin();	//���ݑI�����Ă���R�[�h�ԍ����ŏ��̑I�����ɐݒ�
}

//�f�X�g���N�^
Select::~Select()
{

	for (auto img : SelectImage)
	{
		delete img;	//SelectImage�j��
	}

	//vector�̃�����������s��
	vector<int> v;				//���vector���쐬����
	SelectCode.swap(v);			//��ƒ��g�����ւ���

	//vector�̃�����������s��
	vector<Image*> v2;				//���vector���쐬����
	SelectImage.swap(v2);			//��ƒ��g�����ւ���

}

//�I���������擾
bool Select::GetIsChoise()
{
	return IsChoise;
}

//�߂邩�擾
bool Select::GetIsBack()
{
	return IsBack;
}

//�I�񂾑I�����̃R�[�h�ԍ����擾
int Select::GetChoiseSelectCode()
{
	return Choise_SelectCode;
}

//�����ݒ�
/*
�����Fint�F�`��J�nX�ʒu
�����Fint�F�`��J�nY�ʒu
�����Fint�F�I�����̊Ԋu(��)
�����Fint�F�I�����̊Ԋu(�c)�A�f�t�H���g��0
*/
void Select::SetInit(int x, int y, int interval_side,int interval_vertical)
{
	for (auto img : SelectImage)
	{
		img->SetInit();		//�摜�����ݒ�
	}

	DrawX = x;				//�`��J�nX�ʒu�ݒ�
	DrawY = y;				//�`��J�nY�ʒu�ݒ�
	Interval_Side = interval_side;	//�I�����̊Ԋu(��)��ݒ�
	Interval_Vertical = interval_vertical;	//�I�����̊Ԋu(�c)��ݒ�

	//�`��͈͂̒��ŕ`��ł����̐����v�Z
	while (true)	//�������[�v
	{

		x += SelectImage.front()->GetWidth() + Interval_Side;			//X�̈ʒu�����炷

		if (x > GAME_WIDTH)	//�`��\�����𒴂�����
			break;			//���[�v�I��

		++RowNum;			//�J�E���g�A�b�v
	}

	//�`��͈͂̒��ŕ`��ł���s�̐����v�Z
	while (true)	//�������[�v
	{
		y += SelectImage.front()->GetHeight() + Interval_Vertical;	//y�̈ʒu�����炷

		if (y > GAME_HEIGHT)	//�`��\�����𒴂�����
			break;				//���[�v�I��

		++LineNum;				//�J�E���g�A�b�v
	}

	//�I���������ׂĕ`�悷��̂ɁA���y�[�W�K�v���v�Z
	int one_page = RowNum * LineNum;	//1�y�[�W�ɓ���I�����̐�
	do
	{
		++PageMax;	//�y�[�W������
	} while ((one_page * PageMax) < SelectCode.size());	
	NowPage = PAGE_START;	//�擪�̃y�[�W�����݂̃y�[�W�ɐݒ�

}

//������
void Select::Init()
{
	Choise_SelectCode = CHOISE_NONE;			//�I�񂾑I�����̃R�[�h��������
	IsChoise = false;							//�I��������������
	IsBack = false;								//�߂邩������
	NowSelectCode = SelectCode.begin();			//���ݑI��ł���I����������
	DrawX += (GAME_WIDTH * (NowPage - 1));		//�`��ʒu��߂�
	NowPage = PAGE_START;						//�y�[�W��߂�

	return;
}

//�I������ǉ�
void Select::Add(Image* image)
{
	SelectImage.push_back(image);				//�I�����̉摜�ǉ�
	SelectCode.push_back(SelectImage.size());	//�I�����R�[�h��ݒ�
	NowSelectCode = SelectCode.begin();			//���ݑI�����Ă���R�[�h�ԍ����ŏ��̑I�����ɐݒ�
}

//�`��
void Select::Draw()
{

	int NowDrawX = DrawX, NowDrawY = DrawY;		//���݂̕`��ʒu
	int row_cnt = 0;							//�񐔂̃J�E���g
	int line_cnt = 0;							//�s���̃J�E���g
	int now_page = 0;							//�y�[�W�J�E���g
	int cnt = 0;

	for (auto img : SelectImage)
	{
		if (row_cnt >= RowNum)		//�񐔂��A�`��ł���͈͂𒴂�����
		{
			NowDrawX = DrawX + GAME_WIDTH * now_page;			//X�̕`��ʒu���ŏ��̈ʒu��
			NowDrawY += img->GetHeight() + Interval_Vertical;	//Y�̕`��ʒu���A�摜�̍����{�Ԋu�����ւ��炷
			++line_cnt;											//�J�E���g�A�b�v
			row_cnt = 0;										//�J�E���g���Z�b�g
		}

		if (line_cnt >= LineNum)	//�s�����A�`��ł���͈͂𒴂�����
		{
			NowDrawX = DrawX + GAME_WIDTH;		//X�̈ʒu��1��ʕ����炵���ʒu��
			NowDrawY = DrawY;					//Y�̈ʒu���ŏ��̈ʒu��
			++now_page;							//�J�E���g�A�b�v
			line_cnt = 0;						//�J�E���g���Z�b�g
		}

		++row_cnt;	//�J�E���g�A�b�v

		if (cnt == *NowSelectCode)		//���ݑI�����Ă�����̂�������
		{
			//�̈�ݒ�
			rect.left = NowDrawX - RECT_EXPANSION_VALUE;						//����X
			rect.top = NowDrawY - RECT_EXPANSION_VALUE;							//����Y
			rect.right = NowDrawX + img->GetWidth() + RECT_EXPANSION_VALUE;		//�E��X
			rect.bottom = NowDrawY + img->GetHeight() + RECT_EXPANSION_VALUE;	//�E��Y

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, RECT_TOUKA_VALUE * TOUKA_MAX_VALUE);	//���߂�����
			DrawBox(rect.left, rect.top, rect.right, rect.bottom, COLOR_WHITE, TRUE);	//�����l�p�`��`��
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//���߂���߂�

			img->Draw(NowDrawX, NowDrawY);	//�I�����摜��`��
		}
		else		//����ȊO��
		{
			img->Draw(NowDrawX, NowDrawY);	//�I�����摜��`��
		}

		NowDrawX += img->GetWidth() + Interval_Side;			//�`��ʒu�����炷
		++cnt;	//�J�E���g�A�b�v

	}

	enum ARROW_TYPE
	{
		ARROW_RIGHT,	//�E
		ARROW_LEFT		//��
	};

	//UI�̕`��
	if (NowPage == PAGE_START)	//�ŏ��̃y�[�W�Ȃ�
	{
		//�E���̂ݕ`��
		Arrow.at(ARROW_RIGHT)->DrawCenterY(ARROW_RIGHT_DRAW_X);
	}
	else if (NowPage == PageMax)	//�Ō�̃y�[�W�Ȃ�
	{
		//�����̂ݕ`��
		Arrow.at(ARROW_LEFT)->DrawCenterY(ARROW_LEFT_DRAW_X);
	}
	else		//����ȊO�Ȃ�
	{
		//�����Ƃ��`��
		Arrow.at(ARROW_RIGHT)->DrawCenterY(ARROW_RIGHT_DRAW_X);
		Arrow.at(ARROW_LEFT)->DrawCenterY(ARROW_LEFT_DRAW_X);
	}
			
}

//�L�[����
void Select::Operation(KeyDown* keydown)
{
	if (keydown->IsKeyDownOne(KEY_INPUT_LEFT))	//�����L�[�������ꂽ��
	{
		if (CheckIsPrevPage())	//�O�̃y�[�W�֍s����Ƃ���
		{
			PrevPage();	//�O�̃y�[�W��
		}
		else		//�s���Ȃ�����
		{
			Prev();	//�O�̑I������
		}
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RIGHT))	//�E���L�[�������ꂽ��
	{
		if (CheckIsNextPage())	//���̃y�[�W�֍s����Ƃ���
		{
			NextPage();	//���̃y�[�W��
		}
		else		//�s���Ȃ�����
		{
			Next();	//���̑I������
		}
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_UP))		//����L�[�������ꂽ��
	{
		Prev(RowNum);		//��̐����A�O�̑I������
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_DOWN))		//�����L�[�������ꂽ��
	{
		Next(RowNum);		//��̐����A���̑I������
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))	//�G���^�[�L�[�������ꂽ��
	{
		Choise_SelectCode = *NowSelectCode;				//���ݑI�����Ă���I������ݒ�
		IsChoise = true;								//�I������
		Key_se.at((int)SE_KEY_KETTEI)->Play(false);		//����̌��ʉ���炷
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_BACK))		//�o�b�N�X�y�[�X�L�[�������ꂽ��
	{
		IsBack = true;	//�߂�
	}

	return;

}

//���̃y�[�W�֍s���邩�m�F
bool Select::CheckIsNextPage()
{
	int distance = NowSelectCode - SelectCode.begin();	//�������擾

	if (NowPage < PageMax && (distance + 1) % RowNum == 0)	//�Ō�̃y�[�W����Ȃ��A�E�[�̑I������I��ł���Ƃ�
	{
		return true;		//���̃y�[�W�֍s����
	}
	else		//����ȊO�̎���
	{
		return false;		//���̃y�[�W�֍s���Ȃ�
	}

}

//�O�̃y�[�W�֍s���邩�m�F
bool Select::CheckIsPrevPage()
{
	int distance = NowSelectCode - SelectCode.begin();	//�������擾

	if (NowPage > PAGE_START && distance % RowNum == 0)	//�ŏ��̃y�[�W����Ȃ��A���[�̑I������I��ł���Ƃ�
	{
		return true;		//�O�̃y�[�W�֍s����
	}
	else		//����ȊO�̎���
	{
		return false;		//�O�̃y�[�W�֍s���Ȃ�
	}

}

//���̃y�[�W��
void Select::NextPage()
{
	Next(RowNum + 1);		//���̃y�[�W�̑I����
	++NowPage;				//���̃y�[�W��
	DrawX -= GAME_WIDTH;	//�`��ʒu��1�y�[�W�����炷
}

//�O�̃y�[�W��
void Select::PrevPage()
{
	Prev(RowNum + 1);		//�O�̃y�[�W�̑I����
	--NowPage;				//�O�̃y�[�W��
	DrawX += GAME_WIDTH;	//�`��ʒu����1�y�[�W�����炷
}

//���̑I������
void Select::Next()
{

	if (*NowSelectCode < SelectCode.back())	//�Ō�̑I��������Ȃ����
	{
		++NowSelectCode;	//���̑I������
	}
	return;
}

//�w�肳�ꂽ���A���̑I������
void Select::Next(int value)
{
	int distance = std::distance(SelectCode.begin(), NowSelectCode);		//���ݑI�����Ă���v�f�܂ł̋������擾
	distance += value;														//�w�肳�ꂽ�����������Z
	int distance_max = std::distance(SelectCode.begin(), SelectCode.end());	//�I�����̍ő�̋������擾
	if (distance < distance_max)	//�I�����͈͓̔��Ȃ�
	{
		NowSelectCode += value;	//�w�肳�ꂽ���A���̑I������
	}

}

//�O�̑I������
void Select::Prev()
{
	if (*NowSelectCode > SelectCode.front())		//�ŏ��̑I��������Ȃ����
	{
		--NowSelectCode;	//�O�̑I������
	}

	return;
}

//�w�肳�ꂽ���A�O�̑I������
void Select::Prev(int value)
{
	int distance = std::distance(SelectCode.begin(), NowSelectCode);			//���ݑI�����Ă���v�f�܂ł̋������擾
	distance -= value;															//�w�肳�ꂽ�����������Z
	int distance_min = std::distance(SelectCode.begin(), SelectCode.begin());	//�I�����̍ŏ��̋������擾

	if (distance > distance_min)	//�I�����͈͓̔��Ȃ�
	{
		NowSelectCode -= value;	//�w�肳�ꂽ���A�O�̑I������
	}

}
