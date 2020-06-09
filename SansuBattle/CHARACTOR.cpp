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
	this->HP = HP_INIT_VALUE;	//HP������
	this->IsLoad = false;		//�ǂݍ��߂���������

	return;
}

//�f�X�g���N�^
CHARACTOR::~CHARACTOR()
{

	delete this->image;		//image�j��
	return;
}

//�V�����摜��ǂݍ���
void CHARACTOR::NewImage(const char* dir, const char* name)
{
	this->image = new IMAGE(dir, name);		//�摜�I�u�W�F�N�g����
	this->IsLoad = this->image->GetIsLoad();//�ǂݍ��߂����ݒ�
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

//�ǂݍ��߂����擾
bool CHARACTOR::GetIsLoad()
{
	return this->IsLoad;
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

//�_���[�W��^����
void CHARACTOR::SendDamege()
{
	if (this->HP > 0)		//HP��0����Ȃ����
	{
		--this->HP;			//�_���[�W��^����
	}

	return;

}

//�`��
void CHARACTOR::Draw()
{
	image->Draw(DrawX, DrawY);	//�`��
}

//�����ɕ`��
void CHARACTOR::DrawCenter()
{
	image->DrawCenter();		//�����ɕ`��
}