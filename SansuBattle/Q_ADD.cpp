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
void Q_Add::CreateQuestion()
{
	int num1 = 0, num2 = 0;		//��������ϐ�

	num1 = GetRand(Q_EASY_VALUE_MAX);			//���𐶐�
	num2 = GetRand(Q_EASY_VALUE_MAX);			//���𐶐�

	this->Anser = num1 + num2;	//���̌v�Z���ʂ𓚂��Ɋi�[
	this->Q_Text = (std::to_string(num1) + "�{" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

	IsCreate = true;	//�����쐬����

	return;

}
