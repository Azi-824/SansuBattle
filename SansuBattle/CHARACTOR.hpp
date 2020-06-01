//CHARACTOR.hpp
//�L�����N�^�[�N���X

#pragma once

//###################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "DxLib.h"
#include "main.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"

//###################### �}�N����` #######################
#define HP_INIT_VALUE	5	//HP�̏����l

//###################### �N���X��` #######################
class CHARACTOR
{
protected:

	IMAGE* image;				//�摜

	int DrawX;					//�`��X�ʒu
	int DrawY;					//�`��Y�ʒu

	int HP;						//HP

	bool IsArive;				//�����Ă��邩
	bool IsKeyOperation;		//�L�[�{�[�h�ő���ł��邩
	bool IsLoad;				//�ǂݍ��߂���

public:

	CHARACTOR();				//�R���X�g���N�^
	~CHARACTOR();				//�f�X�g���N�^

	void NewImage(const char*, const char*);	//�V�����摜��ǂݍ���

	void SetIsArive(bool);		//�����Ă��邩��ݒ�
	void SetKeyOperation(bool); //�L�[�{�[�h�ő���ł��邩�ݒ�

	void SetImagePos(int, int);	//�ʒu��ݒ肷��

	bool GetIsArive();			//�����Ă��邩�擾
	bool GetKeyOperation();		//�L�[�{�[�h�ő���ł��邩�擾
	bool GetIsLoad();			//�ǂݍ��߂����擾

	void Operation(KEYDOWN *);	//����

	bool SetInit(int,int);		//�����ݒ�

	void SendDamege();			//�_���[�W��^����

};

