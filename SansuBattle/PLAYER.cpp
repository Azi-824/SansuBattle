//PLAYER.cpp
//�v���C���[���Ǘ�����N���X

//################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "PLAYER.hpp"

//################### �N���X��` ##################

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
PLAYER::PLAYER(const char* dir, const char* name)
{

	//HP�摜���� 
	this->NewImage(dir, name);		//HP�摜�𐶐�
	return;

}

//�f�X�g���N�^
PLAYER::~PLAYER()
{
	return;
}

//HP��`�悷��
void PLAYER::DrawHP()
{
	for (int i = 0; i < this->HP; ++i)		//HP�̕����[�v
	{
		this->image->Draw(this->DrawX + i * this->image->GetWidth(), this->DrawY);	//HP�摜�`��
	}

	return;

}
