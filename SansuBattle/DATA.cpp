//DATA.cpp
//�f�[�^���Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� ##################
#include "DATA.hpp"

//################# �N���X��` ###################

//�R���X�g���N�^
DATA::DATA(int year,int month,int day,int score)
{

	Year = year;		//�N
	Month = month;		//��
	Day = day;			//��
	Score = score;		//�X�R�A

	return;
}

//�f�X�g���N�^
DATA::~DATA()
{
	return;
}

//�N�擾
int DATA::GetYear()
{
	return Year;
}

//���擾
int DATA::GetMonth()
{
	return Month;
}

//���擾
int DATA::GetDay()
{
	return Day;
}

//�X�R�A�擾
int DATA::GetScore()
{
	return Score;
}
