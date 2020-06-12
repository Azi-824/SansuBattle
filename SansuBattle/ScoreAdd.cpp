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
	const int time_excellent = 5;		//�G�N�Z�����g�̕]����̎���(5�b�ȓ�)
	const int time_great = 15;			//�O���[�g�̕]����̎���(15�b�ȓ�)

	if (time <= time_excellent)	//�G�N�Z�����g�̕]������Z�����
	{
		Score = Score + (SCOREADD_SCORE_ANSER * TIME_BONUS_EXCELLENT);	//�G�N�Z�����g�̃{�[�i�X�������Čv�Z
	}
	else if (time <= time_great)//�O���[�g�̕]������Z�����
	{
		Score = Score + (SCOREADD_SCORE_ANSER * TIME_BONUS_GREAT);		//�O���[�g�̃{�[�i�X�������Čv�Z
	}
	else						//������x�����
	{
		Score = Score + SCOREADD_SCORE_ANSER;	//�{�[�i�X�Ȃ��Ōv�Z
	}

}