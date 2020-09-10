//Data.cpp
//�f�[�^���Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� ##################
#include "Data.hpp"

//################# �N���X��` ###################

int Data::ElementCnt = 0;	//�v�f��
//�e�L�X�g�e�[�u��
vector<string> Data::TxtTable = { TXT_MD_SUM,			//�����Z���[�h�̃e�L�X�g
								  TXT_MD_DIF,			//�����Z���[�h�̃e�L�X�g
								  TXT_MD_PRO,			//�|���Z���[�h�̃e�L�X�g
								  TXT_MD_DEA,			//����Z���[�h�̃e�L�X�g
								  TXT_MD_SUM_DIF,		//�����Z�ƈ����Z���[�h�̃e�L�X�g
								  TXT_MD_PRO_DEA,		//�|���Z�Ɗ���Z���[�h�̃e�L�X�g
								  TXT_MD_SUM_PRO,		//+*���[�h�̃e�L�X�g
								  TXT_MD_SUM_DEA,		//+/���[�h�̃e�L�X�g
								  TXT_MD_DIF_PRO,		//-*���[�h�̃e�L�X�g
								  TXT_MD_SUM_DIF_PRO,	//+-*���[�h�̃e�L�X�g
								  TXT_MD_SUM_DIF_DEA,	//+-/���[�h�̃e�L�X�g
								  TXT_MD_ALL };			//all���[�h�̃e�L�X�g

//�R���X�g���N�^
Data::Data(DATEDATA date, int score)
{
	//�����o�[������
	this->date = date;	//�f�[�^
	Score = score;		//�X�R�A
	Element = ElementCnt++;	//�v�f�ԍ�
}

//�R���X�g���N�^
Data::Data(int score)
{
	//�����o�[������
	date = { 0 };			//�f�[�^
	GetDateTime(&date);		//�f�[�^�擾
	Score = score;			//�X�R�A
	Element = ElementCnt++;	//�v�f�ԍ�
}

//�f�X�g���N�^
Data::~Data() {}

//���t�f�[�^�ݒ�
void Data::SetDate(DATEDATA date)
{
	this->date = date;
}

//�X�R�A�ݒ�
void Data::SetScore(int score)
{
	Score = score;
}

//���t�f�[�^�擾
DATEDATA Data::GetDate()
{
	return date;
}

//�X�R�A�擾
int Data::GetScore()
{
	return Score;
}

//�X�R�A�`��
void Data::Draw(int mode)
{
	if (Element >= RANKING_DRAW_MAX)	//�`�悷��ő吔��葽�����
		return;	//�`�悹���I��

	int height = GetFontSizeToHandle(Font::GetNowHandle());	//�����擾

	string text_gamemode = TxtTable.at(mode);	//�Q�[�����[�h���̃e�L�X�g���擾

	DrawStringToHandle(DRAW_DATA_X, DRAW_DATA_Y, text_gamemode.c_str(), COLOR_WHITE, Font::GetNowHandle());		//�����L���O�^�C�g���`��

	DrawFormatStringToHandle(DRAW_DATA_X, DRAW_DATA_Y + (Element + 1) * height, COLOR_WHITE, Font::GetNowHandle(), DRAW_DATA_TEXT,
		Element + 1,//���ʂ�
		Score,		//�X�R�A
		date.Year,	//�N
		date.Mon,	//��
		date.Day);	//��

}

//�v�f�ԍ��ݒ�
void Data::SetElement(int element)
{
	Element = element;
}

//�v�f�ԍ��擾
int Data::GetElement()
{
	return Element;
}

//�J�E���g���N���A����
void Data::CntClear()
{
	ElementCnt = 0;
}
