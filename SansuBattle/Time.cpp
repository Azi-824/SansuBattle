//Time.cpp
//���Ԃ��Ǘ�����N���X

//################## �w�b�_�t�@�C���ǂݍ��� ################
#include "Time.hpp"

//################## �N���X��` ##################

//�R���X�g���N�^
Time::Time()
{
	//�����o�[�ϐ�������
	StartTime = 0;		//�v���J�n���ԏ�����
	ElapsedTime = 0;	//�o�ߎ��ԏ�����
	LimitTime = 0;		//�������ԏ�����
	LimitInit = 0;		//�������ԏ����l
	NowLimitTime = 0;	//�c��̐������ԏ�����
}

//�R���X�g���N�^�i�������Ԃ̐ݒ�t���j
//�����Fint�F��������
Time::Time(int limit)
{
	//�����o�[�ϐ�������
	StartTime = 0;		//�v���J�n���ԏ�����
	ElapsedTime = 0;	//�o�ߎ��ԏ�����
	NowLimitTime = 0;	//�c��̐������ԏ�����
	LimitTime = limit;	//�������Ԃ�ݒ�
	LimitInit = LimitTime;	//�������Ԃ̏����l��ݒ�
}

//�f�X�g���N�^
Time::~Time() {}

//�v���J�n
void Time::SetTime()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	StartTime = GetNowCount() / 1000;	//�v���J�n���Ԑݒ�
	LimitTime = LimitInit;				//�������Ԃ������l�ɂ���
}

//�o�ߎ��ԍX�V
void Time::UpdateElpasedTime()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	ElapsedTime = (GetNowCount() / 1000) - StartTime;	//�o�ߎ��Ԃ��X�V
}

//�������ԍX�V
void Time::UpdateLimitTime()
{
	UpdateElpasedTime();	//�o�ߎ��Ԃ��X�V
	NowLimitTime = LimitTime - ElapsedTime;	//�c��̐������Ԃ��X�V
}

//�o�ߎ��ԕ`��
//�����Fint�F�`��X�ʒu
//�����Fint�F�`��Y�ʒu
void Time::DrawElapsedTime(int x, int y)
{
	UpdateElpasedTime();	//�o�ߎ��Ԃ��X�V
	DrawFormatStringToHandle(x, y, COLOR_WHITE, Font::GetNowHandle(), "%d", ElapsedTime);	//�o�ߎ��Ԃ�`��
}

//�������ԕ`��
//�����Fint�F�`��X�ʒu
//�����Fint�F�`��Y�ʒu
void Time::DrawLimitTime(int x, int y)
{
	UpdateLimitTime();	//�c��̐������ԍX�V
	if (NowLimitTime <= CHENGE_TIME)	//����Ԃ�菭�Ȃ��Ȃ�����
	{
		//�`��F��
		DrawFormatStringToHandle(x, y, COLOR_RED, Font::GetNowHandle(), "%2d", NowLimitTime);	//�������Ԃ�`��
	}
	else
	{
		DrawFormatStringToHandle(x, y, COLOR_GREEN, Font::GetNowHandle(), "%2d", NowLimitTime);	//�������Ԃ�`��
	}
}

//�o�ߎ��Ԏ擾
int Time::GetElapsedTime()
{
	return ElapsedTime;
}

//�������Ԃ��߂������擾
//�߂�l:true �������Ԃ��߂��Ă��� :false �������Ԃ��߂��Ă��Ȃ�
bool Time::GetIsLimit()
{
	UpdateLimitTime();	//�������ԍX�V
	return NowLimitTime <= 0 ? true : false;
}

//�c��̐������Ԃ��}�C�i�X����
//�����Fint�F���炷���ԁi�b�j
void Time::MinusLimitTime(int value)
{
	LimitTime -= value;	//�������Ԃ����炷
}
