//PLAYER.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "CHARACTOR.hpp"

//##################### �}�N����` #########################
#define IMG_DIR_PLAYER	R"(.\MY_IMG\Player)"		//�v���C���[�̉摜�̃f�B���N�g��

#define IMG_NAME_HP		R"(\hp.png)"				//HP�摜�̖��O

#define HP_INIT_VALUE	5	//HP�̏����l

//##################### �N���X��` #########################
class PLAYER : public CHARACTOR		//�L�����N�^�[�N���X���p��
{
private:

	int HP;							//HP

	bool IsImageLoad;				//�摜��ǂݍ��߂���

public:

	PLAYER(const char*, const char*);	//�R���X�g���N�^
	~PLAYER();							//�f�X�g���N�^

	bool GetIsLoad();					//�ǂݍ��߂����擾

	void SendDamege();					//�_���[�W��^����

};
