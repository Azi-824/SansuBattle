//Enemy.cpp
//�G���Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Enemy.hpp"

//############### �N���X��` #####################

//�C���X�^���X�𐶐�
int Enemy::NowEnemyNum = 0;

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
Enemy::Enemy(const char* dir, const char* name)
{
	//�摜����
	img = new Image(dir, name);	//�摜����
	hp_img->Load(IMG_DIR_ENEMY, IMG_NAME_ENEMY_HP);	//HP�摜����

	//�_���[�W�G�t�F�N�g����
	damege = new Effect(new Animation(ANIM_DAMEGE, ANIM_DAMEGE_SPEED, false), new Music(MUSIC_DIR_EFFECT, SE_NAME_EF_DAMEGE));
	dmgFlg = false;	//�_���[�W�t���O

	HP_X = ENEMY_HP_DRAW_X;//HP�`��X�ʒu
	HP_Y = ENEMY_HP_DRAW_Y;//HP�`��Y�ʒu

	rect = { 0 };	//�`��͈�

}

//�f�X�g���N�^
Enemy::~Enemy()
{
	delete img;		//img�j��
	delete damege;	//damege�j��
}

//�����ݒ�
bool Enemy::SetInit()
{
	if (!hp_img->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	if (!img->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	if (!damege->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	img->SetInit();		//�G�L�����摜�����ݒ�
	hp_img->SetInit();	//HP
	damege->SetInit();	//�_���[�W�G�t�F�N�g

	//�`��͈͐ݒ�
	rect.left = GAME_WIDTH / 2 - img->GetWidth() / 2;
	rect.top = GAME_HEIGHT / 2 - img->GetHeight() / 2;
	rect.right = rect.left + img->GetWidth();
	rect.bottom = rect.top + img->GetHeight();
}

//������
void Enemy::Init()
{
	NowEnemyNum = 0;	//���݂̓G�̐���������
	HP = HP_INIT_VALUE;	//HP������
	IsArive = true;		//�����Ă���
	img->SetIsFade(false);	//�t�F�[�h�A�E�g���Ȃ��B
}

//���̓G��
void Enemy::NextEnemy()
{
	if (NowEnemyNum < ENEMY_MAX)	//���݂̓G���A�G�̍ő吔��菭�Ȃ����
	{
		++NowEnemyNum;				//���̓G��
	}
}

//���݉��̖ڂ̓G���擾
int Enemy::GetNowEnemyNum()
{
	return NowEnemyNum;
}

//�`��
void Enemy::Draw()
{

	//HP�`��
	for (int i = 0; i < HP; ++i)
	{
		if (reverse)	//���]�`�悷��Ƃ�
		{
			hp_img->Draw(HP_X - i * hp_img->GetWidth(), HP_Y);	//���]�`��
		}
		else	//�ʏ�`��̂Ƃ�
		{
			hp_img->Draw(HP_X + i * hp_img->GetWidth(), HP_Y);	//HP�`��
		}
	}

	//�G�`��
	if (IsArive)	//�����Ă����
	{
		img->DrawCenter();		//�����ɕ`��
		if (dmgFlg)	//�_���[�W���󂯂��Ƃ�
		{
			damege->DrawCenter(rect);	//�_���[�W�G�t�F�N�g�`��
		}
	}
	else			//����ł����
	{
		img->SetIsFade(true);	//�t�F�[�h�A�E�g�J�n
		img->DrawCenter();		//�����ɕ`��
	}
}

//�t�F�[�h�A�E�g�I���������擾
bool Enemy::GetFadeEnd()
{
	return img->GetFadeEnd();
}

//�_���[�W�t���O�ݒ�
void Enemy::SetDamegeFlg(bool dmg)
{
	dmgFlg = dmg;
}

//�G�t�F�N�g�I��������
bool Enemy::GetIsEffectEnd()
{
	if (damege->GetIsEffectEnd())	//�G�t�F�N�g�`�悪�I��������
	{
		damege->Reset();			//�G�t�F�N�g���Z�b�g
		dmgFlg = false;				//�_���[�W�t���O���Z�b�g
		return true;				//�G�t�F�N�g�I��
	}
	else	//�I�����Ă��Ȃ����
	{
		return false;	//�I�����Ă��Ȃ�
	}
}
