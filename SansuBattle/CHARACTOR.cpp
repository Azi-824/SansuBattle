//Charactor.cpp
//�L�����N�^�[�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #####################
#include "Charactor.hpp"

//################ �N���X��` ########################

//�R���X�g���N�^
Charactor::Charactor()
{
	//�����o�[�ϐ�������
	HP_X = 0;			//HP�`��X�ʒu
	HP_Y = 0;			//HP�`��Y�ʒu
	reverse = false;	//���]�`�悷�邩
	IsArive = true;		//�����Ă��邩������
	HP = HP_INIT_VALUE;	//HP������

	hp_img = new Image();	//�摜�̃C���X�^���X����

}

//�f�X�g���N�^
Charactor::~Charactor()
{
	delete hp_img;	//hp_img�j��
}

//������
void Charactor::Init()
{
	HP = HP_INIT_VALUE;	//HP������
	IsArive = true;		//�����Ă���
}

//�����ݒ�
bool Charactor::SetInit()
{
	if (!hp_img->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	hp_img->SetInit();		//�摜
}

//�����Ă��邩�擾
bool Charactor::GetIsArive()
{
	return IsArive;
}

//�_���[�W��^����
void Charactor::SendDamege()
{
	--HP;	//�_���[�W��^����
	if (HP <= 0)	//HP��0�ȉ��ɂȂ�����
	{
		HP = 0;	//HP��0
		Kill();	//�L�������E��
	}
}

//�L�������E��
void Charactor::Kill()
{
	IsArive = false;
}

//HP�擾
int Charactor::GetHp()
{
	return HP;
}

//�`��
void Charactor::Draw()
{
	for (int i = 0; i < HP; ++i)
	{
		if (reverse)	//���]�`�悷��Ƃ�
		{
			hp_img->Draw(HP_X - i * hp_img->GetWidth(), HP_Y);	//���]�`��
		}
		else	//�ʏ�`��̂Ƃ�
		{
			hp_img->Draw(HP_X + i * hp_img->GetWidth(), HP_Y);	//HP�`��
		}
	}
}
