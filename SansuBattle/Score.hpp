//Score.hpp
//�X�R�A���Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� #############
#include "Global.hpp"

//############ �}�N����` #################
#define TIME_BONUS_EXCELLENT	2		//�񓚎��Ԃ��G�N�Z�����g�̎��̃{�[�i�X�{��
#define TIME_BONUS_GREAT		1.5		//�񓚎��Ԃ��O���[�g�̎��̃{�[�i�X�{��
#define LEVEL_BONUS_EASY		1		//�ȒP���x���̃{�[�i�X�{��
#define LEVEL_BONUS_NORMAL		2		//���ʃ��x���̃{�[�i�X�{��
#define LEVEL_BONUS_HARD		3		//������x���̃{�[�i�X�{��

#define SCORE_SUM_ANSER			100		//�����Z�̉񓚂��������̃X�R�A
#define SCORE_DIFFERENCE_ANSER	150		//�����Z�̉񓚂��������̃X�R�A
#define SCORE_PRODUCT_ANSER		200		//�|���Z�̉񓚂��������̃X�R�A
#define SCORE_DEALER_ANSER		250		//����Z�̉񓚂��������̃X�R�A
#define SCORE_SUM_DIF_ANSER		300		//�����Z�A�����Z�̉񓚂��������̃X�R�A
#define SCORE_PRO_DEA_ANSER		350		//�|���Z�A����Z�̉񓚂��������̃X�R�A
#define SCORE_SUM_PRO_ANSER		400		//+*�̉񓚂��������̃X�R�A
#define SCORE_SUM_DEA_ANSER		450		//+/�̉񓚂��������̃X�R�A
#define SCORE_DIF_PRO_ANSER		500		//-*�̉񓚂��������̃X�R�A
#define SCORE_SUM_DIF_PRO_ANSER	550		//+-*�̉񓚂��������̃X�R�A
#define SCORE_SUM_DIF_DEA_ANSER	600		//+-/�̉񓚂��������̃X�R�A
#define SCORE_ALL_ANSER			650		//+-*/�̉񓚂��������̃X�R�A

//############ �N���X��` #############
class Score
{
private:

	static int score;		//�X�R�A

	static vector<int> ScoreTable;	//�Q�[�����[�h���̃X�R�A
	static vector<int> LevBonus;	//�Q�[�����x�����̃{�[�i�X

public:

	Score();		//�R���X�g���N�^
	~Score();		//�f�X�g���N�^

	static int GetScore();				//�X�R�A�擾
	static void AddScore(int,int,int);	//�X�R�A���Z
	static void Draw();					//�X�R�A�`��
	static void DrawCenter(RECT);		//�w�肳�ꂽ�̈���̒����ɕ`��
	static void Reset();				//���Z�b�g

};
