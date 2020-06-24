/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Image.cpp     																				�@ */
/* �摜�N���X 																					�@ */

/*
�ǉ����@
�E�t�H���_���ƃt�@�C�������}�N����`����
�EAdd�������g�p���āA�摜��ǂݍ���
*/

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Global.hpp"
#include <string>
#include <vector>

//########## �}�N����`�F�摜�̃t�@�C���p�X�Ɩ��O ##########
#define IMG_DIR_BACK		R"(.\MY_IMG\Back)"				//�w�i�摜�̃t�@�C���̏ꏊ

#define IMG_NAME_TITLE		R"(\title.jpg)"					//�^�C�g����ʂ̔w�i�摜�̖��O
#define IMG_NAME_PLAY		R"(\play.jpg)"					//�v���C��ʂ̔w�i�摜�̖��O
#define IMG_NAME_SELECT		R"(\select.jpg)"				//�I����ʂ̔w�i�摜�̖��O
#define IMG_NAME_END		R"(\end.jpg)"					//�G���h��ʂ̉摜�̖��O

#define FADE_MAX_CNT	60	//�t�F�[�h�����̃J�E���g�ő�l
#define TOUKA_MAX_VALUE	255	//���߂̍ő�l

//########## �}�N����`�F�G���[���b�Z�[�W##########
#define IMAGE_ERROR_TITLE "IMAGE_ERROR"					//�G���[�^�C�g��
#define IMAGE_ERROR_MSG	"�摜���ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//########## �񋓌^ ################
enum BACK_IMAGE
{
	TITLE_BACK,		//�^�C�g����ʂ̔w�i�摜
	PLAY_BACK,		//�v���C��ʂ̔w�i�摜
	SELECT_BACK,	//�I����ʂ̔w�i�摜
	END_BACK		//�G���h��ʂ̉摜
};

using std::string;

//########## �N���X�̒�` ##########
class Image
{
private:
	std::string FilePath;	//�p�X
	std::string FileName;	//���O

	std::vector<int> Handle;				//�n���h��

	std::vector<int> Width;					//��
	std::vector<int> Height;				//����

	int ImageKind;				//�ǂݍ��񂾉摜�̎��
	int Draw_Num;				//�`�悷��摜�̔ԍ�

	bool IsLoad;				//�ǂݍ��߂����H
	std::vector<bool> IsDraw;	//�`�悵�Ă悢��
	std::vector<bool> IsFade;	//�t�F�[�h�A�E�g���邩
	std::vector<bool> FadeEnd;	//�t�F�[�h�G�t�F�N�g���I�������

public:
	Image(const char *,const char *);	//�R���X�g���N�^
	virtual ~Image();					//�f�X�g���N�^

	std::string GetFileName(void);	//���O���擾

	void SetInit(void);				//�T�C�Y���Z�b�g
	int GetSize();					//�摜�����擾

	int GetWidth();		//�����擾
	int GetHeight();	//�������擾

	bool GetIsLoad(void);			//�ǂݍ��߂��H
	void SetIsDraw(bool);			//�`�悵�Ă悢���ݒ�

	void Draw(int, int);		//�摜��`��
	void DrawCenter(int width = GAME_WIDTH,int height = GAME_HEIGHT);	//�摜��`��i�����j

	bool AddImage(const char *, const char *);	//�摜��ǉ�
	void ChengeImage(int);						//�`�悷��摜��ύX
	void NextImage();							//�`�悷��摜������̉摜��
	void NextImage(int);						//�`�悷��摜���w�肳�ꂽ���A���̉摜��
	void PrevImage();							//�`�悷��摜����O�̉摜��
	void PrevImage(int);						//�`�悷��摜���w�肳�ꂽ���A�O�̉摜��
	void ChengeImageFront();					//�`�悷��摜��擪�̉摜��

	void SetIsFade(bool);		//�t�F�[�h�A�E�g���邩�ݒ�
	bool GetFadeEnd();			//�t�F�[�h�G�t�F�N�g���I�����Ă��邩�擾

};

