//Music.hpp
//���y�p�N���X

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

#define BGM_NAME_TITLE_BGM			R"(\title_bgm.mp3)"		//�^�C�g����BGM�̖��O
#define BGM_NAME_SELECT_BGM			R"(\select_bgm.mp3)"	//�I����ʂ�BGM�̖��O
//�v���C���
#define BGM_NAME_PLAY_SUM_BGM			R"(\play_add_bgm.mp3)"			//�v���C��ʁi�����Z�j��BGM�̖��O
#define BGM_NAME_PLAY_DIFF_BGM			R"(\play_diff_bgm.mp3)"			//�v���C��ʁi�����Z�j��BGM�̖��O
#define BGM_NAME_PLAY_PRO_BGM			R"(\play_pro_bgm.mp3)"			//�v���C��ʁi�|���Z�j��BGM�̖��O
#define BGM_NAME_PLAY_DEA_BGM			R"(\play_dealer_bgm.mp3)"		//�v���C��ʁi����Z�j��BGM�̖��O
#define BGM_NAME_PLAY_SUM_DIF_BGM		R"(\play_sum_dif_bgm.mp3)"		//�v���C��ʁi�����Z�A�����Z�j��BGM�̖��O
#define BGM_NAME_PLAY_PRO_DEA_BGM		R"(\play_pro_dea_bgm.mp3)"		//�v���C��ʁi�|���Z�A����Z�j��BGM�̖��O
#define BGM_NAME_PLAY_SUM_PRO_BGM		R"(\play_sum_pro_bgm.mp3)"		//�v���C��ʁi+*�j��BGM�̖��O
#define BGM_NAME_PLAY_SUM_DEA_BGM		R"(\play_sum_dea_bgm.mp3)"		//�v���C��ʁi+/�j��BGM�̖��O
#define BGM_NAME_PLAY_DIF_PRO_BGM		R"(\play_dif_pro_bgm.mp3)"		//�v���C��ʁi-*�j��BGM�̖��O
#define BGM_NAME_PLAY_SUM_DIF_PRO_BGM	R"(\play_sum_dif_pro_bgm.mp3)"	//�v���C��ʁi+-*�j��BGM�̖��O
#define BGM_NAME_PLAY_SUM_DIF_DEA_BGM	R"(\play_sum_dif_dea_bgm.mp3)"	//�v���C��ʁi+-/�j��BGM�̖��O
#define BGM_NAME_PLAY_ALL_BGM			R"(\play_all_bgm.mp3)"			//�v���C��ʁi+-*/�j��BGM�̖��O

#define BGM_NAME_END_BGM			R"(\end_bgm.mp3)"		//�G���h��ʂ�BGM�̖��O

#define SE_NAME_KETTEI			R"(\kettei.mp3)"		//����̌��ʉ�SE

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

enum SE_KEY
{
	SE_KEY_KETTEI			//�L�[����i����j�̌��ʉ�
};

enum BGM_TYPE
{
	BGM_TYPE_TITLE,			//�^�C�g��BGM
	BGM_TYPE_SELECT,		//�I����ʂ�BGM
	BGM_TYPE_END			//�G���hBGM
};

using std::string;

//##################### �N���X��` ############################
class Music
{
private:

	string FilePath;		//�t�@�C���p�X
	string FileName;		//���O

	int Handle;				//�n���h��
	int PlayType;			//���̍Đ����@

	bool IsLoad;			//�ǂݍ��߂���
	bool IsPlayed;			//�Đ��ς݂�


public:

	Music(const char *, const char *);		//�R���X�g���N�^

	~Music();								//�f�X�g���N�^

	bool GetIsLoad();						//�ǂݍ��߂������擾����
	bool GetIsPlay();					//�����Đ�����Ă��邩�擾����
	void SetInit(int, double);				//�����ݒ�

	void ChengePlayType(int);				//���̍Đ����@��ύX����
	void ChengeVolume(double);			//���ʂ�ύX����

	void Play(bool check =true);		//�����Đ�����
	void PlayOne(bool check = true);	//�����Đ�����(1�񂾂�)

	void PlayReset();						//�Đ��ς݂��ǂ��������Z�b�g����(�S��)

	void Stop();							//�����~�߂�(�S��)

};
