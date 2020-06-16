//FONT.cpp
//�t�H���g�N���X

//############### �w�b�_�t�@�C���ǂݍ��� ####################
#include "FONT.hpp"

//############### �N���X�̒�` #####################

//�C���X�^���X�w��
vector<string> FONT::LoadFontName;	//�ǂݍ��񂾃t�H���g�̖��O
vector<string> FONT::FilePath;		//�ǂݍ��񂾃t�H���g�̃p�X

//�R���X�g���N�^
//���@���Fint�F�ǂݍ��ރt�H���g�̖��O
//���@���Fint�F�t�H���g�̃T�C�Y
//���@���Fint�F�t�H���g�̑���
//���@���Fint�F�t�H���g�̃^�C�v
FONT::FONT(int fontname, int size, int bold, int fonttype)
{
								
	Handle = CreateFontToHandle(LoadFontName.at(fontname).c_str(), size, bold, fonttype);	//�t�H���g�n���h�����쐬
	//Handle = CreateFontToHandle(NULL,size, bold, fonttype);	//�t�H���g�n���h�����쐬

	if (Handle == -1)		//�n���h���쐬���s
		IsCreate = false;	//�쐬���s
	else					//�n���h���쐬����
		IsCreate = true;	//�쐬����

	return;

}

//�f�X�g���N�^	
FONT::~FONT()
{
	//vector�̃�����������s��
	std::vector<std::string> v;			//���vector���쐬����
	this->FilePath.swap(v);				//��ƒ��g�����ւ���

}

//�t�H���g��ǂݍ���
bool FONT::LoadFont(const char* dir, const char* name, const char* fontname)
{
	string LoadFilePath = dir;
	LoadFilePath += name;

	//�t�H���g�ǂݍ���
	if (AddFontResourceEx(LoadFilePath.c_str(), FR_PRIVATE, NULL) <= 0)		//�ǂݍ��ݎ��s
	{
		string ErroeMsg(FONT_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');				//���s
		ErroeMsg += LoadFilePath;			//�t�H���g�̃p�X

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(FONT_ERROR_TITLE),
			MB_OK);

		return false;	//�ǂݍ��ݎ��s

	}

	LoadFontName.push_back(fontname);	//�ǂݍ��񂾃t�H���g�̖��O��ǉ�
	FilePath.push_back(LoadFilePath);	//�ǂݍ��񂾃t�H���g�̃p�X��ǉ�

	return true;

}

//�ǂݍ��񂾃t�H���g���J��
bool FONT::ReleaseFont()
{
	for (int i = 0; i < LoadFontName.size(); ++i)
	{
		if (RemoveFontResourceEx(FilePath.at(i).c_str(), FR_PRIVATE, NULL) == 0)	//���s��
		{
			MessageBox(NULL, "remove failure", "", MB_OK);				//�G���[���b�Z�[�W
			return false;
		}

	}
	return true;
}

//�t�H���g�n���h���쐬
int FONT::GetHandle()
{
	return Handle;
}

//�t�H���g�n���h�����쐬�ł������擾
bool FONT::GetIsCreate()
{
	return IsCreate;
}