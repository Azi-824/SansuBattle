//ScoreAdd.hpp
//�����Z�̃X�R�A���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ####################
#include "ScoreBase.hpp"

//################### �}�N����` #####################

//################### �N���X��` #####################
class ScoreAdd :public ScoreBase	//ScoreBase�N���X���p��
{
public:

	ScoreAdd();			//�R���X�g���N�^
	~ScoreAdd();		//�f�X�g���N�^

	virtual void CalcScore(int) override;		//�X�R�A�v�Z����

};