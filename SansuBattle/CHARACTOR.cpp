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

	delete this->image;		//image�j��
	return;
}

//�V�����摜��ǂݍ���
bool CHARACTOR::NewImage(const char* dir, const char* name)
{
	this->image = new IMAGE(dir, name);		//�摜�I�u�W�F�N�g����
	return this->image->GetIsLoad();		//�ǂݍ��߂����擾
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
bool CHARACTOR::SetInit(int x,int y)
{

	this->image->SetInit();			//�摜�����ݒ�
	this->DrawX = x;				//�`��X�ʒu
	this->DrawY = y;				//�`��Y�ʒu
	this->IsArive = true;			//�����Ă���
	this->IsKeyOperation = true;	//�L�[�{�[�h����ł���

	return true;

}

////�摜��`��
//void CHARACTOR::DrawImage()
//{
//	this->image->Draw(this->DrawX, this->DrawY);
//	return;
//}
