//PLAYER.cpp
//�v���C���[���Ǘ�����N���X

//################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "PLAYER.hpp"

//################### �N���X��` ##################

//�R���X�g���N�^
PLAYER::PLAYER(const char* dir, const char* name)
{
	//�����o�[�ϐ�������
	this->HP = HP_INIT_VALUE;		//HP������

	//HP�摜���� 
	this->IsImageLoad = this->NewImage(dir, name);		//HP�摜�𐶐�
	return;

}

//�f�X�g���N�^
PLAYER::~PLAYER()
{
	return;
}

//�ǂݍ��߂����擾
bool PLAYER::GetIsLoad()
{
	return this->IsImageLoad;
}

//�_���[�W��^����
void PLAYER::SendDamege()
{
	if (this->HP > 0)		//HP��0����Ȃ����
	{
		--this->HP;			//�_���[�W��^����
	}

	return;

}
