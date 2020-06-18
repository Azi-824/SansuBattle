//ScoreBase.cpp
//�X�R�A�֌W�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "ScoreBase.hpp"

//################# �N���X��` ##################

//�C���X�^���X����
int ScoreBase::Score = 0;	//�X�R�A

//�R���X�g���N�^
ScoreBase::ScoreBase()
{

}

//�f�X�g���N�^
ScoreBase::~ScoreBase()
{

}

//���݂̃X�R�A�\��
void ScoreBase::DrawNowScore()
{
	int Strlen = strlen(std::to_string(Score).c_str());						//������̒������擾
	int Width = GetDrawStringWidthToHandle(std::to_string(Score).c_str(), Strlen, NowFontHandle);	//�����擾

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), GAME_TOP, COLOR_WHITE, NowFontHandle, "%d", Score);		//�X�R�A�\��
}

//�X�R�A���Z�b�g
void ScoreBase::ResetScore()
{
	Score = 0;	//�X�R�A���Z�b�g
}

//�X�R�A�擾
int ScoreBase::GetScore()
{
	return Score;
}