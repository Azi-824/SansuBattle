//Select.cpp
//�I�������Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� #######################
#include "Select.hpp"

//################# �N���X��` ########################

//�C���X�^���X�𐶐�
vector<Music*> Select::Key_se;	//�L�[�{�[�h�̌��ʉ�

//�R���X�g���N�^
Select::Select(vector<Image*>image)
{

	//�����o�[�ϐ�������
	Choise_SelectCode = CHOISE_NONE;	//�I�񂾑I�����̃R�[�h��������
	IsChoise = false;					//�I��������������
	IsBack = false;						//�߂邩������
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
�����Fint�F�`��\����
�����Fint�F�I�����̊Ԋu(��)
�����Fint�F�I�����̊Ԋu(�c)�A�f�t�H���g��0
*/
void Select::SetInit(int x, int y, int width,int interval_side,int interval_vertical)
{
	for (auto img : SelectImage)
	{
		img->SetInit();		//�摜�����ݒ�
	}

	DrawX = x;				//�`��J�nX�ʒu�ݒ�
	DrawY = y;				//�`��J�nY�ʒu�ݒ�
	DrawWidth_Range = width;//�`�敝�͈̔͂�ݒ�
	Interval_Side = interval_side;	//�I�����̊Ԋu(��)��ݒ�
	Interval_Vertical = interval_vertical;	//�I�����̊Ԋu(�c)��ݒ�

	//�`��͈͂̒��ŕ`��ł����̐����v�Z
	while (true)	//�������[�v
	{

		if (x + SelectImage.front()->GetWidth() + Interval_Side > width)	//�`��\�����𒴂�����
		{
			break;	//���[�v�𔲂���
		}

		x += SelectImage.front()->GetWidth() + Interval_Side;			//X�̈ʒu�����炷
		++RowNum;														//�J�E���g�A�b�v
	}

	return;
}

//������
void Select::Init()
{
	Choise_SelectCode = CHOISE_NONE;			//�I�񂾑I�����̃R�[�h��������
	IsChoise = false;							//�I��������������
	IsBack = false;								//�߂邩������
	NowSelectCode = SelectCode.begin();			//���ݑI��ł���I����������

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
	int cnt = 0;

	for (auto img : SelectImage)
	{
		if (row_cnt >= RowNum)		//�񐔂��A�`��ł���͈͂𒴂�����
		{
			NowDrawX = DrawX;									//X�̕`��ʒu���ŏ��̈ʒu��
			NowDrawY += img->GetHeight() + Interval_Vertical;	//Y�̕`��ʒu���A�摜�̍����{�Ԋu�����ւ��炷
			row_cnt = 0;										//�J�E���g���Z�b�g
		}

		++row_cnt;	//�J�E���g�A�b�v

		if (cnt == *NowSelectCode)		//���ݑI�����Ă�����̂�������
		{
			//�̈�ݒ�
			rect.left = NowDrawX - RECT_EXPANSION_VALUE;								//����X
			rect.top = NowDrawY - RECT_EXPANSION_VALUE;									//����Y
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
	else if (keydown->IsKeyDownOne(KEY_INPUT_BACK))		//�o�b�N�X�y�[�X�L�[�������ꂽ��
	{
		IsBack = true;	//�߂�
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
