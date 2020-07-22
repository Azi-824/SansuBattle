//Charactor.cpp
//�L�����N�^�[�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #####################
#include "Charactor.hpp"

//################ �N���X��` ########################

//�C���X�^���X����
vector<Image*> Charactor::image_hp;	//HP�摜

//�R���X�g���N�^
Charactor::Charactor()
{
	//�����o�[�ϐ�������
	DrawX = 0;			//X�ʒu������
	DrawY = 0;			//Y�ʒu������
	IsArive = true;		//�����Ă��邩������
	IsKeyOperation = true;//�L�[����\��������
	HP = HP_INIT_VALUE;	//HP������
	DrawHp_type = -1;	//�`�悷��HP�̎��
	IsLoad = false;		//�ǂݍ��߂���������

	if (image_hp.empty())	//HP�摜���쐬����Ă��Ȃ����
	{
		image_hp.push_back(new Image(IMG_DIR_CHARA, IMG_NAME_PLAYER_HP));//�v���C���[��HP�摜
		image_hp.push_back(new Image(IMG_DIR_CHARA, IMG_NAME_ENEMY_HP));//�v�G��HP�摜
	}

	return;
}

//�f�X�g���N�^
Charactor::~Charactor(){}

//������
void Charactor::Init()
{
	HP = HP_INIT_VALUE;	//HP������
	IsArive = true;		//�����Ă���
}

//�����Ă��邩�ݒ�
void Charactor::SetIsArive(bool Isarive)
{
	IsArive = Isarive;
}

//�����Ă��邩�擾
bool Charactor::GetIsArive()
{
	return IsArive;
}

//�ǂݍ��߂����擾
bool Charactor::GetIsLoad()
{
	return IsLoad;
}

//�����ݒ�
void Charactor::SetInit(int x,int y)
{
	for (auto img : image_hp)
	{
		img->SetInit();	//�����ݒ�
	}
	DrawX = x;				//�`��X�ʒu
	DrawY = y;				//�`��Y�ʒu
	IsArive = true;			//�����Ă���
	IsKeyOperation = true;	//�L�[�{�[�h����ł���

}

//�_���[�W��^����
void Charactor::SendDamege()
{
	if (HP > 0)		//HP��0����Ȃ����
	{
		--HP;			//�_���[�W��^����
	}

}

//HP�擾
int Charactor::GetHp()
{
	return HP;
}

//HP�`��
void Charactor::DrawHp()
{
	for (int i = 0; i < HP; ++i)	//HP�̕����[�v
	{
		image_hp.at(DrawHp_type)->Draw(DrawX + i * image_hp.at(DrawHp_type)->GetWidth(), DrawY);	//HP�摜�`��
	}

}
