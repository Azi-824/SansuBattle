//ScoreProduct.hpp
//�|���Z�̃X�R�A���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###############
#include "Score.hpp"

//################### �}�N����` #####################
#define SCORE_PRODUCT_ANSER	150		//�|���Z�̉񓚂��������̃X�R�A

//############# �N���X��` ################
class ScoreProduct : public Score	//Score���p��
{
public:

	ScoreProduct();			//�R���X�g���N�^
	~ScoreProduct();		//�f�X�g���N�^

	void CalcScore(int, int) override;		//�X�R�A�v�Z����

};
