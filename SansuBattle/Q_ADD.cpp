//Q_Base.cpp
//�����Z�̖����Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� ##################
#include "Q_Add.hpp"

//################# �N���X��` ####################

//�R���X�g���N�^
Q_Add::Q_Add()
{
	return;
}

//�f�X�g���N�^
Q_Add::~Q_Add()
{
	return;
}

//�����쐬
void Q_Add::CreateQuestion(int gamelevel)
{

	int q_min = 0, q_max = 0;	//���̍ŏ��l�ƍő�l������ϐ�

	switch (gamelevel)	//�Q�[�����x�����ɕ���
	{

	case (int)STAGE_LEVEL_EASY:	//�ȒP�̎�

		q_min = 1;					//�ŏ��l1
		q_max = Q_EASY_VALUE_MAX;	//�ő�l9

		break;	//�ȒP�̎�

	case (int)STAGE_LEVEL_NORMAL:	//���ʂ̎�

		q_min = 10;					//�ŏ��l1
		q_max = 20;	//�ő�l20

		break;	//���ʂ̎�

	case (int)STAGE_LEVEL_HARD:	//����̎�

		q_min = 20;					//�ŏ��l1
		q_max = 30;	//�ő�l30

		break;	//����̎�


	default:
		break;
	}

	int num1 = 0, num2 = 0;		//��������ϐ�

	num1 = GetRand(q_max - q_min) + q_min;			//���𐶐�
	num2 = GetRand(q_max - q_min) + q_min;			//���𐶐�

	this->Anser = num1 + num2;	//���̌v�Z���ʂ𓚂��Ɋi�[
	this->Q_Text = (std::to_string(num1) + "�{" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

	IsCreate = true;	//�����쐬����

	return;

}
