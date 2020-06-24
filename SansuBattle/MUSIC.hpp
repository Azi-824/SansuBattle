//Music.hpp
//���y�p�N���X

/*
�ǉ����@
�E�t�H���_���A�t�@�C�������}�N����`����
�E�ǉ��������̎�ނ��ƂɁA�񋓌^�ɒǉ�����
�@��F�퓬�Ŏg�p����SE��ǉ������ꍇ
    �@BT_SE_TYPE�ɒǉ�����
�EAdd�������g�p���āASE��BGM��ǉ����邱�Ƃ��ł���
*/

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Global.hpp"
#include <string>
#include <vector>

//##################### �}�N����`�F�t�@�C���p�X�A���O ###################
#define MUSIC_DIR_SE			R"(.\MY_MUSIC\SE)"			//SE�̃t�@�C����
#define MUSIC_DIR_BGM			R"(.\MY_MUSIC\BGM)"			//BGM�̃t�@�C����
#define MUSIC_DIR_EFFECT		R"(.\MY_MUSIC\Effect)"		//�G�t�F�N�g�̃t�@�C����

#define SE_NAME_EFFECT_ATK		R"(\atack.mp3)"			//�U���G�t�F�N�g�̌��ʉ�

#define BGM_NAME_TITLE_BGM		R"(\title_bgm.mp3)"		//�^�C�g����BGM�̖��O
#define BGM_NAME_SELECT_BGM		R"(\select_bgm.mp3)"	//�I����ʂ�BGM�̖��O
#define BGM_NAME_PLAY_ADD_BGM	R"(\play_add_bgm.mp3)"	//�v���C��ʁi�����Z�j��BGM�̖��O
#define BGM_NAME_PLAY_DIFF_BGM	R"(\play_diff_bgm.mp3)"	//�v���C��ʁi�����Z�j��BGM�̖��O
#define BGM_NAME_END_BGM		R"(\end_bgm.mp3)"		//�G���h��ʂ�BGM�̖��O

//##################### �}�N����`�F�G���[���b�Z�[�W ######################
#define MUSIC_ERROR_TITLE "MUSIC_ERROR"					//�G���[�^�C�g��
#define MUSIC_ERROR_MSG	"�����ǂݍ��߂܂���ł���"		//�G���[���b�Z�[�W

//##################### �}�N����` ##########################
#define VOLUME_MAX		255	//���ʂ̍ő�l

//##################### �񋓌^ #########################
enum SE_EFFECT
{
	SE_EFFECT_ATACK			//�U���G�t�F�N�g�̌��ʉ�
};

enum BGM_TYPE
{
	BGM_TYPE_TITLE,			//�^�C�g��BGM
	BGM_TYPE_SELECT,		//�I����ʂ�BGM
	BGM_TYPE_END			//�G���hBGM
};

enum BGM_TYPE_PLAY
{
	BGM_PLAY_ADD			//�����Z��BGM
};

//##################### �N���X��` ############################
class Music
{
private:

	std::string FilePath;		//�t�@�C���p�X
	std::string FileName;		//���O

	std::vector<int> Handle;	//�n���h��
	int PlayType;				//���̍Đ����@

	bool IsLoad;				//�ǂݍ��߂���
	std::vector<bool> IsPlayed;	//�Đ��ς݂�


public:

	Music(const char *, const char *);		//�R���X�g���N�^

	~Music();								//�f�X�g���N�^

	bool GetIsLoad();						//�ǂݍ��߂������擾����
	bool GetIsPlay(int);					//�����Đ�����Ă��邩�擾����
	int GetSize();							//���y������ޓ����Ă��邩�擾
	void SetInit(int, double);				//�����ݒ�

	void ChengePlayType(int);				//���̍Đ����@��ύX����
	void ChengeVolume(double,int);			//���ʂ�ύX����

	void Play(int,bool check =true);		//�����Đ�����
	void PlayOne(int,bool check = true);	//�����Đ�����(1�񂾂�)

	void PlayReset(int);					//�Đ��ς݂��ǂ��������Z�b�g����(�w�肳�ꂽ���̂���)
	void PlayReset();						//�Đ��ς݂��ǂ��������Z�b�g����(�S��)

	void Stop();							//�����~�߂�(�S��)
	void Stop(int);							//�����~�߂�(�w�肳�ꂽ���̂���)

	bool Add(const char*, const char*);		//����ǉ�����

};
