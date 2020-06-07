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
	this->NowLimitTime = 0;		//�c��̐������ԏ�����

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

//�������ԍX�V
//�����Fint�F��������
void Time::UpdateLimitTime(int limit_time)
{
	this->UpdateElpasedTime();	//�o�ߎ��Ԃ��X�V
	this->NowLimitTime = limit_time - this->ElapsedTime;	//�c��̐������Ԃ��X�V
	return;
}

//�o�ߎ��ԕ`��
//�����Fint�F�`��X�ʒu
//�����Fint�F�`��Y�ʒu
void Time::DrawElapsedTime(int x, int y)
{
	this->UpdateElpasedTime();	//�o�ߎ��Ԃ��X�V
	DrawFormatString(x, y, COLOR_WHITE, "%d", this->ElapsedTime);	//�o�ߎ��Ԃ�`��
	return;
}

//�������ԕ`��
//�����Fint�F�`��X�ʒu
//�����Fint�F�`��Y�ʒu
//�����Fint�F��������
void Time::DrawLimitTime(int x, int y,int limit_time)
{
	this->UpdateLimitTime(limit_time);	//�c��̐������ԍX�V
	DrawFormatString(x, y, COLOR_WHITE, "%d", this->NowLimitTime);	//�������Ԃ�`��
	return;
}
