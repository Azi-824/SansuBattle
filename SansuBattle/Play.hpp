//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"

//############### �}�N����` #################
#define GAME_LIMIT_DRAW_X	680		//�Q�[���̐������ԕ`��X�ʒu
#define GAME_LIMIT_DRAW_Y	10		//�Q�[���̐������ԕ`��Y�ʒu
#define GAME_LIMIT_TIME		60		//�Q�[���̐�������

using std::vector;

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

public:

	Play();		//�R���X�g���N�^
	~Play();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void Run() override;	//�v���C��ʂ̏���

};