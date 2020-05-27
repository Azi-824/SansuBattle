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
void SELECT::SetInit()
{
	this->SelectImage->SetInit();	//�摜�����ݒ�
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

	for (int i = this->SelectCode.front(); i <= this->SelectCode.back(); ++i)		//�I�����̉摜�̐������[�v
	{
		if (NowDrawX + this->SelectImage->GetWidth() + SELECT_INTERVAL > width)	//�`��\�����𒴂�����
		{
			NowDrawX = x;	//X�̕`��ʒu���ŏ��̈ʒu��
			NowDrawY = y + this->SelectImage->GetHeight() + SELECT_INTERVAL;	//Y�̕`��ʒu���A�摜�̍����{�Ԋu�����ւ��炷
		}

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
