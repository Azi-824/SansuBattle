//ScoreAdd.cpp
//�����Z�̃X�R�A���Ǘ�����N���X

//################ �w�b�_�t�@�C���ǂݍ��� ##################
#include "ScoreAdd.hpp"

//################ �N���X��` ##################

//�R���X�g���N�^
ScoreAdd::ScoreAdd()
{

}

//�f�X�g���N�^
ScoreAdd::~ScoreAdd()
{

}

//�X�R�A�v�Z����
//�����Fint�F�񓚂܂łɂ�����������
void ScoreAdd::CalcScore(int time)
{
	int time_excellent = 5;		//�G�N�Z�����g�̕]����̎���
	int time_great = 15;		//�O���[�g�̕]����̎���

	if (time <= time_excellent)	//�G�N�Z�����g�̕]������Z�����
	{
		Score = Score + (100 * 2);
	}
	else if (time <= time_great)//�O���[�g�̕]������Z�����
	{
		Score = Score + (100 * 1.5);
	}
	else						//������x�����
	{
		Score = Score + 100;
	}

}