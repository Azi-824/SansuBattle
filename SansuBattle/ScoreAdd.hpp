//ScoreAdd.hpp
//�����Z�̃X�R�A���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ####################
#include "Score.hpp"

//################### �}�N����` #####################
#define SCOREADD_SCORE_ANSER	100		//�����Z�̉񓚂��������̃X�R�A

//################### �N���X��` #####################
class ScoreAdd :public Score	//ScoreBase�N���X���p��
{
public:

	ScoreAdd();			//�R���X�g���N�^
	~ScoreAdd();		//�f�X�g���N�^

	virtual void CalcScore(int,int) override;		//�X�R�A�v�Z����

};
