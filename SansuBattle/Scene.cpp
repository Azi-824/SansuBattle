//Scene.cpp

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Scene.hpp"

//############## �N���X��` ################

int Scene::NowScene = 0;	//���݂̃V�[��
bool Scene::GameEnd = false;//�Q�[���G���h�t���O
vector<Font*> Scene::font;	//�t�H���g

//�R���X�g���N�^
Scene::Scene()
{
	back = new Image();	//�C���X�^���X����
	bgm = new Music();	//�C���X�^���X����
	IsLoad = false;		//�ǂݍ��߂���
}

//�f�X�g���N�^
Scene::~Scene()
{
	delete back;	//back�j��
	delete bgm;		//bgm�j��
}

//���݂̃V�[�����擾
int Scene::GetNowScene()
{
	return NowScene;
}

//�Q�[���G���h�t���O���擾
bool Scene::IsGameEnd()
{
	return GameEnd;
}