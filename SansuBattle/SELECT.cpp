//SELECT.cpp
//�I�������Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� #######################
#include "SELECT.hpp"

//################# �N���X��` ########################

//�R���X�g���N�^
SELECT::SELECT(const char* dir, const char* name,int code)
{

	//�����o�[�ϐ�������
	this->Choise_SelectCode = -1;		//�I�񂾑I�����̃R�[�h��������
	this->IsChoise = false;				//�I��������������

	this->SelectImage = new IMAGE(dir, name);					//�I�����̉摜�𐶐�
	this->IsCreateSelect = this->SelectImage->GetIsLoad();		//�摜��ǂݍ��߂����ݒ�
	this->SelectCode.push_back(code);							//�I�����̃R�[�h�ԍ���ݒ�

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

	for (int i = 0; i < this->SelectImage->GetSize(); ++i)		//�I�����̉摜�̐������[�v
	{
		if (NowDrawX + this->SelectImage->GetWidth() + SELECT_INTERVAL > width)	//�`��\�����𒴂�����
		{
			NowDrawX = x;	//X�̕`��ʒu���ŏ��̈ʒu��
			NowDrawY = y + this->SelectImage->GetHeight() + SELECT_INTERVAL;	//Y�̕`��ʒu���A�摜�̍����{�Ԋu�����ւ��炷
		}

		this->SelectImage->Draw(NowDrawX, NowDrawY);	//�I�����摜��`��

		NowDrawX += this->SelectImage->GetWidth() + SELECT_INTERVAL;	//�`��ʒu�����炷
		this->SelectImage->NextImage();					//���̉摜��

	}

	this->SelectImage->ChengeImageFront();	//�`�悷��摜��擪�̉摜�ɖ߂�
}
