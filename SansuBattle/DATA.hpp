//Data.hpp
//�f�[�^���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"

//################### �}�N����` #####################
#define RANKING_DRAW_Y	10	//�����L���O�`��Y�ʒu

//#define RANK_INDEX_TEXT	"�����L���O"	//�\��e�L�X�g

//�e�L�X�g�֌W
#define TXT_MD_SUM			"��������"						//�����Z���[�h�̃e�L�X�g
#define TXT_MD_DIF			"�Ђ�����"						//�����Z���[�h�̃e�L�X�g
#define TXT_MD_PRO			"��������"						//�|���Z���[�h�̃e�L�X�g
#define TXT_MD_DEA			"��肴��"						//����Z���[�h�̃e�L�X�g
#define TXT_MD_SUM_DIF		"��������A�Ђ�����"			//�����Z�ƈ����Z���[�h�̃e�L�X�g
#define TXT_MD_PRO_DEA		"��������A��肴��"			//�|���Z�Ɗ���Z���[�h�̃e�L�X�g
#define TXT_MD_SUM_PRO		"��������A��������"			//+*���[�h�̃e�L�X�g
#define TXT_MD_SUM_DEA		"��������A��肴��"			//+/���[�h�̃e�L�X�g
#define TXT_MD_DIF_PRO		"�Ђ�����A��������"			//-*���[�h�̃e�L�X�g
#define TXT_MD_SUM_DIF_PRO	"��������A�Ђ�����A��������"	//+-*���[�h�̃e�L�X�g
#define TXT_MD_SUM_DIF_DEA	"��������A�Ђ�����A��肴��"	//+-/���[�h�̃e�L�X�g
#define TXT_MD_ALL			"�܂Ƃ�"						//all���[�h�̃e�L�X�g

#define DRAW_DATA_TEXT	"%2d:%dpt(%d/%d/%d)"				//�����L���O�`��̃e�L�X�g
#define DRAW_DATA_X		20	//�����L���O�`��J�nX�ʒu
#define DRAW_DATA_Y		20	//�����L���O�`��J�nY�ʒu

#define RANKING_DRAW_MAX 10	//�`�悷��f�[�^�̍ő吔

using std::string;

//################### �N���X��` #####################
class Data
{

private:

	int Score;		//�X�R�A
	int Element;	//�v�f�ԍ�
	static int ElementCnt;	//�v�f��
	static vector<string> TxtTable;	//�e�L�X�g�e�[�u��

	DATEDATA date;	//���t�f�[�^


public:

	Data(DATEDATA,int);	//�R���X�g���N�^
	Data(int);			//�R���X�g���N�^
	~Data();			//�f�X�g���N�^

	void SetDate(DATEDATA);	//���t�f�[�^�ݒ�
	void SetScore(int);		//�X�R�A�ݒ�

	DATEDATA GetDate();	//���t�f�[�^�擾
	int GetScore();		//�X�R�A�擾

	void Draw(int);			//�X�R�A�`��
	void SetElement(int);	//�v�f�ԍ��ݒ�
	int GetElement();		//�v�f�ԍ��擾
	static void CntClear();	//�J�E���g���N���A����

};
