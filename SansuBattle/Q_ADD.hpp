//Q_Add.hpp
//�����Z�̖����Ǘ�����N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Question.hpp"

//################# �}�N����` ####################

//################# �N���X��` ####################
class Q_Add :public Question
{
private:


public:

	Q_Add();					//�R���X�g���N�^
	~Q_Add();					//�f�X�g���N�^

	void CreateQuestion(int) override;		//���쐬

};
