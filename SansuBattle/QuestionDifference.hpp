//QuestionDifference.hpp
//�����Z�̖����Ǘ�����N���X

#pragma once

//############## �w�b�_�t�@�C���ǂݍ��� ################
#include "Question.hpp"

//############## �N���X��` ##################
class QuestionDifference :public Question	//Question�N���X�C��
{
public:

	QuestionDifference();		//�R���X�g���N�^
	~QuestionDifference();		//�f�X�g���N�^

	void CreateQuestion(int) override;	//���쐬

};
