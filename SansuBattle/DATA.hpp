//DATA..hpp
//�f�[�^���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"

//################### �}�N����` #####################

//################### �N���X��` #####################
class DATA
{

private:

	int Year;		//�N
	int Month;		//��
	int Day;		//��
	int Score;		//�X�R�A

public:

	DATA(int,int,int,int);			//�R���X�g���N�^
	~DATA();						//�f�X�g���N�^

	int GetYear();		//�N�擾
	int GetMonth();		//���擾
	int GetDay();		//���擾
	int GetScore();		//�X�R�A�擾

};
