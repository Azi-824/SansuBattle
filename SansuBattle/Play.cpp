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
	bgm.front()->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM);				//BGM�ǉ��i+�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DIF));			//BGM�ǉ��i-�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_PRO));			//BGM�ǉ��i*�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DEA));			//BGM�ǉ��i/�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DIF));		//BGM�ǉ��i+-�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_PRO_DEA));		//BGM�ǉ��i*/�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_PRO));		//BGM�ǉ��i+*�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DEA));		//BGM�ǉ��i+/�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DIF_PRO));		//BGM�ǉ��i-*�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DIF_PRO));	//BGM�ǉ��i+-*�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_SUM_DIF_DEA));	//BGM�ǉ��i+-/�j
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_ALL));			//BGM�ǉ��i + -*/ �j
	for (auto b : bgm) { if (!b->GetIsLoad()) { IsLoad = false; return; } }	//�ǂݍ��ݎ��s

	//********************* �L�����N�^�[ ******************************
	//�v���C���[
	player = new Player();	//�v���C���[����

	//�G
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY01));	//�G1�̖ڐ���
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY02));	//�G2�̖ڐ���
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY03));	//�G3�̖ڐ���

	//����
	limit = new Time(LIMIT_TIME);		//��������

	IsLoad = true;	//�ǂݍ��ݐ���

}

//�f�X�g���N�^
Play::~Play()
{
	delete player;		//player�j��
	delete limit;		//limit�j��
	
	//�G
	for (auto e : enemy) { delete e; }	//enemy�j��
	vector<Enemy*> v;
	v.swap(enemy);	
}

//�����ݒ�
void Play::SetInit()
{

	font.at(HANDLE_NR)->Chenge();	//�t�H���g�n���h�����m�[�}���ɕύX

	back->SetInit();	//�w�i�摜�����ݒ�
	for (auto b : bgm) { b->SetInit(DX_PLAYTYPE_LOOP, VOL_DEF); }	//BGM�����ݒ�

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
	static bool start = false;
	if (!start)
	{
		quesiton.push_back(new Question(GameMode, GameLevel));	//�����쐬
		limit->SetTime();		//�������Ԃ̌v���J�n
		start = true;
	}

	bgm.at(GameMode)->Play();			//BGM�𗬂�
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	player->Draw();								//�v���C���[�iHP�j�`��
	enemy.at(Enemy::GetNowEnemyNum())->Draw();	//�G�L�����`��

	quesiton.back()->DrawQuestion();	//���`��

	player->DrawInputNum();			//���͒��̒l��`��

	limit->UpdateLimitTime();			//�������Ԃ̍X�V
	limit->DrawLimitTime(LIMIT_DRAW_X, LIMIT_DRAW_Y);	//�������ԕ`��

	if (player->CheckInputKey())	//�L�[���͂�����������
	{
		if (quesiton.back()->JudgAnser(player->GetAns()))	//�v���C���[�̉񓚂�������������
		{
			enemy.at(Enemy::GetNowEnemyNum())->SetDamegeFlg(true);		//�G�Ƀ_���[�W�t���O�𗧂Ă�
		}
		else		//�s������������
		{
			//play_se.at(SE_PLAY_FALSE)->Play();				//�s�����̌��ʉ�
			limit->MinusLimitTime(MISS_MINUS_TIME);		//�������Ԃ����炷
			player->InpReset();							//���͏�񃊃Z�b�g
		}

	}

	if (enemy.at(Enemy::GetNowEnemyNum())->GetIsEffectEnd())	//�G�t�F�N�g�I��������
	{
		enemy.at(Enemy::GetNowEnemyNum())->SendDamege();		//�G�Ƀ_���[�W��^����
		player->InpReset();										//���͏�񃊃Z�b�g
		quesiton.push_back(new Question(GameMode, GameLevel));	//���̖��𐶐�
		limit->SetTime();		//�������Ԃ̍Čv���J�n
	}

	if (limit->GetIsLimit())	//�������Ԃ𒴂�����
	{
		player->SendDamege();	//�v���C���[�Ƀ_���[�W��^����
		quesiton.push_back(new Question(GameMode, GameLevel));	//���̖����쐬
		limit->SetTime();		//�������Ԃ̍Čv���J�n
	}

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm.at(GameMode)->Stop();	//BGM���~�߂�
		NowScene = SCENE_RANKING;	//�����L���O��ʂ�
	}

}
