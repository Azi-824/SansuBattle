//ENEMY.cpp
//�G���Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "ENEMY.hpp"

//############### �N���X��` #####################

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
ENEMY::ENEMY(const char* dir, const char* name)
{
	//�摜����
	this->NewImage(dir, name);

	return;
}

//�f�X�g���N�^
ENEMY::~ENEMY()
{
	return;
}

//�摜�`��
void ENEMY::DrawImage()
{
	this->image->Draw(this->DrawX, this->DrawY);	//�摜��`��
	return;
}
