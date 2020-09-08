//Ranking.cpp
//�����L���O��ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Ranking.hpp"

//############# �N���X��` ################

//�R���X�g���N�^
Ranking::Ranking()
{
	//�摜�֌W
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_RANKING)) { IsLoad = false; return; }	//�w�i�摜�ǂݍ���

	if (!bgm.front()->Load(MUSIC_DIR_BGM, BGM_NAME_RANKING)) { IsLoad = false; return; }	//BGM�ǂݍ���
	IsLoad = true;

}

//�f�X�g���N�^
Ranking::~Ranking()
{

}

//�����ݒ�
void Ranking::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	for (auto b : bgm) { b->SetInit(DX_PLAYTYPE_LOOP, VOL_DEF); }	//BGM�����ݒ�

}


//�����L���O��ʂ̏���
void Ranking::Run()
{

	bgm.front()->Play();			//BGM�𗬂�
	back->Draw(GAME_LEFT, GAME_TOP);//�w�i�`��

	//***************** �X�R�A�̕`�� ********************
	font.at(HANDLE_RANK)->Chenge();				//�t�H���g�ύX
	for (auto d : data) { d->Draw(GameMode); }	//�X�R�A�`��
	font.at(HANDLE_NR)->Chenge();				//�t�H���g�ύX

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm.front()->Stop();	//BGM���~�߂�
		NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
	}

}