//CHARACTOR.hpp
//�L�����N�^�[�N���X

#pragma once

//###################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "DxLib.h"
#include "main.hpp"
#include "KEYDOWN.hpp"


//###################### �}�N����` #######################

//###################### �N���X��` #######################
class CHARACTOR
{
private:

	int DrawX;					//�`��X�ʒu
	int DrawY;					//�`��Y�ʒu

	bool IsArive;				//�����Ă��邩
	bool IsKeyOperation;		//�L�[�{�[�h�ő���ł��邩

public:

	CHARACTOR();				//�R���X�g���N�^
	~CHARACTOR();				//�f�X�g���N�^

	void SetIsArive(bool);		//�����Ă��邩��ݒ�
	void SetKeyOperation(bool); //�L�[�{�[�h�ő���ł��邩�ݒ�

	void SetImagePos(int, int);	//�ʒu��ݒ肷��

	bool GetIsArive();			//�����Ă��邩�擾
	bool GetKeyOperation();		//�L�[�{�[�h�ő���ł��邩�擾

	void Operation(KEYDOWN *);	//����

	bool SetInit();				//�����ݒ�

};

