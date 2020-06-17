//Enemy.cpp
//�G���Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Enemy.hpp"

//############### �N���X��` #####################

//�C���X�^���X�𐶐�
int Enemy::NowEnemyNum = 0;

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
Enemy::Enemy(const char* dir, const char* name)
{
	//�摜����
	image = new Image(dir, name);	//�摜����
	IsLoad = image->GetIsLoad();	//�ǂݍ��߂���

	return;
}

//�f�X�g���N�^
Enemy::~Enemy()
{
	delete image;	//image�j��
	return;
}

//�����ݒ�
void Enemy::SetInit(int x, int y)
{
	image->SetInit();		//�G�L�����摜�����ݒ�
	image_hp->SetInit();	//HP�摜�����ݒ�
	DrawX = x;				//�`��X�ʒu
	DrawY = y;				//�`��Y�ʒu
	IsArive = true;			//�����Ă���
	IsKeyOperation = true;	//�L�[�{�[�h����ł���

}

//������
void Enemy::Init()
{
	NowEnemyNum = 0;	//���݂̓G�̐���������
	HP = HP_INIT_VALUE;	//HP������
	IsArive = true;		//�����Ă���
	image->SetIsFade(false);	//�t�F�[�h�A�E�g���Ȃ��B
}

//���̓G��
void Enemy::NextEnemy()
{
	if (NowEnemyNum < ENEMY_MAX)	//���݂̓G���A�G�̍ő吔��菭�Ȃ����
	{
		++NowEnemyNum;				//���̓G��
	}
}

//���݉��̖ڂ̓G���擾
int Enemy::GetNowEnemyNum()
{
	return NowEnemyNum;
}

//�`��
void Enemy::Draw()
{
	image->Draw(DrawX, DrawY);	//�`��
}

//�����ɕ`��
void Enemy::DrawCenter()
{
	if (IsArive)	//�����Ă����
	{
		image->DrawCenter();		//�����ɕ`��
	}
	else			//����ł����
	{
		image->SetIsFade(true);	//�t�F�[�h�A�E�g�J�n
		image->DrawCenter();	//�����ɕ`��
	}
}

//HP�`��
void Enemy::DrawHp()
{
	image_hp->ChengeImage((int)HP_ENEMY);	//HP�̉摜�̎�ނ�G�̉摜��
	for (int i = 0; i < HP; ++i)	//HP�̕����[�v
	{
		image_hp->Draw(ENEMY_HP_DRAW_X + i * image_hp->GetWidth(), ENEMY_HP_DRAW_Y);	//HP�摜�`��
	}

}

//�t�F�[�h�A�E�g�I���������擾
bool Enemy::GetFadeEnd()
{
	return image->GetFadeEnd();
}
