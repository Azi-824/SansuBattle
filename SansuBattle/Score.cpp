//Score.cpp
//�X�R�A�֌W�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Score.hpp"

//################# �N���X��` ##################

//�R���X�g���N�^
Score::Score()
{
	score = 0;	//score������
}

//�f�X�g���N�^
Score::~Score()
{

}

//���݂̃X�R�A�\��
void Score::DrawNowScore()
{
	int Strlen = strlen(std::to_string(score).c_str());						//������̒������擾
	int Width = GetDrawStringWidthToHandle(std::to_string(score).c_str(), Strlen, NowFontHandle);	//�����擾

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), GAME_TOP, COLOR_WHITE, NowFontHandle, "%d", score);		//�X�R�A�\��
}

//�X�R�A�v�Z
void Score::CalcScore(int gamemode, int gamelevel, int time)
{

	int add_value = 0;	//���Z�����X�R�A

	//*************** ���Z������X�R�A�ʂ̐ݒ� ***********************
	switch (gamemode)	//�Q�[�����[�h��
	{

	case Q_MODE_SUM:	//�����Z�̎�

		add_value = SCORE_ADD_ANSER;	//�����Z�̃X�R�A���A���Z�����ʂɐݒ�

		break;			//�����Z�̎������܂�

	case Q_MODE_DIFFERENCE:	//�����Z�̎�

		add_value = SCORE_DIFFERENCE_ANSER;	//�����Z�̃X�R�A���A���Z�����ʂɐݒ�

		break;			//�����Z�̎������܂�

	case Q_MODE_PRODUCT:	//�|���Z�̎�

		add_value = SCORE_PRODUCT_ANSER;	//�|���Z�̃X�R�A���A���Z�����ʂɐݒ�

		break;			//�|���Z�̎������܂�

	default:
		break;
	}

	const int time_excellent = 5;		//�G�N�Z�����g�̕]����̎���(5�b�ȓ�)
	const int time_great = 15;			//�O���[�g�̕]����̎���(15�b�ȓ�)

	if (time <= time_excellent)	//�G�N�Z�����g�̕]������Z�����
	{
		add_value *= TIME_BONUS_EXCELLENT;	//�G�N�Z�����g�̃{�[�i�X�������Čv�Z
	}
	else if (time <= time_great)//�O���[�g�̕]������Z�����
	{
		add_value *= TIME_BONUS_GREAT;		//�O���[�g�̃{�[�i�X�������Čv�Z
	}

	switch (gamelevel)	//�Q�[�����x����
	{

	case (int)STAGE_LEVEL_EASY:		//�ȒP�̂Ƃ�

		add_value *= LEVEL_BONUS_EASY;	//�ȒP�̃��x���{�[�i�X����Z

		break;	//�ȒP�̎������܂�

	case (int)STAGE_LEVEL_NORMAL:		//���ʂ̂Ƃ�

		add_value *= LEVEL_BONUS_NORMAL;	//���ʂ̃��x���{�[�i�X����Z

		break;	//���ʂ̎������܂�

	case (int)STAGE_LEVEL_HARD:		//����̂Ƃ�

		add_value *= LEVEL_BONUS_HARD;	//����̃��x���{�[�i�X����Z

		break;	//����̎������܂�

	default:
		break;
	}

	score += add_value;	//�X�R�A���Z

}

//�X�R�A���Z�b�g
void Score::ResetScore()
{
	score = 0;	//�X�R�A���Z�b�g
}

//�X�R�A�擾
int Score::GetScore()
{
	return score;
}