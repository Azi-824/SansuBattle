//SaveData.hpp
//�Z�[�u�f�[�^���Ǘ�����N���X

#pragma once

//################## �w�b�_�t�@�C���ǂݍ��� ####################
#include "Data.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <direct.h>

//################## �}�N����` #######################
#define SAVEDATA_DIR	R"(C:\SansuBattle)"		//�Z�[�u�f�[�^�̕ۑ��f�B���N�g����

#define SAVEDATA_NAME			R"(\Savedata.csv)"			//�Z�[�u�f�[�^�̖��O
#define SAVE_NAME_SUM			R"(\Save_Add.csv)"			//�Z�[�u�f�[�^�̖��O(�����Z)
#define SAVE_NAME_DIF			R"(\Save_Dif.csv)"			//�Z�[�u�f�[�^�̖��O(�����Z)
#define SAVE_NAME_PRO			R"(\Save_Pro.csv)"			//�Z�[�u�f�[�^�̖��O(�|���Z)
#define SAVE_NAME_DEA			R"(\Save_Dea.csv)"			//�Z�[�u�f�[�^�̖��O(����Z)
#define SAVE_NAME_SUM_DIF		R"(\Save_SumDif.csv)"		//�Z�[�u�f�[�^�̖��O(�����Z�A�����Z)
#define SAVE_NAME_PRO_DEA		R"(\Save_ProDea.csv)"		//�Z�[�u�f�[�^�̖��O(�|���Z�A����Z)
#define SAVE_NAME_SUM_PRO		R"(\Save_SumPro.csv)"		//�Z�[�u�f�[�^�̖��O(+*)
#define SAVE_NAME_SUM_DEA		R"(\Save_SumDea.csv)"		//�Z�[�u�f�[�^�̖��O(+/)
#define SAVE_NAME_DIF_PRO		R"(\Save_DifPro.csv)"		//�Z�[�u�f�[�^�̖��O(-*)
#define SAVE_NAME_SUM_DIF_PRO	R"(\Save_SumDifPro.csv)"	//�Z�[�u�f�[�^�̖��O(+-*)
#define SAVE_NAME_SUM_DIF_DEA	R"(\Save_SumDifDea.csv)"	//�Z�[�u�f�[�^�̖��O(+-/)
#define SAVE_NAME_ALL			R"(\Save_All.csv)"			//�Z�[�u�f�[�^�̖��O(+-*/)


//�e�L�X�g�֌W
#define TEXT_GAMEMODE				"�Q�[�����[�h:"					//�Q�[�����[�h�̃e�L�X�g
#define TEXT_GAMEMODE_SUM			"��������"						//�����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_DIF			"�Ђ�����"						//�����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_PRO			"��������"						//�|���Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_DEA			"��肴��"						//����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_SUM_DIF		"��������A�Ђ�����"			//�����Z�ƈ����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_PRO_DEA		"��������A��肴��"			//�|���Z�Ɗ���Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_SUM_PRO		"��������A��������"			//+*���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_SUM_DEA		"��������A��肴��"			//+/���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_DIF_PRO		"�Ђ�����A��������"			//-*���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_SUM_DIF_PRO	"��������A�Ђ�����A��������"	//+-*���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_SUM_DIF_DEA	"��������A�Ђ�����A��肴��"	//+-/���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_ALL			"�܂Ƃ�"						//all���[�h�̃e�L�X�g


#define DRAW_DATA_TEXT			"%2d:%dpoint(%d/%d/%d)"			//�����L���O�`��̃e�L�X�g
#define DRAW_DATA_X		20	//�����L���O�`��J�nX�ʒu
#define DRAW_DATA_Y		20	//�����L���O�`��J�nY�ʒu
#define DRAW_DATA_MAX	10	//�`�悷��f�[�^�̐�
#define SAVE_MAX		15	//�ۑ�����f�[�^�̍ő吔

//############## �}�N����`�F�G���[���b�Z�[�W ###################
#define DATA_ERROR_TTILE	"DATA_ERROR"						//�G���[�^�C�g��
#define DATA_ERROR_MSG		"�f�[�^���ǂݍ��߂܂���ł���"		//�G���[���b�Z�[�W

using std::string;
using std::vector;

//################## �N���X��` #######################
class SaveData
{

private:

	vector<Data*> DataCode;					//�Z�[�u�f�[�^
	static vector<string> FileNameTable;	//�t�@�C�����̃e�[�u��
	static vector<string> TextTable;		//�e�L�X�g�̃e�[�u��

	bool CheckCreateFile(string);			//�w�肳�ꂽ�t�@�C�������݂��邩�擾
	void CreateTable();						//�e�[�u���̍쐬

public:

	SaveData();		//�R���X�g���N�^
	~SaveData();	//�f�X�g���N�^

	void Add(int);	//�f�[�^�ǉ�

	bool Save(int);	//�Z�[�u
	bool Load(int);	//�ǂݍ���

	void Sort();	//�Z�[�u�f�[�^���~���ɕ��בւ���

	void Draw(int);	//�f�[�^�`��


};
