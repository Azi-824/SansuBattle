//ScoreBase.hpp
//�X�R�A�֌W�̊�ɂȂ�N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"

//################### �}�N����` ########################

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

	int GetScore();							//�X�R�A�擾

};
