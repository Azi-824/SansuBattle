//CHARACTOR.cpp
//�L�����N�^�[�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #####################
#include "CHARACTOR.hpp"

//################ �N���X��` ########################
//�R���X�g���N�^
CHARACTOR::CHARACTOR()
{
	//�����o�[�ϐ�������
	this->DrawX = 0;			//X�ʒu������
	this->DrawY = 0;			//Y�ʒu������
	this->IsArive = true;		//�����Ă��邩������
	this->IsKeyOperation = true;//�L�[����\��������

	return;
}

//�f�X�g���N�^
CHARACTOR::~CHARACTOR()
{
	return;
}

//�����Ă��邩�ݒ�
void CHARACTOR::SetIsArive(bool Isarive)
{
	this->IsArive = Isarive;
	return;
}

//�L�[�{�[�h�ő���ł��邩�ݒ�
void CHARACTOR::SetKeyOperation(bool Iskeyoperation)
{
	this->IsKeyOperation = IsKeyOperation;
	return;
}

//�ʒu��ݒ肷��
void CHARACTOR::SetImagePos(int x, int y)
{
	this->DrawX = x;	
	this->DrawY = y;
	return;
}

//�����Ă��邩�擾
bool CHARACTOR::GetIsArive()
{
	return this->IsArive;
}

//�L�[�{�[�h����ł��邩�擾
bool CHARACTOR::GetKeyOperation()
{
	return this->IsKeyOperation;
}

//����
void CHARACTOR::Operation(KEYDOWN *keydown)
{
	return;
}

//�������ݒ�
bool CHARACTOR::SetInit()
{

	this->IsArive = true;			//�����Ă���
	this->IsKeyOperation = true;	//�L�[�{�[�h����ł���

	return true;

}
