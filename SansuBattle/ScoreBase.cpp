//ScoreBase.cpp
//�X�R�A�֌W�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "ScoreBase.hpp"

//################# �N���X��` ##################

//�R���X�g���N�^
ScoreBase::ScoreBase()
{
	//�����o�[�ϐ�������
	Score = 0;	//�X�R�A������
}

//�f�X�g���N�^
ScoreBase::~ScoreBase()
{

}

//���݂̃X�R�A�\��
void ScoreBase::DrawNowScore()
{
	DrawFormatString(300, 0, COLOR_WHITE, "%d", Score);		//�X�R�A�\��
}

//�X�R�A�擾
int ScoreBase::GetScore()
{
	return Score;
}