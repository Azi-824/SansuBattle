//PLAYER.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "CHARACTOR.hpp"

//##################### �}�N����` #########################
#define IMG_DIR_PLAYER	R"(.\MY_IMG\Player)"		//�v���C���[�̉摜�̃f�B���N�g��

#define IMG_NAME_HP		R"(\hp.png)"				//HP�摜�̖��O

#define PLAYER_HP_DRAW_X		20	//HP�̕`��J�nX�ʒu
#define PLAYER_HP_DRAW_Y		50	//HP�̕`��J�nY�ʒu

//##################### �N���X��` #########################
class PLAYER : public CHARACTOR		//�L�����N�^�[�N���X���p��
{
private:

public:

	PLAYER(const char*, const char*);	//�R���X�g���N�^
	~PLAYER();							//�f�X�g���N�^

	void Draw() override;				//HP��`�悷��

};
