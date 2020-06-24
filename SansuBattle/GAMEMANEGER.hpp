//GameManeger.hpp
//�Q�[���̃V�X�e�����Ǘ�����N���X

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Global.hpp"
#include "Fps.hpp"
#include "KeyDown.hpp"
#include "Image.hpp"
#include "Select.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "QuestionAdd.hpp"
#include "QuestionDifference.hpp"
#include "Font.hpp"
#include "Time.hpp"
#include "Effect.hpp"
#include "Music.hpp"
#include "ScoreAdd.hpp"
#include "ScoreDifference.hpp"
#include "SaveData.hpp"

//############### �}�N����` ################
//�e�L�X�g�֌W
#define LOAD_TEXT			"NowLoading�c"		//���[�h��ʂ̃e�L�X�g
#define PUSH_TEXT			"PushEnter"			//�G���^�[�L�[�������A�̃e�L�X�g
#define TITLE_TEXT			"NowTitle"			//�^�C�g����ʂ̃e�L�X�g
#define CHOISELEVEL_TEXT	"ChoiseLevel"		//��Փx�I����ʂ̃e�L�X�g
#define CHOISESTAGE_TEXT	"ChoiseStage"		//�X�e�[�W�I����ʂ̃e�L�X�g
#define PLAY_TEXT			"NowPlay"			//�v���C��ʂ̃e�L�X�g
#define DRAWSCORE_TEXT		"DrawScore"			//�X�R�A�\����ʂ̃e�L�X�g
#define END_TEXT			"NowEnd"			//�G���h��ʂ̃e�L�X�g

//���W�֌W
#define TEST_TEXT_X	0					//�e�X�g�p�̃e�L�X�g�`��X�ʒu
#define TEST_TEXT_Y	0					//�e�X�g�p�̃e�L�X�g�`��Y�ʒu

//############### �񋓌^ ################
enum GAME_SCENE
{
	SCENE_LOAD,			//���[�h�V�[��
	SCENE_TITLE,		//�^�C�g���V�[��
	SCENE_CHOISELEVEL,	//��Փx�I���V�[��
	SCENE_CHOISESTAGE,	//�X�e�[�W�I���V�[��
	SCENE_PLAY,			//�v���C�V�[��
	SCENE_DRAWSCORE,	//�X�R�A�\���V�[��
	SCENE_END			//�G���h�V�[��
};

//############### �N���X��` ################
class GameManeger
{

private:

	Fps *fps;					//fps
	KeyDown *keydown;			//�L�[�{�[�h�֌W
	Image* back;				//�w�i�摜
	Select* select_gamemode;	//�Q�[�����[�h�I����
	Select* select_level;		//���x���I����
	Player* player;				//�v���C���[
	vector<Enemy*> enemy;		//�G�L����
	vector<Question*> question;	//���
	vector<Font*> font;			//�t�H���g
	Time* gamelimittime;		//�Q�[����������
	Effect* effect_atk;			//�U���G�t�F�N�g
	vector<Music*> bgm;			//BGM
	vector<Music*> bgm_play;	//�v���C��ʂ�BGM
	vector<Score*> score;		//�X�R�A
	SaveData* save;				//�Z�[�u�f�[�^
	
	int NowScene;				//���݂̃V�[��
	int GameMode;				//�Q�[���̃��[�h
	int GameLevel;				//�Q�[�����x��
	bool IsLoad;				//�ǂݍ��݂��I�������
	bool GameEndFlg;			//�Q�[���I���t���O

public:

	GameManeger();				//�R���X�g���N�^
	~GameManeger();				//�f�X�g���N�^

	bool Load();				//�Q�[���Ɏg�p����f�[�^�̓ǂݍ��ݏ���
	bool GameMainLoop();		//�Q�[���̃��C�����[�v

	void ProcesScene();			//�e�V�[���̏���
	void SetInit();				//�����ݒ�


	//****************** �V�[���֌W *************************
	void Scene_Load();				//���[�h��ʂ̏���
	void Draw_Scene_Load();			//���[�h��ʂ̕`�揈��

	void Scene_Title();				//�^�C�g����ʂ̏���
	void Draw_Scene_Title();		//�^�C�g����ʂ̕`�揈��

	void Scene_ChoiseGameMode();		//�Q�[�����[�h�I����ʂ̏���
	void Draw_Scene_ChoiseGameMode();	//�Q�[�����[�h�I����ʂ̕`�揈��

	void Scene_ChoiseLevel();		//���x���I����ʂ̏���
	void Draw_Scene_ChoiseLevel();	//���x���I����ʂ̕`�揈��

	void Scene_Play();				//�v���C��ʂ̏���
	void Draw_Scene_Play();			//�v���C��ʂ̕`�揈��

	void Scene_DrawScore();			//�X�R�A�\����ʂ̏���
	void Draw_SceneDrawScore();		//�X�R�A�\����ʂ̕`�揈��
		
	void Scene_End();				//�G���h��ʂ̏���
	void Draw_Scene_End();			//�G���h��ʂ̕`�揈��

	bool Save();					//�Z�[�u

};
