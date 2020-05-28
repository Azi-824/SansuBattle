//SELECT.cpp
//�I�������Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� #######################
#include "SELECT.hpp"

//################# �N���X��` ########################

//�R���X�g���N�^
SELECT::SELECT(const char* dir, const char* name,int code)
{

	//�����o�[�ϐ�������
	this->Choise_SelectCode = CHOISE_NONE;		//�I�񂾑I�����̃R�[�h��������
	this->IsChoise = false;						//�I��������������
	this->DrawX = 0;							//�`��J�nX�ʒu������
	this->DrawY = 0;							//�`��J�nY�ʒu������
	this->DrawWidth_Range = 0;					//�`�敝�͈̔͏�����
	this->RowNum = 0;							//�`��͈͂̒��ŕ`��ł����̐�������

	this->SelectImage = new IMAGE(dir, name);					//�I�����̉摜�𐶐�
	this->IsCreateSelect = this->SelectImage->GetIsLoad();		//�摜��ǂݍ��߂����ݒ�
	this->SelectCode.push_back(code);							//�I�����̃R�[�h�ԍ���ݒ�
	this->NowSelectCode = this->SelectCode.begin();				//���ݑI�����Ă���R�[�h�ԍ����ŏ��̑I�����ɐݒ�

	return;
}

//�f�X�g���N�^
SELECT::~SELECT()
{
	//vector�̃�����������s��
	std::vector<int> v;				//���vector���쐬����
	this->SelectCode.swap(v);		//��ƒ��g�����ւ���

	return;

}

//�I��������ꂽ���擾
bool SELECT::GetIsCreateSelect()
{
	return this->IsCreateSelect;
}

//�I���������擾
bool SELECT::GetIsChoise()
{
	return this->IsChoise;
}

//�����ݒ�
void SELECT::SetInit(int x, int y, int width)
{
	this->SelectImage->SetInit();	//�摜�����ݒ�

	this->DrawX = x;				//�`��J�nX�ʒu�ݒ�
	this->DrawY = y;				//�`��J�nY�ʒu�ݒ�
	this->DrawWidth_Range = width;	//�`�敝�͈̔͂�ݒ�

	int NowX = x;

	//�`��͈͂̒��ŕ`��ł����̐����v�Z
	while (true)	//�������[�v
	{

		if (NowX + this->SelectImage->GetWidth() + SELECT_INTERVAL > width)	//�`��\�����𒴂�����
		{
			break;	//���[�v�𔲂���
		}

		NowX += this->SelectImage->GetWidth() + SELECT_INTERVAL;	//X�̈ʒu�����炷
		++this->RowNum;		//�J�E���g�A�b�v
	}

	return;
}

//�I������ǉ�
bool SELECT::Add(const char* dir, const char* name,int code)
{
	this->IsCreateSelect = this->SelectImage->AddImage(dir, name);		//�摜��ǉ�
	this->SelectCode.push_back(code);									//�I�����R�[�h��ݒ�
	this->NowSelectCode = this->SelectCode.begin();						//���ݑI�����Ă���R�[�h�ԍ����ŏ��̑I�����ɐݒ�
	return this->IsCreateSelect;
}

//�`��
/*
�����Fint�F�`��J�nX�ʒu
�����Fint�F�`��J�nY�ʒu
�����Fint�F�`��\����
*/
void SELECT::Draw(int x, int y, int width)
{

	int NowDrawX = x, NowDrawY = y;		//���݂̕`��ʒu
	//int NowDrawX = this->DrawX, NowDrawY = this->DrawY;		//���݂̕`��ʒu
	int over_cnt = 0;					//�`�敝�𒴂����񐔂��J�E���g
	int row_cnt = 0;					//�񐔂̃J�E���g

	for (int i = this->SelectCode.front(); i <= this->SelectCode.back(); ++i)		//�I�����̉摜�̐������[�v
	{

		if (row_cnt >= this->RowNum)		//�񐔂��A�`��ł���͈͂𒴂�����
		{
			++over_cnt;		//�J�E���g�A�b�v
			NowDrawX = x;	//X�̕`��ʒu���ŏ��̈ʒu��
			NowDrawY = y + (this->SelectImage->GetHeight() + SELECT_INTERVAL) * over_cnt;	//Y�̕`��ʒu���A�摜�̍����{�Ԋu�����ւ��炷
			row_cnt = 0;	//�J�E���g���Z�b�g
		}

		++row_cnt;	//�J�E���g�A�b�v

		if (i == *this->NowSelectCode)		//���ݑI�����Ă�����̂�������
		{
			//��ŏC��
			DrawBox(NowDrawX - 10, NowDrawY - 10, NowDrawX + 10, NowDrawY + 10, GetColor(255, 255, 255), TRUE);		//����Ɏl�p�`��`��
			this->SelectImage->Draw(NowDrawX, NowDrawY);	//�I�����摜��`��
		}
		else		//����ȊO��
		{
			this->SelectImage->Draw(NowDrawX, NowDrawY);	//�I�����摜��`��
		}

		NowDrawX += this->SelectImage->GetWidth() + SELECT_INTERVAL;	//�`��ʒu�����炷
		this->SelectImage->NextImage();					//���̉摜��

	}

	this->SelectImage->ChengeImageFront();	//�`�悷��摜��擪�̉摜�ɖ߂�
}

//�L�[����
void SELECT::Operation(KEYDOWN* keydown)
{
	if (keydown->IsKeyDownOne(KEY_INPUT_LEFT))	//�����L�[�������ꂽ��
	{
		this->Prev();	//�O�̑I������
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RIGHT))	//�E���L�[�������ꂽ��
	{
		this->Next();	//���̑I������
	}
	else if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))	//�G���^�[�L�[�������ꂽ��
	{
		this->Choise_SelectCode = *this->NowSelectCode;	//���ݑI�����Ă���I������ݒ�
		this->IsChoise = true;							//�I������
	}

	return;

}

//���̑I������
void SELECT::Next()
{
	if (this->NowSelectCode < this->SelectCode.end() - 1)	//�Ō�̑I��������Ȃ����
	{
		++this->NowSelectCode;	//���̑I������
	}

	return;
}

//�O�̑I������
void SELECT::Prev()
{
	if (this->NowSelectCode > this->SelectCode.begin())		//�ŏ��̑I��������Ȃ����
	{
		--this->NowSelectCode;	//�O�̑I������
	}
}
