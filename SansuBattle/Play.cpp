//Play.cpp
//�v���C��ʂ̏���

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Play.hpp"

//################ �N���X��` ################

//�R���X�g���N�^
Play::Play()
{

	//�摜�֌W
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { IsLoad = false; return; }	//�w�i�摜�ǂݍ���

	//BGM
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY)) { IsLoad = false; return; }	//BGM�ǂݍ���

	//********************* �L�����N�^�[ ******************************
	//�v���C���[
	player = new Player();	//�v���C���[����

	//�G
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//�G1�̖ڐ���
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//�G2�̖ڐ���
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//�G3�̖ڐ���

	IsLoad = true;	//�ǂݍ��ݐ���

}

//�f�X�g���N�^
Play::~Play()
{
	delete player;		//player�j��
	
	//�G
	for (auto e : enemy) { delete e; }	//enemy�j��
	vector<Enemy*> v;
	v.swap(enemy);	
}

//�����ݒ�
void Play::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�

	//�v���C���[
	if (!player->SetInit()) { IsLoad = false; return; }	//�����ݒ�
	//�G
	for (auto e : enemy)
	{
		if (!e->SetInit()) { IsLoad = false; return; }	//�����ݒ�
	}
}

//�v���C��ʂ̏���
void Play::Run()
{

	bgm->Play();	//BGM�𗬂�
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	player->Draw();	//�v���C���[�iHP�j�`��
	enemy.at(Enemy::GetNowEnemyNum())->Draw();	//�G�L�����`��

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm->Stop();				//BGM���~�߂�
		NowScene = SCENE_RANKING;	//�����L���O��ʂ�
	}

}
