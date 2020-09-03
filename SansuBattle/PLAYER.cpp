//Player.cpp
//�v���C���[���Ǘ�����N���X

//################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Player.hpp"

//################### �N���X��` ##################

//�R���X�g���N�^
Player::Player()
{
	hp_img->Load(IMG_DIR_PLAYER, IMG_NAME_HP);	//HP�摜����
	HP_X = 0;//HP�`��X�ʒu
	HP_Y = 0;//HP�`��Y�ʒu
	reverse = false;			//���]�`�悷�邩
}

//�f�X�g���N�^
Player::~Player(){}

//�����ݒ�
bool Player::SetInit()
{
	if (!hp_img->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	hp_img->SetInit();	//�摜�����ݒ�
	HP_X = GAME_WIDTH - hp_img->GetWidth();	//HP�`��X�ʒu
	HP_Y = PLAYER_HP_DRAW_Y;				//HP�`��Y�ʒu
	reverse = true;	//���]�`��
	return true;	//�ǂݍ��ݐ���
}
