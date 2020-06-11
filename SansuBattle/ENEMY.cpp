//ENEMY.cpp
//�G���Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "ENEMY.hpp"

//############### �N���X��` #####################

//�C���X�^���X�𐶐�
int ENEMY::NowEnemyNum = 0;

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
ENEMY::ENEMY(const char* dir, const char* name)
{
	//�摜����
	image = new IMAGE(dir, name);	//�摜����
	IsLoad = image->GetIsLoad();	//�ǂݍ��߂���

	return;
}

//�f�X�g���N�^
ENEMY::~ENEMY()
{
	delete image;	//image�j��
	return;
}

//�����ݒ�
void ENEMY::SetInit(int x, int y)
{
	image->SetInit();		//�G�L�����摜�����ݒ�
	image_hp->SetInit();	//HP�摜�����ݒ�
	DrawX = x;				//�`��X�ʒu
	DrawY = y;				//�`��Y�ʒu
	IsArive = true;			//�����Ă���
	IsKeyOperation = true;	//�L�[�{�[�h����ł���

}

//������
void ENEMY::Init()
{
	NowEnemyNum = 0;	//���݂̓G�̐���������
	HP = HP_INIT_VALUE;	//HP������
	IsArive = true;		//�����Ă���
}

//���̓G��
void ENEMY::NextEnemy()
{
	if (NowEnemyNum < ENEMY_MAX)	//���݂̓G���A�G�̍ő吔��菭�Ȃ����
	{
		++NowEnemyNum;				//���̓G��
	}
}

//���݉��̖ڂ̓G���擾
int ENEMY::GetNowEnemyNum()
{
	return NowEnemyNum;
}

//�`��
void ENEMY::Draw()
{
	image->Draw(DrawX, DrawY);	//�`��
}

//�����ɕ`��
void ENEMY::DrawCenter()
{
	image->DrawCenter();		//�����ɕ`��
}

//HP�`��
void ENEMY::DrawHp()
{
	image_hp->ChengeImage((int)HP_ENEMY);	//HP�̉摜�̎�ނ�G�̉摜��
	for (int i = 0; i < HP; ++i)	//HP�̕����[�v
	{
		image_hp->Draw(ENEMY_HP_DRAW_X + i * image_hp->GetWidth(), ENEMY_HP_DRAW_Y);	//HP�摜�`��
	}

}
