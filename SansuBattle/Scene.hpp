//Scene.hpp
//�e�V�[���̊�ɂȂ�N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ######################
#include "Global.hpp"
#include "Image.hpp"
#include "Music.hpp"
#include "Font.hpp"

//################### �}�N����` #########################

//################### �񋓌^ #####################
enum GAME_SCENE
{
	SCENE_LOAD,			//���[�h�V�[��
	SCENE_TITLE,		//�^�C�g���V�[��
	SCENE_SELECT,		//�I���V�[��
	SCENE_PLAY,			//�v���C�V�[��
	SCENE_RANKING		//�����L���O�V�[��
};

enum GAMEMODE_KIND
{
	GAMEMODE_SUM,					//���[�h�A�a�i�����Z�j
	GAMEMODE_DIFFERENCE,			//���[�h�A���i�����Z�j
	GAMEMODE_PRODUCT,				//���[�h�A�ρi�|���Z�j
	GAMEMODE_DEALER,				//���[�h�A���i����Z�j
	GAMEMODE_SUM_DIF,				//���[�h�A�a���i�����Z�A�����Z�j
	GAMEMODE_PRO_DEA,				//���[�h�A�Ϗ��i�|���Z�A����Z�j
	GAMEMODE_SUM_PRO,				//MODE(+*)
	GAMEMODE_SUM_DEA,				//MODE(+/)
	GAMEMODE_DIF_PRO,				//MODE(-*)
	GAMEMODE_SUM_DIF_PRO,			//MODE(+-*)
	GAMEMODE_SUM_DIF_DEA,			//MODE(+-/)
	GAMEMODE_ALL,					//MODE(+-*/)
	GAMEMODE_MAX					//�Q�[�����[�h�̎�ސ�
};	//���̎��

enum GAME_LEVEL
{
	GAME_LEVEL_EASY,		//�ȒP
	GAME_LEVEL_NORMAL,		//����
	GAME_LEVEL_HARD,		//���
	GAME_LEVEL_MAX			//�Q�[�����x���̎�ސ�
};	//�X�e�[�W�̃��x��

using std::vector;

//################### �N���X��` #########################
class Scene
{
protected:

	//�N���X����
	static int NowScene;		//���݂̃V�[��
	static int GameMode;		//�Q�[�����[�h
	static int GameLevel;		//�Q�[�����x��
	static bool GameEnd;		//�Q�[���I���t���O
	static vector<Font*> font;	//�t�H���g

	static bool FadeOut();		//�t�F�[�h�A�E�g����

	//�C���X�^���X��
	Image* back;			//�w�i�摜
	vector<Music*> bgm;		//BGM
	bool IsLoad;			//�ǂݍ��߂���

public:

	Scene();		//�R���X�g���N�^
	~Scene();		//�f�X�g���N�^

	static int GetNowScene();	//���݂̃V�[�����擾
	static bool IsGameEnd();	//�Q�[���G���h�t���O���擾

	virtual void SetInit() = 0;		//�����ݒ�
	virtual void Run() = 0;			//�V�[�����̏���

};
