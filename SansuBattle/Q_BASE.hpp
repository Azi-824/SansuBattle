//Q_BASE.hpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ###############
#include "DxLib.h"
#include <string>

//################# �}�N����` #################
#define Q_DRAW_X 30		//���̕`��X�ʒu
#define Q_DRAW_Y 30		//���̕`��Y�ʒu
//################# �N���X��` #################
class Q_BASE
{
protected:

	std::string Q_Text;			//��蕶
	int Anser;					//����

public:

	Q_BASE();							//�R���X�g���N�^
	~Q_BASE();							//�f�X�g���N�^

	void DrawQuestion();				//����`�悷��

	bool JudgAnser(int);				//���������肷��

};
