//Player.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Charactor.hpp"

//##################### �}�N����` #########################
#define IMG_DIR_PLAYER	R"(.\MY_IMG\Player)"		//�v���C���[�̉摜�̃f�B���N�g��

#define IMG_NAME_HP		R"(\hp.png)"				//HP�摜�̖��O

#define PLAYER_HP_DRAW_X		20	//HP�̕`��J�nX�ʒu
#define PLAYER_HP_DRAW_Y		50	//HP�̕`��J�nY�ʒu

//##################### �N���X��` #########################
class Player : public Charactor		//�L�����N�^�[�N���X���p��
{
private:

public:

	Player();	//�R���X�g���N�^
	~Player();							//�f�X�g���N�^

	void DrawHp() override;		//HP��`�悷��

};
