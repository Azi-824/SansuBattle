//QuestionProduct.hpp
//�|���Z�̖����Ǘ�����N���X

#pragma once

//############## �w�b�_�t�@�C���ǂݍ��� ###############
#include "Question.hpp"

//############## �N���X��` #############
class QuestionProduct :public Question	//Question�N���X�C��
{
public:

	QuestionProduct();		//�R���X�g���N�^
	~QuestionProduct();		//�f�X�g���N�^

	void CreateQuestion(int) override;	//���쐬

};

