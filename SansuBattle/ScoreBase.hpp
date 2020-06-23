//ScoreBase.hpp
//�X�R�A�֌W�̊�ɂȂ�N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"
#include <string>

//################### �}�N����` ########################
#define TIME_BONUS_EXCELLENT	2		//�񓚎��Ԃ��G�N�Z�����g�̎��̃{�[�i�X�{��
#define TIME_BONUS_GREAT		1.5		//�񓚎��Ԃ��O���[�g�̎��̃{�[�i�X�{��

//################### �N���X��` ########################
class ScoreBase
{
protected:

	int Score;			//���_

public:

	ScoreBase();							//�R���X�g���N�^
	~ScoreBase();							//�f�X�g���N�^

	virtual void CalcScore(int) = 0;		//�X�R�A�v�Z����
	void DrawNowScore();					//���݂̃X�R�A�\��
	void ResetScore();						//�X�R�A���Z�b�g

	int GetScore();							//�X�R�A�擾

};
