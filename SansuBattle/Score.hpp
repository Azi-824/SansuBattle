//Score.hpp
//�X�R�A�֌W�̊�ɂȂ�N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"
#include <string>

//################### �}�N����` ########################
#define TIME_BONUS_EXCELLENT	2		//�񓚎��Ԃ��G�N�Z�����g�̎��̃{�[�i�X�{��
#define TIME_BONUS_GREAT		1.5		//�񓚎��Ԃ��O���[�g�̎��̃{�[�i�X�{��
#define LEVEL_BONUS_EASY		1		//�ȒP���x���̃{�[�i�X�{��
#define LEVEL_BONUS_NORMAL		2		//���ʃ��x���̃{�[�i�X�{��
#define LEVEL_BONUS_HARD		3		//������x���̃{�[�i�X�{��

#define SCORE_ADD_ANSER	100				//�����Z�̉񓚂��������̃X�R�A
#define SCORE_DIFFERENCE_ANSER	150		//�����Z�̉񓚂��������̃X�R�A
#define SCORE_PRODUCT_ANSER	200			//�|���Z�̉񓚂��������̃X�R�A


//################### �N���X��` ########################
class Score
{
protected:

	int score;			//���_

public:

	Score();							//�R���X�g���N�^
	~Score();							//�f�X�g���N�^

	void CalcScore(int,int,int);		//�X�R�A�v�Z����
	void DrawNowScore();				//���݂̃X�R�A�\��
	void ResetScore();					//�X�R�A���Z�b�g

	int GetScore();						//�X�R�A�擾

};
