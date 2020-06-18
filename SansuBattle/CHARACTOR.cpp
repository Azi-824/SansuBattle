//Charactor.cpp
//�L�����N�^�[�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #####################
#include "Charactor.hpp"

//################ �N���X��` ########################

//�C���X�^���X����
Image* Charactor::image_hp;	//HP�摜

//�R���X�g���N�^
Charactor::Charactor()
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
		image_hp = new Image(IMG_DIR_CHARA, IMG_NAME_PLAYER_HP);	//�v���C���[��HP�摜
		image_hp->AddImage(IMG_DIR_CHARA, IMG_NAME_ENEMY_HP);		//�G��HP�摜
	}

	return;
}

//�f�X�g���N�^
Charactor::~Charactor()
{
	return;
}

//������
void Charactor::Init()
{
	HP = HP_INIT_VALUE;	//HP������
	IsArive = true;		//�����Ă���
}

//�����Ă��邩�ݒ�
void Charactor::SetIsArive(bool Isarive)
{
	this->IsArive = Isarive;
	return;
}

//�����Ă��邩�擾
bool Charactor::GetIsArive()
{
	return this->IsArive;
}

//�ǂݍ��߂����擾
bool Charactor::GetIsLoad()
{
	return this->IsLoad;
}

//�������ݒ�
void Charactor::SetInit(int x,int y)
{

	image_hp->SetInit();	//HP�摜�����ݒ�
	DrawX = x;				//�`��X�ʒu
	DrawY = y;				//�`��Y�ʒu
	IsArive = true;			//�����Ă���
	IsKeyOperation = true;	//�L�[�{�[�h����ł���

}

//�_���[�W��^����
void Charactor::SendDamege()
{
	if (this->HP > 0)		//HP��0����Ȃ����
	{
		--this->HP;			//�_���[�W��^����
	}

	return;

}

//HP�擾
int Charactor::GetHp()
{
	return HP;
}