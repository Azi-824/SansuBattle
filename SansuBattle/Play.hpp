//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Question.hpp"
#include "Time.hpp"

//############### �}�N����` #################
#define LIMIT_DRAW_X	740		//�Q�[���̐������ԕ`��X�ʒu
#define LIMIT_DRAW_Y	10		//�Q�[���̐������ԕ`��Y�ʒu
#define LIMIT_TIME		30		//�Q�[���̐�������
#define MISS_MINUS_TIME	5		//�ԈႦ���Ƃ��̌��鎞��

using std::vector;

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

	Player* player;				//�v���C���[
	vector<Enemy*> enemy;		//�G
	vector<Question*> quesiton;	//���
	Time* limit;				//��������

public:

	Play();						//�R���X�g���N�^
	~Play();					//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void Run() override;		//�v���C��ʂ̏���

};
