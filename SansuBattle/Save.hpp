//Save.hpp
//�Z�[�u�֌W�̃N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Global.hpp"
#include "Data.hpp"
#include <fstream>
#include <sys/stat.h>
#include <direct.h>

//################## �}�N����` #######################
#define SAVEDATA_DIR	R"(C:\SansuBattle)"		//�Z�[�u�f�[�^�̕ۑ��f�B���N�g����

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

#define SAVE_MAX		15	//�ۑ�����f�[�^�̍ő吔

//############## �}�N����`�F�G���[���b�Z�[�W ###################
#define DATA_ERROR_TTILE	"DATA_ERROR"						//�G���[�^�C�g��
#define DATA_ERROR_MSG		"�f�[�^���ǂݍ��߂܂���ł���"		//�G���[���b�Z�[�W

using std::string;
using std::vector;

//########### �N���X��` #############
class Save
{

private:

	static vector<string> NameTable;	//�t�@�C�����̃e�[�u��

	static bool CheckCreateFile(string);//�w�肳�ꂽ�t�@�C���������݂��邩�擾
	static void CreateTable();			//�e�[�u���̍쐬

public:

	Save();		//�R���X�g���N�^
	~Save();	//�f�X�g���N�^

	static bool Load(vector<Data*>*,int);		//�ǂݍ���
	static bool DataSave(vector<Data*>,int);	//�Z�[�u
	static void Sort(vector<Data*>*);			//�\�[�g����


};
