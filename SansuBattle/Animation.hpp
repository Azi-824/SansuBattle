//Animation.hpp
//�A�j���[�V�������Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"

//###################### �}�N����`�F�t�@�C���p�X�A���O ######################
#define ANIM_DIR				R"(.\Anim)"			//�A�j���[�V�����̉摜�t�@�C���̏ꏊ

#define ANIM_NAME_DAMEGE		R"(\Damege.png)"	//�_���[�W�G�t�F�N�g�̉摜�̖��O

//###################### �}�N����`�F�G���[���b�Z�[�W ########################
#define ANIMATION_ERROR_TTILE	"ANIMATION_ERROR"						//�G���[�^�C�g��
#define ANIMATION_ERROR_MSG		"�A�j���[�V�������ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//############ �}�N����` ##############
//********************** �T�C�Y ************************
#define ANIM_DAMEGE_WIDTH		240	//������
#define ANIM_DAMEGE_HEIGHT		240	//��������

//********************** ������ **************************
#define ANIM_DAMEGE_YOKO_CNT		7	//��������
#define ANIM_DAMEGE_TATE_CNT		1	//�c������

//************************ �������� **************************
#define ANIM_DAMEGE_ALL_CNT	ANIM_DAMEGE_YOKO_CNT * ANIM_DAMEGE_TATE_CNT	//��������

//************************ �`�摬�x ***************************
#define ANIM_DAMEGE_SPEED		0.08

//############## �񋓌^ #################
enum ANIM_LIST
{
	ANIM_DAMEGE,	//�U��
};

using std::vector;
using std::string;

//############ �N���X��` ##############
class Animation
{
private:

	static vector<vector<int>> AnimList;//�A�j���[�V�����ꗗ

	vector<int> Handle;					//�n���h��
	vector<int>::iterator Handle_itr;	//�n���h���̃C�e���[�^

	int Width;					//��
	int Height;					//����

	double NextChangeSpeed;		//�A�j���[�V������ύX���鑬��(�b)
	int ChangeCnt;				//�A�j���[�V��������t���[���̃J�E���g
	int ChangeMaxCnt;			//�A�j���[�V��������t���[���̍ő�l

	bool IsAnimeLoop;			//�A�j���[�V�����̓��[�v����H
	bool IsDrawEnd;				//�`��I��������
	bool IsNowDraw;				//�`�撆��

	bool IsLoad;				//�ǂݍ��߂����H

public:

	static bool CreateList();		//���X�g�쐬
	static void DeleteHandle();		//���X�g�̃n���h�����폜

	Animation(int, double, bool);	//�R���X�g���N�^
	~Animation();					//�f�X�g���N�^

	void SetInit();			//�����ݒ�

	int GetWidth();			//�����擾
	int GetHeight();		//�������擾

	bool GetIsLoad(void);	//�ǂݍ��߂��H
	bool GetIsDrawEnd();	//�`��I���������擾
	bool GetIsNowDraw();	//�`�撆���擾

	void Reset();			//���Z�b�g

	void Draw(int, int);	//�`��
	void DrawCenter();		//��ʒ����ɕ`��
	void DrawCenter(RECT);	//�w�肳�ꂽ�̈���̒����ɕ`��


};
