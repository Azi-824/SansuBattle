//QuestionAdd.hpp
//�����Z�̖����Ǘ�����N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Question.hpp"

//################# �}�N����` ####################

//################# �N���X��` ####################
class QuestionAdd :public Question
{
private:


public:

	QuestionAdd();					//�R���X�g���N�^
	~QuestionAdd();					//�f�X�g���N�^

	void CreateQuestion(int) override;		//���쐬

};
