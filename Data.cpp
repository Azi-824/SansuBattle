//Data.cpp
//�f�[�^���Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� ##################
#include "Data.hpp"

//################# �N���X��` ###################

//�R���X�g���N�^
Data::Data(int year,int month,int day,int score)
{

	Year = year;		//�N
	Month = month;		//��
	Day = day;			//��
	Score = score;		//�X�R�A

	return;
}

//�f�X�g���N�^
Data::~Data()
{
	return;
}

//�N�擾
int Data::GetYear()
{
	return Year;
}

//���擾
int Data::GetMonth()
{
	return Month;
}

//���擾
int Data::GetDay()
{
	return Day;
}

//�X�R�A�擾
int Data::GetScore()
{
	return Score;
}
