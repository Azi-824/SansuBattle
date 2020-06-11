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
	this->NewImage(dir, name);

	return;
}

//�f�X�g���N�^
ENEMY::~ENEMY()
{
	return;
}

//���̓G��
void ENEMY::NextEnemy()
{
	if (NowEnemyNum < ENEMY_MAX)	//���݂̓G���A�G�̍ő吔��菭�Ȃ����
	{
		++NowEnemyNum;				//���̓G��
	}
}

//���݂̓G��������
void ENEMY::ResetNowEnemy()
{
	NowEnemyNum = 0;
}

//���݉��̖ڂ̓G���擾
int ENEMY::GetNowEnemyNum()
{
	return NowEnemyNum;
}
