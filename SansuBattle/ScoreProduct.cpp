//ScoreProduct.cpp
//�|���Z�̃X�R�A���Ǘ�����N���X

//################ �w�b�_�t�@�C���ǂݍ��� ##################
#include "ScoreProduct.hpp"

//################ �N���X��` ##################

//�R���X�g���N�^
ScoreProduct::ScoreProduct() {}

//�f�X�g���N�^
ScoreProduct::~ScoreProduct() {}

//�X�R�A�v�Z����
//�����Fint�F�Q�[�����x��
//�����Fint�F�񓚂܂łɂ�����������
void ScoreProduct::CalcScore(int gamelevel, int time)
{
	const int time_excellent = 5;		//�G�N�Z�����g�̕]����̎���(5�b�ȓ�)
	const int time_great = 15;			//�O���[�g�̕]����̎���(15�b�ȓ�)
	int addscore_value = 0;				//���Z�����X�R�A

	if (time <= time_excellent)	//�G�N�Z�����g�̕]������Z�����
	{
		addscore_value = SCORE_PRODUCT_ANSER * TIME_BONUS_EXCELLENT;	//�G�N�Z�����g�̃{�[�i�X�������Čv�Z
	}
	else if (time <= time_great)//�O���[�g�̕]������Z�����
	{
		addscore_value = SCORE_PRODUCT_ANSER * TIME_BONUS_GREAT;		//�O���[�g�̃{�[�i�X�������Čv�Z
	}
	else						//������x�����
	{
		addscore_value = SCORE_PRODUCT_ANSER;	//�{�[�i�X�Ȃ��Ōv�Z
	}

	switch (gamelevel)	//�Q�[�����x����
	{

	case (int)STAGE_LEVEL_EASY:		//�ȒP�̂Ƃ�

		addscore_value *= LEVEL_BONUS_EASY;	//�ȒP�̃��x���{�[�i�X����Z

		break;	//�ȒP�̎������܂�

	case (int)STAGE_LEVEL_NORMAL:		//���ʂ̂Ƃ�

		addscore_value *= LEVEL_BONUS_NORMAL;	//���ʂ̃��x���{�[�i�X����Z

		break;	//���ʂ̎������܂�

	case (int)STAGE_LEVEL_HARD:		//����̂Ƃ�

		addscore_value *= LEVEL_BONUS_HARD;	//����̃��x���{�[�i�X����Z

		break;	//����̎������܂�

	default:
		break;
	}

	score += addscore_value;	//�X�R�A���Z

}