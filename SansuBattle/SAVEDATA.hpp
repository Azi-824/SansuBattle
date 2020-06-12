//SAVEDATA.hpp
//�Z�[�u�f�[�^���Ǘ�����N���X

#pragma once

//################## �w�b�_�t�@�C���ǂݍ��� ####################
#include "DATA.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <direct.h>

//################## �}�N����` #######################
#define SAVEDATA_DIR	R"(C:\SansuBattle)"		//�Z�[�u�f�[�^�̕ۑ��f�B���N�g����

#define SAVEDATA_NAME		R"(\Savedata.csv)"		//�Z�[�u�f�[�^�̖��O
#define SAVE_NAME_ADD		R"(\Save_Add.csv)"		//�Z�[�u�f�[�^�̖��O(�����Z)
#define SAVE_NAME_DIF		R"(\Save_Dif.csv)"		//�Z�[�u�f�[�^�̖��O(�����Z)
#define SAVE_NAME_PRO		R"(\Save_Pro.csv)"		//�Z�[�u�f�[�^�̖��O(�|���Z)
#define SAVE_NAME_DEA		R"(\Save_Dea.csv)"		//�Z�[�u�f�[�^�̖��O(����Z)
#define SAVE_NAME_SUM_DIF	R"(\Save_SumDif.csv)"	//�Z�[�u�f�[�^�̖��O(�����Z�A�����Z)
#define SAVE_NAME_PRO_DEA	R"(\Save_ProDea.csv)"	//�Z�[�u�f�[�^�̖��O(�|���Z�A����Z)


//�e�L�X�g�֌W
#define TEXT_GAMEMODE			"�Q�[�����[�h:"					//�Q�[�����[�h�̃e�L�X�g
#define TEXT_GAMEMODE_ADD		"��������"						//�����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_DIF		"�Ђ�����"						//�����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_PRO		"��������"						//�|���Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_DEA		"��肴��"						//����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_SUM_DIF	"��������A�Ђ�����"			//�����Z�ƈ����Z���[�h�̃e�L�X�g
#define TEXT_GAMEMODE_PRO_DEA	"��������A��肴��"			//�|���Z�Ɗ���Z���[�h�̃e�L�X�g

#define DRAW_DATA_TEXT			"%2d��:%d�l����(%d/%d/%d)"		//�����L���O�`��̃e�L�X�g
#define DRAW_DATA_X		0	//�����L���O�`��J�nX�ʒu
#define DRAW_DATA_Y		0	//�����L���O�`��J�nY�ʒu
#define DRAW_DATA_MAX	10	//�`�悷��f�[�^�̐�

//############## �}�N����`�F�G���[���b�Z�[�W ###################
#define DATA_ERROR_TTILE	"DATA_ERROR"						//�G���[�^�C�g��
#define DATA_ERROR_MSG		"�f�[�^���ǂݍ��߂܂���ł���"		//�G���[���b�Z�[�W

using std::string;

//################## �N���X��` #######################
class SAVEDATA
{

private:

	std::vector<DATA*> DataCode;			//�Z�[�u�f�[�^

	const char* GetFileName(int);			//�ǂ̃t�@�C�����g�p���邩�擾
	const char* GetTextGameMode(int);		//�Q�[�����[�h���̃e�L�X�g���擾
	bool CheckCreateFile(string);			//�w�肳�ꂽ�t�@�C�������݂��邩�擾

public:

	SAVEDATA();		//�R���X�g���N�^
	~SAVEDATA();	//�f�X�g���N�^

	void Add(int);	//�f�[�^�ǉ�

	bool Save(int);	//�Z�[�u
	bool Load(int);	//�ǂݍ���

	void Sort();	//�Z�[�u�f�[�^���~���ɕ��בւ���

	void Draw(int);	//�f�[�^�`��


};
