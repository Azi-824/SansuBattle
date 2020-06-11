//CHARACTOR.cpp
//�L�����N�^�[�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #####################
#include "CHARACTOR.hpp"

//################ �N���X��` ########################

//�C���X�^���X����
IMAGE* CHARACTOR::image_hp;

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

	if (image_hp == NULL)	//HP�摜���쐬����Ă��Ȃ����
	{
		image_hp = new IMAGE(IMG_DIR_CHARA, IMG_NAME_PLAYER_HP);	//�v���C���[��HP�摜
		image_hp->AddImage(IMG_DIR_CHARA, IMG_NAME_ENEMY_HP);		//�G��HP�摜
	}

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
void CHARACTOR::SetInit(int x,int y)
{

	image_hp->SetInit();	//HP�摜�����ݒ�
	DrawX = x;				//�`��X�ʒu
	DrawY = y;				//�`��Y�ʒu
	IsArive = true;			//�����Ă���
	IsKeyOperation = true;	//�L�[�{�[�h����ł���

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

//HP�擾
int CHARACTOR::GetHp()
{
	return HP;
}