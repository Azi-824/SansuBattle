//PLAYER.cpp
//�v���C���[���Ǘ�����N���X

//################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "PLAYER.hpp"

//################### �N���X��` ##################

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
PLAYER::PLAYER()
{
	return;
}

//�f�X�g���N�^
PLAYER::~PLAYER()
{
	return;
}

//HP��`�悷��
void PLAYER::DrawHp()
{
	image_hp->ChengeImage((int)HP_PLAYER);	//HP�̉摜�̎�ނ��v���C���[�̉摜��
	for (int i = 0; i < HP; ++i)	//HP�̕����[�v
	{
		image_hp->Draw(PLAYER_HP_DRAW_X + i * image_hp->GetWidth(), PLAYER_HP_DRAW_Y);	//HP�摜�`��
	}
}
