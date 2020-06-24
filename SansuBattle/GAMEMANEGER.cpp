//GameManeger.cpp
//�Q�[���̃V�X�e�����Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� ################
#include "GameManeger.hpp"

//############### �N���X��` ################

//�R���X�g���N�^
GameManeger::GameManeger()
{
	//�I�u�W�F�N�g�̐���
	fps = new Fps(GAME_FPS_SPEED);	//FPS�N���X�̃I�u�W�F�N�g�𐶐�
	keydown = new KeyDown();			//KEYDOWN�N���X�̃I�u�W�F�N�g�𐶐�

	//�����o�[�ϐ�������
	NowScene = (int)SCENE_LOAD;		//�ŏ��̃V�[���́A���[�h���
	IsLoad = false;					//�ǂݍ��݁A������
	GameMode = -1;					//�Q�[�����[�h������
	GameLevel = -1;					//�Q�[�����x��������
	GameEndFlg = false;				//�Q�[���I���t���O������
	return;

}

//�f�X�g���N�^
GameManeger::~GameManeger()
{
	//�I�u�W�F�N�g�̔j��
	delete fps;				//fps�j��
	delete keydown;			//keydown�j��
	delete back;			//back�j��
	delete select_gamemode;	//level_select�j��
	delete select_level;	//stage_select�j��
	delete player;			//player�j��
	delete gamelimittime;	//gamelimittime�j��
	delete effect_atk;		//effect_atk�j��
	delete save;			//save�j��

	//���y�֌W
	//BGM
	for (auto bgm : this->bgm)
	{
		delete bgm;		//bgm�j��
	}
	//�v���C��ʂ�BGM
	for (auto bgm : bgm_play)
	{
		delete bgm;		//bgm_play�j��
	}

	//�t�H���g�֌W
	Font::ReleaseFont();	//�ǂݍ��񂾃t�H���g���J��
	for (int i = 0; i < font.size(); ++i)	//�t�H���g�n���h���̐���
		delete font.at(i);	//font�j��
	
	//���֌W
	for (int i = 0; i < question.size(); ++i)	//���̎�ޕ�
		delete question.at(i);	//question�j��

	//�G�֌W
	for (int i = 0; i < enemy.size(); ++i)	//�G�̐���
		delete enemy.at(i);	//enemy�̔j��

	//�X�R�A�֌W
	for (int i = 0; i < score.size(); ++i)	//�X�R�A�̎�ޕ�
		delete score.at(i);	//score�j��

	//vector�̃�����������s��
	vector<Question*> v;		//���vector���쐬����
	question.swap(v);		//��ƒ��g�����ւ���

	//vector�̃�����������s��
	vector<Enemy*> v2;		//���vector���쐬����
	enemy.swap(v2);			//��ƒ��g�����ւ���

	//vector�̃�����������s��
	vector<Score*> v3;		//���vector���쐬����
	score.swap(v3);			//��ƒ��g�����ւ���

	//vector�̃�����������s��
	vector<Font*> v4;		//���vector���쐬����
	font.swap(v4);			//��ƒ��g�����ւ���

	//vector�̃�����������s��
	vector<Music*> v5;		//���vector���쐬����
	bgm.swap(v5);			//��ƒ��g�����ւ���

	//vector�̃�����������s��
	vector<Music*> v6;		//���vector���쐬����
	bgm_play.swap(v6);		//��ƒ��g�����ւ���

	return;

}

//�Q�[�����Ŏg�p����f�[�^�̓ǂݍ��ݏ���
/*
�߂�l�Ftrue�F����
�߂�l�Ffalse�F�G���[�A�����I��
*/
bool GameManeger::Load()
{

	//�t�H���g�֌W
	if (Font::LoadFont(FONT_DIR, FONT_FILE_NAME, FONT_NAME) == false) { return false; }	//�t�H���g��ǂݍ���
	font.push_back(new Font((int)FONT_NAME_KOKUBAN, DEFAULT_FONTSIZE, FONT_BOLD_DEFAULT, DX_FONTTYPE_ANTIALIASING));		//�t�H���g���Ǘ�����I�u�W�F�N�g�𐶐�
	font.push_back(new Font((int)FONT_NAME_KOKUBAN, FONTSIZE_DRAW_RANKING, FONT_BOLD_DEFAULT, DX_FONTTYPE_ANTIALIASING));	//�����΂�t�H���g�i�~�j�T�C�Y�j�쐬
	for(int i = 0; i < font.size(); ++i)								//�t�H���g�n���h���̎�ޕ�
	if (font.at(i)->GetIsCreate() == false) { return false; }			//�ǂݍ��ݎ��s
	NowFontHandle = font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle();	//�g�p����t�H���g�������΂�t�H���g�ɕύX

	//���Ԋ֌W
	gamelimittime = new Time();		//�Q�[���̐������Ԃ��Ǘ�����I�u�W�F�N�g�𐶐�

	//�摜�֌W
	//�w�i�摜
	back = new Image(IMG_DIR_BACK, IMG_NAME_TITLE);		//�w�i�摜���Ǘ�����I�u�W�F�N�g�𐶐�
	if (back->GetIsLoad() == false) { return false; }		//�ǂݍ��ݎ��s
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_PLAY) == false) { return false; }		//�v���C��ʂ̔w�i�摜��ǉ�
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_SELECT) == false) { return false; }	//�I����ʂ̔w�i�摜��ǉ�
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_END) == false) { return false; }	//�_�~�[�摜��ǉ�

	//�I�����֌W
	//��Փx�̑I����
	select_gamemode = new Select(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM, Q_MODE_SUM);		//��Փx�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (select_gamemode->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DIFFERENCE, Q_MODE_DIFFERENCE) == false) { return false; }		//�_�~�[�摜�ǉ�
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRODUCT, Q_MODE_PRODUCT) == false) { return false; }		//�_�~�[�摜�ǉ�
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DEALER, Q_MODE_DEALER) == false) { return false; }			//�_�~�[�摜�ǉ�
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM_DIFF, Q_MODE_SUM_DIFFERENCE) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (select_gamemode->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRO_DEA, Q_MODE_PRODUCT_DEALER) == false) { return false; }	//�_�~�[�摜�ǉ�

	//�X�e�[�W�̑I����
	select_level = new Select(SELECT_IMG_DIR, IMG_NAME_SELECTLEVEL_EASY, STAGE_LEVEL_EASY);		//�X�e�[�W�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (select_level->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (select_level->Add(SELECT_IMG_DIR, IMG_NAME_SELECTLEVEL_NORMAL, STAGE_LEVEL_NORMAL) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (select_level->Add(SELECT_IMG_DIR, IMG_NAME_SELECTLEVEL_HARD, STAGE_LEVEL_HARD) == false) { return false; }	//�_�~�[�摜�ǉ�


	//�v���C���[�֌W
	player = new Player();		//�v���C���[���Ǘ�����I�u�W�F�N�g�𐶐�

	//�G�֌W
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY_FIRST));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(1�̖�)
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY_SECOND));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(2�̖�)
	enemy.push_back(new Enemy(IMG_DIR_ENEMY, IMG_NAME_ENEMY_THIRD));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(3�̖�)
	for (int i = 0; i < enemy.size(); ++i)	//�G�̐�����
	{
		if (enemy.at(i)->GetIsLoad() == false) { return false; }		//�ǂݍ��ݎ��s
	}

	//�G�t�F�N�g�֌W
	effect_atk = new Effect(EFFECT_DIR, EFFECT_NAME_ATACK, EFFECT_ATACK_ALL_CNT, EFFECT_ATACK_YOKO_CNT, EFFECT_ATACK_TATE_CNT, EFFECT_ATACK_WIDTH, EFFECT_ATACK_HEIGHT, EFFECT_ATACK_SPEED, false);	//�U���G�t�F�N�g���Ǘ�����I�u�W�F�N�g�𐶐�
	if (effect_atk->GetIsLoad() == false) { return false; }//�ǂݍ��ݎ��s
	if (effect_atk->AddSe(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_ATK) == false) { return false; }	//���ʉ��ǉ�

	//���y�֌W
	//BGM
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_TITLE_BGM));					//BGM���Ǘ�����I�u�W�F�N�g�𐶐�
	bgm.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_SELECT_BGM));					//�I������ʂ�BGM�ǉ�
	for (auto bgm : this->bgm)
	{
		if (bgm->GetIsLoad() == false) { return false; }	//�ǂݍ��ݎ��s
		bgm->SetInit(DX_PLAYTYPE_LOOP, 30);					//�����ݒ�
	}

	bgm_play.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_ADD_BGM));					//BGM(�v���C���)���Ǘ�����I�u�W�F�N�g�𐶐�
	bgm_play.push_back(new Music(MUSIC_DIR_BGM, BGM_NAME_PLAY_DIFF_BGM));				//�v���C��ʁi�����Z�j��BGM�ǉ�
	for (auto bgm : bgm_play)
	{
		if (bgm->GetIsLoad() == false) { return false; }	//�ǂݍ��ݎ��s
		bgm->SetInit(DX_PLAYTYPE_LOOP, 30);					//�����ݒ�
	}

	//���֌W
	//�����Z
	question.push_back(new QuestionAdd());			//�����Z�̖����Ǘ�����I�u�W�F�N�g�𐶐�
	question.push_back(new QuestionDifference());	//�����Z�̖����Ǘ�����I�u�W�F�N�g�𐶐�

	//�X�R�A�֌W
	//�����Z
	score.push_back(new ScoreAdd());		//�����Z�̃X�R�A���Ǘ�����I�u�W�F�N�g�𐶐�
	score.push_back(new ScoreDifference());	//�����Z�̃X�R�A���Ǘ�����I�u�W�F�N�g�𐶐�

	//�Z�[�u�f�[�^�֌W
	save = new SaveData();			//�Z�[�u�f�[�^���Ǘ�����I�u�W�F�N�g�𐶐�
	return true;	//�ǂݍ��ݐ���
}

//�Q�[���̃��C�����[�v
/*
�߂�l�Ftrue�F����
�߂�l�Ffalse�F�G���[�A�����I��
*/
bool GameManeger::GameMainLoop()
{
	if (ProcessMessage() != 0) { return false; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

	if (ClearDrawScreen() != 0) { return false; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

	keydown->KeyDownUpdate();	//�L�[�̓��͏�Ԃ��X�V����

	fps->Update();		//FPS�̏���[�X�V]

	if (GameEndFlg) { return false; }		//�Q�[���I���t���O����������A�����I��

	//�����������Q�[���̃V�[���������灥��������

	ProcesScene();		//�e�V�[���̏���

	//�����������Q�[���̃V�[�������܂Ł���������

	//this->fps->Draw(0, 0);		//FPS�`��

	ScreenFlip();				//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

	fps->Wait();			//FPS�̏���[�҂�]

	return true;				//����

}

//�e�V�[���̏���
void GameManeger::ProcesScene()
{
	switch (NowScene)		//���݂̃V�[���̕`�揈�������s
	{

	case (int)SCENE_LOAD:	//���[�h��ʂ̂Ƃ�

		Scene_Load();			//���[�h��ʂ̏���

		Draw_Scene_Load();	//���[�h��ʂ̕`�揈��

		break;				//���[�h��ʂ̂Ƃ������܂�

	case (int)SCENE_TITLE:	//�^�C�g����ʂ̂Ƃ�

		Scene_Title();		//����

		Draw_Scene_Title();	//�`��

		break;				//�^�C�g����ʂ̂Ƃ������܂�

	case (int)SCENE_CHOISELEVEL:	//��Փx�I����ʂ̂Ƃ�

		Scene_ChoiseGameMode();		//����

		Draw_Scene_ChoiseGameMode();	//�`��

		break;				//��Փx�I����ʂ̂Ƃ������܂�

	case (int)SCENE_CHOISESTAGE:	//�X�e�[�W�I����ʂ̂Ƃ�

		Scene_ChoiseLevel();		//����

		Draw_Scene_ChoiseLevel();	//�`��

		break;				//�X�e�[�W�I����ʂ̂Ƃ������܂�

	case (int)SCENE_PLAY:	//�v���C��ʂ̂Ƃ�

		Scene_Play();			//����

		Draw_Scene_Play();	//�`��

		break;				//�v���C��ʂ̂Ƃ������܂�

	case (int)SCENE_DRAWSCORE:	//�X�R�A�\����ʂ̂Ƃ�

		Scene_DrawScore();		//����

		Draw_SceneDrawScore();	//�`��

		break;				//�X�R�A�\����ʂ̂Ƃ������܂�

	case (int)SCENE_END:	//�G���h��ʂ̂Ƃ�

		Scene_End();		//����

		Draw_Scene_End();	//�`��

		break;				//�G���h��ʂ̂Ƃ������܂�

	default:
		break;
	}

	return;	

}

//�����ݒ�
void GameManeger::SetInit()
{
	back->SetInit();			//�摜�����ݒ�
	select_gamemode->SetInit(SELECT_GAMEMODE_DRAW_X, SELECT_GAMEMODE_DRAW_Y, GAME_WIDTH, SELECT_GAMEMODE_INTERVAL_SIDE, SELECT_GAMEMODE_INTERVAL_VERTICAL);	//�Q�[�����[�h�̑I���������ݒ�
	select_level->SetInit(SELECT_LEVEL_DRAW_X, SELECT_LEVEL_DRAW_Y, GAME_WIDTH, SELECT_LEVEL_INTERVAL_SIDE);				//���x���̑I���������ݒ�
	player->SetInit(PLAYER_HP_DRAW_X, PLAYER_HP_DRAW_Y);							//�v���C���[�����ݒ�
	effect_atk->SetInit();															//�G�t�F�N�g�����ݒ�

	for (int i = 0; i < enemy.size(); ++i)
	{
		enemy.at(i)->SetInit();								//�G�̏����ݒ�
	}

	return;
}

//***************************** �V�[�����̏��� ********************************
//���[�h��ʂ̏���
void GameManeger::Scene_Load()
{
	if (IsLoad)	//�ǂݍ��݂��������Ă�����
	{
		if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
		{
			NowScene = (int)SCENE_TITLE;	//�^�C�g����ʂ�
		}
	}
	else		//�ǂݍ��݂��������Ă��Ȃ�������
	{
		if (GetASyncLoadNum() == 0)	//�񓯊��œǂݍ���ł��鏈�����I�������
		{

			SetUseASyncLoadFlag(FALSE);	//�����ǂݍ��݂ɐݒ�

			SetInit();			//�����ݒ�

			IsLoad = true;		//�ǂݍ��݊���
		}

	}


	return;		
}

//���[�h��ʂ̕`�揈��
void GameManeger::Draw_Scene_Load()
{

	if (IsLoad)	//�ǂݍ��݂�����������
	{
		DrawStringToHandle(TEST_TEXT_X, TEST_TEXT_Y, PUSH_TEXT, COLOR_WHITE, font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle());
	}
	else		//�������Ă��Ȃ����
	{
		DrawStringToHandle(TEST_TEXT_X, TEST_TEXT_Y, LOAD_TEXT, COLOR_WHITE, font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle());
	}

	return;
}

//�^�C�g����ʂ̏���
void GameManeger::Scene_Title()
{

	back->ChengeImage((int)TITLE_BACK);	//�w�i�摜��ύX

	bgm.at((int)BGM_TYPE_TITLE)->Play();		//BGM���Đ�

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		bgm.at((int)BGM_TYPE_TITLE)->Stop();//�Đ����̉��y���~�߂�
		NowScene = (int)SCENE_CHOISELEVEL;	//��Փx�I����ʂ�
	}

	return;
}

//�^�C�g����ʂ̕`�揈��
void GameManeger::Draw_Scene_Title()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	return;
}

//�Q�[�����[�h�I����ʂ̏���
void GameManeger::Scene_ChoiseGameMode()
{

	back->ChengeImage((int)SELECT_BACK);	//�w�i�摜��ύX

	bgm.at((int)BGM_TYPE_SELECT)->Play();	//�I����ʂ�BGM���Đ�

	select_gamemode->Operation(keydown);			//�I�����L�[����

	if (select_gamemode->GetIsChoise())			//�I��������
	{
		GameMode = select_gamemode->GetChoiseSelectCode();		//�Q�[�����x���ݒ�

		//(�ǂݍ��ݐ�������true���Ԃ��Ă���̂ŁA���̂܂ܑ������ƃQ�[���I�����Ă��܂����߁A���]�����Ă���B�j
		GameEndFlg = !(save->Load(GameMode));					//�Z�[�u�f�[�^�ǂݍ���

		select_gamemode->Init();	//�Q�[�����[�h�̑I����������

		NowScene = (int)SCENE_CHOISESTAGE;						//�X�e�[�W�I����ʂ�
	}

	return;
}

//�Q�[�����[�h�I����ʂ̕`�揈��
void GameManeger::Draw_Scene_ChoiseGameMode()
{
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	select_gamemode->Draw();				//��Փx�̑I�����`��

	return;
}

//���x���I����ʂ̏���
void GameManeger::Scene_ChoiseLevel()
{

	select_level->Operation(keydown);		//�I�����L�[����

	if (select_level->GetIsChoise())		//�I��������
	{
		GameLevel = select_level->GetChoiseSelectCode();	//�Q�[�����x����ݒ�
		bgm.at((int)BGM_TYPE_SELECT)->Stop();				//�Đ�����BGM���~�߂�
		for (int i = 0; i < enemy.size(); ++i)	//�G�̐������[�v
		{
			enemy.at(i)->Init();			//�G������
		}
		player->Init();						//�v���C���[������
		score.at(GameMode)->ResetScore();	//�X�R�A���Z�b�g
		question.at(GameMode)->Reset();		//���֌W���Z�b�g
		select_level->Init();				//���x���̑I����������
		gamelimittime->SetTime();			//�������Ԃ̌v���J�n
		NowScene = (int)SCENE_PLAY;			//�v���C��ʂ�
	}

	return;
}

//���x���I����ʂ̕`�揈��
void GameManeger::Draw_Scene_ChoiseLevel()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	select_level->Draw();		//�X�e�[�W�I�����`��

	return;
}

//�v���C��ʂ̏���
void GameManeger::Scene_Play()
{

	back->ChengeImage((int)PLAY_BACK);	//�w�i�摜��ύX

	bgm_play.at(GameMode)->Play();			//�v���C��ʂ�BGM���Đ�

	gamelimittime->UpdateLimitTime(GAME_LIMIT_TIME);	//�������Ԃ̍X�V

	if (!question.at(GameMode)->GetIsCreate())	//�����쐬���Ă��Ȃ����
	{
		question.at(GameMode)->CreateQuestion(GameLevel);	//�����쐬
	}

	if (question.at(GameMode)->CheckInputKey(keydown))	//�L�[���͂�����������
	{
		if (question.at(GameMode)->JudgAnser())				//�v���C���[�̉񓚂�������������
		{
			effect_atk->SetIsDraw(true,(int)EFFECT_ATACK);			//�A�j���[�V�����̕`����J�n����
		}
		else		//�s������������
		{
			player->SendDamege();	//�v���C���[�Ƀ_���[�W��^����
		}

	}

	if (effect_atk->GetIsDrawEnd())							//�A�j���[�V�����`�悪�I�������
	{
		effect_atk->SetIsDraw(false, (int)EFFECT_ATACK);					//�A�j���[�V������`�悵�Ȃ�
		effect_atk->ResetIsAnime((int)EFFECT_ATACK);						//�A�j���[�V������Ԃ����Z�b�g
		enemy.at(Enemy::GetNowEnemyNum())->SendDamege();					//�G�Ƀ_���[�W��^����
		score.at(GameMode)->CalcScore(GameLevel, gamelimittime->GetElapsedTime());	//�X�R�A���Z						
		gamelimittime->SetTime();											//�������Ԃ̍Čv��
	}

	if (enemy.at(Enemy::GetNowEnemyNum())->GetHp() <= 0)		//�G��HP��0�ɂȂ�����
	{
		enemy.at(Enemy::GetNowEnemyNum())->SetIsArive(false);	//�G���S
		if (enemy.at(Enemy::GetNowEnemyNum())->GetFadeEnd())	//�t�F�[�h�A�E�g�I��������
		{
			Enemy::NextEnemy();	//���̓G��
		}
	}
	
	if (Enemy::GetNowEnemyNum() >= enemy.size() ||			//�G�̐����A�ő吔�𒴂�����
		player->GetHp() <= 0)								//�v���C���[��HP��0�ɂȂ�����	
	{
		save->Add(score.at(GameMode)->GetScore());	//�X�R�A��ǉ�
		save->Sort();								//�\�[�g����
		bgm_play.at(GameMode)->Stop();				//�Đ�����BGM���~�߂�
		NowScene = (int)SCENE_DRAWSCORE;			//�X�R�A�\����ʂ�
	}

	return;
}

//�v���C��ʂ̕`�揈��
void GameManeger::Draw_Scene_Play()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	player->DrawHp();				//�v���C���[HP�`��

	if (Enemy::GetNowEnemyNum() < enemy.size())	//���݂̓G���A�G�̍ő吔�ʓ���������
	{
		enemy.at(Enemy::GetNowEnemyNum())->DrawCenter();	//�G�L�����`��
		enemy.at(Enemy::GetNowEnemyNum())->DrawHp();		//HP�`��
	}

	question.at(GameMode)->DrawQuestion();				//��蕶�`��
	question.at(GameMode)->DrawInputNum();				//���͒��̐�����`��

	score.at(GameMode)->DrawNowScore();	//���݂̃X�R�A�`��

	gamelimittime->DrawLimitTime(GAME_LIMITTIME_DRAW_X, GAME_LIMITTIME_DRAW_Y, GAME_LIMIT_TIME);			//�������Ԃ̕`��

	effect_atk->DrawCenter((int)EFFECT_ATACK);	//�U���G�t�F�N�g�`��

	return;
}

//�X�R�A�\����ʂ̏���
void GameManeger::Scene_DrawScore()
{

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		NowScene = (int)SCENE_END;	//�G���h��ʂ�
	}

	return;
}

//�X�R�A�\����ʂ̕`�揈��
void GameManeger::Draw_SceneDrawScore()
{
	NowFontHandle = font.at((int)HANDLE_TYPE_KOKUBAN_MINISIZE)->GetHandle();	//�g�p����t�H���g�n���h���ύX
	save->Draw(GameMode);														//�f�[�^�������L���O�\��
	NowFontHandle = font.at((int)HANDLE_TYPE_KOKUBAN_NORMALSIZE)->GetHandle();	//�g�p����t�H���g�n���h���ύX

	return;
}

//�G���h��ʂ̏���
void GameManeger::Scene_End()
{

	back->ChengeImage((int)END_BACK);	//�w�i�摜��ύX

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		NowScene = (int)SCENE_TITLE;	//�^�C�g����ʂ�
	}

	return;
}

//�G���h��ʂ̕`�揈��
void GameManeger::Draw_Scene_End()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}

//�Z�[�u
bool GameManeger::Save()
{
	return save->Save(GameMode);	
}
