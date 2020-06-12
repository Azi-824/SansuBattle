//MUSIC.cpp
//���y�p�N���X

//################### �w�b�_�t�@�C���ǂݍ��� ####################
#include "MUSIC.hpp"

//################## �N���X��` ###########################

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
//���@���Fint�F���f�ނ̎�ސ�
MUSIC::MUSIC(const char *dir, const char *name)
{
	//�����o�ϐ���������
	this->FilePath = "";	//�p�X
	this->FileName = "";	//���O

	this->IsLoad = false;	//�ǂݍ��߂����H

	//����ǂݍ���
	std::string LoadfilePath;	//���̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	this->Handle.push_back(LoadSoundMem(LoadfilePath.c_str()));	//���̓ǂݍ���

	if (this->Handle.back() == -1)	//�����ǂݍ��߂Ȃ������Ƃ�
	{
		std::string ErroeMsg(MUSIC_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');					//���s
		ErroeMsg += LoadfilePath;				//���̃p�X

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(MUSIC_ERROR_TITLE),
			MB_OK);

		return;
	}

	this->FilePath = LoadfilePath;		//���̃p�X��ݒ�
	this->FileName = name;				//���̖��O��ݒ�

	this->PlayType = DX_PLAYTYPE_BACK;	//�ŏ��͍Đ����@���o�b�N�O���E���h�Đ��ɂ���

	this->IsLoad = true;				//�ǂݍ��ݐ���

	this->IsPlayed.push_back(false);	//�Đ��ς݂ł͂Ȃ�

	return;

}

//�f�X�g���N�^
MUSIC::~MUSIC()
{

	//�͈̓x�[�X�� for ���[�v
	//vector�Ȃǂ̃R���e�i�N���X�Ŏg�p�ł���
	//auto�F�^���_�F�R���p�C���������l���琄�_���Č^�����߂Ă����
	for (int handle : this->Handle)
	{
		DeleteMusicMem(handle);		//���̃n���h���̍폜
	}

	//vector�̃�����������s��
	std::vector<int> v;			//���vector���쐬����
	this->Handle.swap(v);		//��ƒ��g�����ւ���

	//vector�̃�����������s��
	std::vector<bool> v2;		//���vector���쐬����
	this->IsPlayed.swap(v2);	//��ƒ��g�����ւ���

	return;
}

//�ǂݍ��߂����ǂ������擾
bool MUSIC::GetIsLoad()
{
	return this->IsLoad;
}

//�����Đ�����Ă��邩�擾
//�߂�l�F�Đ����Ftrue�@�Đ�������Ȃ��Ffalse
bool MUSIC::GetIsPlay(int kind)
{
	return CheckSoundMem(this->Handle[kind]);
}

//���y������ޓ����Ă��邩�擾
int MUSIC::GetSize()
{
	return Handle.size();
}

//�Đ����@��ύX����
void MUSIC::ChengePlayType(int type)
{
	this->PlayType = type;	
	return;
}

//���ʂ�ύX����
//�����Fint�F����(0�`100%�Ŏw��)
//�����Fint�F���ʂ�ς��������̎��
void MUSIC::ChengeVolume(double volume,int kind)
{
	ChangeVolumeSoundMem(VOLUME_MAX * (volume / 100), this->Handle[kind]);
	return;
}

//�����Đ�����
void MUSIC::Play(int kind,bool check)
{
	if (check)	//�v���C�����m�F����ꍇ
	{
		if (!this->GetIsPlay(kind))		//�v���C������Ȃ����
		{
			PlaySoundMem(this->Handle[kind], this->PlayType);	//���̍Đ�
		}
	}
	else		//�m�F���Ȃ��ꍇ
	{
		PlaySoundMem(this->Handle[kind], this->PlayType);	//���̍Đ�
	}

	return;
}

//�����Đ�����(1�񂾂�)
void MUSIC::PlayOne(int kind, bool check)
{
	if (!this->IsPlayed[kind])		//�Đ��ς݂���Ȃ����
	{
		if (check)	//�v���C�����m�F����ꍇ
		{
			if (!this->GetIsPlay(kind))		//�v���C������Ȃ����
			{
				PlaySoundMem(this->Handle[kind], this->PlayType);	//���̍Đ�

				this->IsPlayed[kind] = true;		//�Đ��ς�

			}

		}
		else		//�m�F���Ȃ��ꍇ
		{
			PlaySoundMem(this->Handle[kind], this->PlayType);	//���̍Đ�

			this->IsPlayed[kind] = true;		//�Đ��ς�
		}
	}
}

//�Đ��ς݂��ǂ��������Z�b�g����(�w�肳�ꂽ���̂���)
void MUSIC::PlayReset(int kind)
{
	this->IsPlayed[kind] = false;	//�Đ��ς݂���Ȃ�
	return;
}

//�Đ��ς݂��ǂ��������Z�b�g����(�S��)
void MUSIC::PlayReset()
{
	for (int i = 0; i < this->Handle.size(); ++i)
	{
		this->IsPlayed[i] = false;	//�Đ��ς݂���Ȃ�
	}
	return;
}

//�����~�߂�i���ׂāj
void MUSIC::Stop(void)
{
	for (int i = 0; i < this->Handle.size(); ++i)
	{
		StopSoundMem(this->Handle[i]);		//�����~�߂�
	}
	return;
}

//�����~�߂�i�w�肳�ꂽ���̂����j
void MUSIC::Stop(int kind)
{
	StopSoundMem(this->Handle[kind]);
	return;
}

//����ǉ�����
bool MUSIC::Add(const char *dir, const char *name)
{

	//����ǂݍ���
	std::string LoadfilePath;	//���̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	this->Handle.push_back(LoadSoundMem(LoadfilePath.c_str()));	//���̓ǂݍ���

	if (this->Handle.back() == -1)	//�����ǂݍ��߂Ȃ������Ƃ�
	{
		std::string ErroeMsg(MUSIC_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');					//���s
		ErroeMsg += LoadfilePath;				//���̃p�X

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(MUSIC_ERROR_TITLE),
			MB_OK);

		return false;	//�ǂݍ��ݎ��s
	}

	this->IsPlayed.push_back(false);	//�Đ��ς݂ł͂Ȃ�

	return true;		//�ǂݍ��ݐ���

}