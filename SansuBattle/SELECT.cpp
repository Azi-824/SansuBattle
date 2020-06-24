//Select.cpp
//�I�������Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� #######################
#include "Select.hpp"

//################# �N���X��` ########################

//�C���X�^���X�𐶐�
vector<Music*> Select::Key_se;	//�L�[�{�[�h�̌��ʉ�

//�R���X�g���N�^
Select::Select(const char* dir, const char* name,int code)
{

	//�����o�[�ϐ�������
	Choise_SelectCode = CHOISE_NONE;	//�I�񂾑I�����̃R�[�h��������
	IsChoise = false;					//�I��������������
	DrawX = 0;							//�`��J�nX�ʒu������
	DrawY = 0;							//�`��J�nY�ʒu������
	DrawWidth_Range = 0;				//�`�敝�͈̔͏�����
	RowNum = 0;							//�`��͈͂̒��ŕ`��ł����̐�������
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

	SelectImage = new Image(dir, name);				//�I�����̉摜�𐶐�
	IsCreateSelect = SelectImage->GetIsLoad();		//�摜��ǂݍ��߂����ݒ�
	SelectCode.push_back(code);						//�I�����̃R�[�h�ԍ���ݒ�
	NowSelectCode = SelectCode.begin();				//���ݑI�����Ă���R�[�h�ԍ����ŏ��̑I�����ɐݒ�
}

//�f�X�g���N�^
Select::~Select()
{
	//vector�̃�����������s��
	vector<int> v;				//���vector���쐬����
	SelectCode.swap(v);			//��ƒ��g�����ւ���

}

//�I��������ꂽ���擾
bool Select::GetIsCreateSelect()
{
	return IsCreateSelect;
}

//�I���������擾
bool Select::GetIsChoise()
{
	return IsChoise;
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
�����Fint�F�`��\����
�����Fint�F�I�����̊Ԋu(��)
�����Fint�F�I�����̊Ԋu(�c)�A�f�t�H���g��0
*/
void Select::SetInit(int x, int y, int width,int interval_side,int interval_vertical)
{
	SelectImage->SetInit();	//�摜�����ݒ�

	DrawX = x;				//�`��J�nX�ʒu�ݒ�
	DrawY = y;				//�`��J�nY�ʒu�ݒ�
	DrawWidth_Range = width;//�`�敝�͈̔͂�ݒ�
	Interval_Side = interval_side;	//�I�����̊Ԋu(��)��ݒ�
	Interval_Vertical = interval_vertical;	//�I�����̊Ԋu(�c)��ݒ�

	//�`��͈͂̒��ŕ`��ł����̐����v�Z
	while (true)	//�������[�v
	{

		if (x + SelectImage->GetWidth() + Interval_Side > width)	//�`��\�����𒴂�����
		{
			break;	//���[�v�𔲂���
		}

		x += SelectImage->GetWidth() + Interval_Side;			//X�̈ʒu�����炷
		++RowNum;											//�J�E���g�A�b�v
	}

	return;
}

//������
void Select::Init()
{
	Choise_SelectCode = CHOISE_NONE;			//�I�񂾑I�����̃R�[�h��������
	IsChoise = false;							//�I��������������
	NowSelectCode = SelectCode.begin();			//���ݑI��ł���I����������

	return;
}

//�I������ǉ�
bool Select::Add(const char* dir, const char* name,int code)
{
	IsCreateSelect = SelectImage->AddImage(dir, name);		//�摜��ǉ�
	SelectCode.push_back(code);									//�I�����R�[�h��ݒ�
	NowSelectCode = SelectCode.begin();						//���ݑI�����Ă���R�[�h�ԍ����ŏ��̑I�����ɐݒ�
	return IsCreateSelect;
}

//�`��
void Select::Draw()
{

	int NowDrawX = DrawX, NowDrawY = DrawY;		//���݂̕`��ʒu
	int row_cnt = 0;					//�񐔂̃J�E���g

	for (int i = SelectCode.front(); i <= SelectCode.back(); ++i)		//�I�����̉摜�̐������[�v
	{

		if (row_cnt >= RowNum)		//�񐔂��A�`��ł���͈͂𒴂�����
		{
			NowDrawX = DrawX;											//X�̕`��ʒu���ŏ��̈ʒu��
			NowDrawY += SelectImage->GetHeight() + Interval_Vertical;	//Y�̕`��ʒu���A�摜�̍����{�Ԋu�����ւ��炷
			row_cnt = 0;												//�J�E���g���Z�b�g
		}

		++row_cnt;	//�J�E���g�A�b�v

		if (i == *NowSelectCode)		//���ݑI�����Ă�����̂�������
		{
			//�̈�ݒ�
			rect.left = NowDrawX - RECT_EXPANSION_VALUE;								//����X
			rect.top = NowDrawY - RECT_EXPANSION_VALUE;									//����Y
			rect.right = NowDrawX + SelectImage->GetWidth() + RECT_EXPANSION_VALUE;		//�E��X
			rect.bottom = NowDrawY + SelectImage->GetHeight() + RECT_EXPANSION_VALUE;	//�E��Y

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, RECT_TOUKA_VALUE * TOUKA_MAX_VALUE);	//���߂�����
			DrawBox(rect.left, rect.top, rect.right, rect.bottom, COLOR_WHITE, TRUE);	//�����l�p�`��`��
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//���߂���߂�

			SelectImage->Draw(NowDrawX, NowDrawY);	//�I�����摜��`��
		}
		else		//����ȊO��
		{
			SelectImage->Draw(NowDrawX, NowDrawY);	//�I�����摜��`��
		}

		NowDrawX += SelectImage->GetWidth() + Interval_Side;			//�`��ʒu�����炷
		SelectImage->NextImage();									//���̉摜��

	}

	SelectImage->ChengeImageFront();	//�`�悷��摜��擪�̉摜�ɖ߂�
}

//�L�[����
void Select::Operation(KeyDown* keydown)
{
	if (keydown->IsKeyDownOne(KEY_INPUT_LEFT))	//�����L�[�������ꂽ��
	{
		Prev();	//�O�̑I������
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RIGHT))	//�E���L�[�������ꂽ��
	{
		Next();	//���̑I������
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
		Choise_SelectCode = *NowSelectCode;	//���ݑI�����Ă���I������ݒ�
		IsChoise = true;							//�I������
		Key_se.at((int)SE_KEY_KETTEI)->Play(false);		//����̌��ʉ���炷
	}

	return;

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
	if (*NowSelectCode + value <= SelectCode.back())	//�Ō�̑I��������Ȃ����
	{
		NowSelectCode += value;	//�w�肳�ꂽ���A���̑I������
	}

	return;
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
	if (*NowSelectCode - value >= SelectCode.front())		//�ŏ��̑I��������Ȃ����
	{
		NowSelectCode -= value;	//�w�肳�ꂽ���A�O�̑I������
	}

	return;

}
