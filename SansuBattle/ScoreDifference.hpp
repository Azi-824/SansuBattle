//ScoreDifference.hpp
//�����Z�̃X�R�A���Ǘ�����I�u�W�F�N�g

#pragma once

//############## �w�b�_�t�@�C���ǂݍ��� ################
#include "Score.hpp"

//################### �}�N����` #####################
#define SCORE_DIFFERENCE_ANSER	100		//�����Z�̉񓚂��������̃X�R�A

//############# �N���X��` ################
class ScoreDifference : public Score	//Score���p��
{
public:

	ScoreDifference();			//�R���X�g���N�^
	~ScoreDifference();			//�f�X�g���N�^

	void CalcScore(int, int) override;		//�X�R�A�v�Z����

};