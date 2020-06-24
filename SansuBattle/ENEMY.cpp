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

	DrawHp_type = HP_ENEMY;			//HP�̃^�C�v�͓G

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
	for (auto img : image_hp)
	{
		img->SetInit();		//�����ݒ�
	}
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

//�t�F�[�h�A�E�g�I���������擾
bool Enemy::GetFadeEnd()
{
	return image->GetFadeEnd();
}
