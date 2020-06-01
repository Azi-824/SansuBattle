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

//HP��`�悷��
void PLAYER::DrawHP()
{
	for (int i = 0; i < this->HP; ++i)		//HP�̕����[�v
	{
		this->image->Draw(this->DrawX + i * this->image->GetWidth(), this->DrawY);	//HP�摜�`��
	}

	return;

}
