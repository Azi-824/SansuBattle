//Global.hpp
//�����̃\�[�X�Ŏg�p��������`�Ȃǂ��܂Ƃ߂��w�b�_�[�t�@�C��

#pragma once

//################## �w�b�_�t�@�C���ǂݍ��� ##################
#include "DxLib.h"

//################## �}�N����` ######################
#define GAME_LEFT	  0		//��ʂ̉��̎n�_
#define GAME_TOP	  0		//��ʂ̏c�̎n�_
#define GAME_WIDTH	880		//��ʂ̉��̑傫��
#define GAME_HEIGHT	640		//��ʂ̏c�̑傫��
#define GAME_FPS_SPEED					   60

//�F�֌W
#define COLOR_RED	GetColor(255,0,0)		//�ԐF
#define COLOR_GREEN	GetColor(0,255,0)		//�ΐF
#define COLOR_BLUE	GetColor(0,0,255)		//�F
#define COLOR_WHITE GetColor(255,255,255)	//���F
#define COLOR_BLACK GetColor(0,0,0)			//���F

//****************** ���̑� ***********************
#define INIT_VALUE		0	//�����l
#define FADE_MAX_CNT	60	//�t�F�[�h�����̃J�E���g�ő�l
#define TOUKA_MAX_VALUE	255	//���߂̍ő�l

//##################### �}�N����` #####################
enum Q_LEVEL_KIND
{
	Q_LEVEL_SUM,				//��Փx�A�a�i�����Z�j
	Q_LEVEL_DIFFERENCE,			//��Փx�A���i�����Z�j
	Q_LEVEL_PRODUCT,			//��Փx�A�ρi�|���Z�j
	Q_LEVEL_DEALER,				//��Փx�A���i����Z�j
	Q_LEVEL_SUM_DIFFERENCE,		//��Փx�A�a���i�����Z�A�����Z�j
	Q_LEVEL_PRODUCT_DEALER		//��Փx�A�Ϗ��i�|���Z�A����Z�j
};	//���̃��x��

enum STAGE_LEVEL
{
	STAGE_LEVEL_EASY,		//�ȒP
	STAGE_LEVEL_NORMAL,		//����
	STAGE_LEVEL_HARD		//���
};	//�X�e�[�W�̃��x��

