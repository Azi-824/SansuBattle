//Score.cpp
//�X�R�A�֌W�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Score.hpp"

//################# �N���X��` ##################

//�R���X�g���N�^
Score::Score()
{

}

//�f�X�g���N�^
Score::~Score()
{

}

//���݂̃X�R�A�\��
void Score::DrawNowScore()
{
	int Strlen = strlen(std::to_string(score).c_str());						//������̒������擾
	int Width = GetDrawStringWidthToHandle(std::to_string(score).c_str(), Strlen, NowFontHandle);	//�����擾

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), GAME_TOP, COLOR_WHITE, NowFontHandle, "%d", score);		//�X�R�A�\��
}

//�X�R�A���Z�b�g
void Score::ResetScore()
{
	score = 0;	//�X�R�A���Z�b�g
}

//�X�R�A�擾
int Score::GetScore()
{
	return score;
}