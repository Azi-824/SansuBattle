//Score.cpp
//�X�R�A���Ǘ�����N���X

//############ �w�b�_�t�@�C���ǂݍ��� ############
#include "Score.hpp"

//############ �N���X��` ################

int Score::score = 0;	//�X�R�A

//�X�R�A�e�[�u��
vector<int> Score::ScoreTable = { SCORE_SUM_ANSER ,			//�����Z�̎��̃X�R�A
								  SCORE_DIFFERENCE_ANSER,	//�����Z�̎��̃X�R�A
								  SCORE_PRODUCT_ANSER,		//�|���Z�̎��̃X�R�A
								  SCORE_DEALER_ANSER,		//����Z�̎��̃X�R�A
								  SCORE_SUM_DIF_ANSER,		//�����Z�A�����Z�̎��̃X�R�A
								  SCORE_PRO_DEA_ANSER,		//�|���Z�A����Z�̎��̃X�R�A
								  SCORE_SUM_PRO_ANSER,		//+*�̎��̃X�R�A
								  SCORE_SUM_DEA_ANSER,		//+/�̎��̃X�R�A
								  SCORE_DIF_PRO_ANSER,		//-*�̎��̃X�R�A
								  SCORE_SUM_DIF_PRO_ANSER,	//+-*�̎��̃X�R�A
								  SCORE_SUM_DIF_DEA_ANSER,	//+-/�̎��̃X�R�A
								  SCORE_ALL_ANSER };		//+-*/�̎��̃X�R�A
//�{�[�i�X�e�[�u��
vector<int> Score::LevBonus = { LEVEL_BONUS_EASY,			//�ȒP�̂Ƃ��̃{�[�i�X
								LEVEL_BONUS_NORMAL,			//���ʂ̂Ƃ��̃{�[�i�X
								LEVEL_BONUS_HARD };			//����̂Ƃ��̃{�[�i�X

//�R���X�g���N�^
Score::Score(){}

//�f�X�g���N�^
Score::~Score(){}

//�X�R�A�擾
int Score::GetScore()
{
	return score;
}

//�X�R�A���Z
void Score::AddScore(int mode, int lev, int time)
{

	//���Z������X�R�A�ʂ̐ݒ�
	int value = ScoreTable.at(mode);	//�Q�[�����[�h���̃X�R�A���擾

	const int time_excellent = 5;		//�G�N�Z�����g�̕]����̎���(5�b�ȓ�)
	const int time_great = 15;			//�O���[�g�̕]����̎���(15�b�ȓ�)

	if (time <= time_excellent)	//�G�N�Z�����g�̕]������Z�����
	{
		value *= TIME_BONUS_EXCELLENT;	//�G�N�Z�����g�̃{�[�i�X�������Čv�Z
	}
	else if (time <= time_great)//�O���[�g�̕]������Z�����
	{
		value *= TIME_BONUS_GREAT;		//�O���[�g�̃{�[�i�X�������Čv�Z
	}

	value *= LevBonus.at(lev);	//���x�����̃{�[�i�X����Z

	score += value;	//�X�R�A���Z

}

//�X�R�A�`��
void Score::Draw()
{
	DrawFormatStringToHandle(SCORE_DRAW_X, SCORE_DRAW_Y, COLOR_BLACK, Font::GetNowHandle(), "%d", score);
}

//���Z�b�g
void Score::Reset()
{
	score = 0;
}
