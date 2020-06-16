//FONT.hpp
//�t�H���g�N���X

/*
�ǉ����@
�E�t�H���g�̃t�@�C�����ƁA�t�H���g�̖��O���}�N����`����
�E�}�N����`����Ă���t�H���g�̎�ނ𑝂₷
�EAdd�������g�p���āA�Q�[�����Ŏg�p����t�H���g�𑝂₷���Ƃ��ł���
*/

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ######################
#include "Global.hpp"
#include <string>
#include <vector>

//################ �}�N����` �t�@�C���p�X�Ɩ��O ###############
#define FONT_DIR			R"(.\MY_FONT)"				//�t�H���g�t�@�C���̏ꏊ

#define FONT_FILE_NAME		R"(\kokubanB.ttf)"			//�t�H���g�̖��O
//############### �}�N����` ##################

//*********** �t�H���g�� **************
#define FONT_NAME		"�����΂�"					//�t�H���g�̐�������

//*********** �t�H���g�T�C�Y **************
#define DEFAULT_FONTSIZE	128						//�f�t�H���g�̃t�H���g�T�C�Y
#define FONTSIZE_MINI		48						//�t�H���g�T�C�Y�i�~�j�j
#define FONTSIZE_DRAW_RANKING	54					//�����L���O�`��̎��̃t�H���g�T�C�Y

//************* �t�H���g�̑��� *****************
#define FONT_BOLD_DEFAULT	5		//�f�t�H���g�̃t�H���g�̑���

//################ �}�N����` �G���[���b�Z�[�W #################
#define FONT_ERROR_TITLE "FONT_ERROR"						//�G���[�^�C�g��
#define FONT_ERROR_MSG	"�t�H���g���ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//################ �񋓌^ #####################
enum LOAD_FONT_NAME
{
	FONT_NAME_KOKUBAN	//�����΂�t�H���g
};	//�ǂݍ��񂾃t�H���g�̎��

enum FONT_HANDLE_TYPE
{
	HANDLE_TYPE_KOKUBAN_NORMALSIZE		//�����΂�t�H���g�̃m�[�}���T�C�Y�̃n���h��
};

using std::vector;
using std::string;

//################ �N���X�̒�` ##################
class FONT {

private:
	static vector<string> FilePath;			//�p�X
	static vector<string> LoadFontName;		//�ǂݍ��񂾃t�H���g�̖��O

	int Handle;								//�t�H���g�n���h��
	bool IsCreate;							//�t�H���g�n���h�����쐬�ł�����

public:

	FONT(int, int, int, int);		//�R���X�g���N�^
	~FONT();						//�f�X�g���N�^

	static bool LoadFont(const char*, const char*, const char*);	//�t�H���g��ǂݍ���
	static bool ReleaseFont();										//�ǂݍ��񂾃t�H���g���J��

	int GetHandle();		//�t�H���g�n���h���擾
	bool GetIsCreate();		//�t�H���g�n���h�����쐬�ł������擾

};
