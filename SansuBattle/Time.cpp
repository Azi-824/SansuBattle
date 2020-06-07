//Time.cpp
//���Ԃ��Ǘ�����N���X

//################## �w�b�_�t�@�C���ǂݍ��� ################
#include "Time.hpp"

//################## �N���X��` ##################

//�R���X�g���N�^
Time::Time()
{
	//�����o�[�ϐ�������
	this->StartTime = 0;		//�v���J�n���ԏ�����
	this->ElapsedTime = 0;		//�o�ߎ��ԏ�����

	return;
}

//�f�X�g���N�^
Time::~Time()
{
	return;
}

//�v���J�n
void Time::SetTime()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	this->StartTime = GetNowCount() / 1000;	//�v���J�n���Ԑݒ�
	return;
}

//�o�ߎ��ԍX�V
void Time::UpdateElpasedTime()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	this->ElapsedTime = (GetNowCount() / 1000) - this->StartTime;	//�o�ߎ��Ԃ��X�V
	return;
}

//�o�ߎ��ԕ`��
void Time::DrawElapsedTime(int x, int y)
{
	this->UpdateElpasedTime();	//�o�ߎ��Ԃ��X�V
	DrawFormatString(x, y, COLOR_WHITE, "%d", this->ElapsedTime);	//�o�ߎ��Ԃ�`��
	return;
}
