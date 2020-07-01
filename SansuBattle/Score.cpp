//Score.cpp
//�X�R�A�֌W�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Score.hpp"

//################# �N���X��` ##################

//�R���X�g���N�^
Score::Score()
{
	score = 0;	//score������
	//�Q�[�����[�h���̃X�R�A��ݒ�
	mode_score.push_back(SCORE_SUM_ANSER);			//�����Z�̎��̃X�R�A
	mode_score.push_back(SCORE_DIFFERENCE_ANSER);	//�����Z�̎��̃X�R�A
	mode_score.push_back(SCORE_PRODUCT_ANSER);		//�|���Z�̎��̃X�R�A
	mode_score.push_back(SCORE_DEALER_ANSER);		//����Z�̎��̃X�R�A
	mode_score.push_back(SCORE_SUM_DIF_ANSER);		//�����Z�A�����Z�̎��̃X�R�A
	mode_score.push_back(SCORE_PRO_DEA_ANSER);		//�|���Z�A����Z�̎��̃X�R�A
	//�Q�[�����x�����̃{�[�i�X��ݒ�
	level_bonus.push_back(LEVEL_BONUS_EASY);		//�ȒP�̂Ƃ��̃{�[�i�X
	level_bonus.push_back(LEVEL_BONUS_NORMAL);		//���ʂ̂Ƃ��̃{�[�i�X
	level_bonus.push_back(LEVEL_BONUS_HARD);		//����̂Ƃ��̃{�[�i�X
}

//�f�X�g���N�^
Score::~Score()
{
	//vector�̉��
	vector<int> v;
	mode_score.swap(v);

	//vector�̉��
	vector<int> v2;
	level_bonus.swap(v2);

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
	//���Z������X�R�A�ʂ̐ݒ�
	int add_value = mode_score.at(gamemode);	//�Q�[�����[�h���̃X�R�A���擾

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

	add_value *= level_bonus.at(gamelevel);	//���x�����̃{�[�i�X����Z

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