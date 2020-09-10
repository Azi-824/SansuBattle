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
#define LIMIT_DRAW_Y	20		//�Q�[���̐������ԕ`��Y�ʒu
#define LIMIT_TIME		30		//�Q�[���̐�������
#define MISS_MINUS_TIME	5		//�ԈႦ���Ƃ��̌��鎞��

#define CIRCLE_X		720		//�~�̕`��X�ʒu
#define CIRCLE_Y		0		//�~�̕`��Y�ʒu
#define SCORE_Y			335		//�X�R�A�̕`��Y�ʒu

#define IMG_UI_DIR			R"(.\Image\Ui)"		//UI�摜�̃f�B���N�g��

#define IMG_CIRCLE_NAME		R"(\circle.png)"	//�~�̉摜�̖��O
#define IMG_KOKUBAN_NAME	 R"(\kokuban.png)"	//���̉摜�̖��O

using std::vector;

//############### �񋓌^ ##################
enum SE_KIND
{
	SE_FALSE,		//�s�����̎��̌��ʉ�
	SE_DAMEGE		//�_���[�W���󂯂��Ƃ��̌��ʉ�
};

enum PHASE_KIND
{
	PHASE_EFFECT,		//�G�t�F�N�g�t�F�[�Y
	PHASE_OPERATION		//����t�F�[�Y
};

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

	Player* player;				//�v���C���[
	vector<Enemy*> enemy;		//�G
	vector<Question*> quesiton;	//���
	Time* limit;				//��������
	vector<Music*> se;			//���ʉ�
	Image* circle;				//�~
	Image* bord;				//����

	bool IsOperation;			//����ł��邩
	int NowPhase;				//���݂̃t�F�[�Y

	void Start() override;		//�V�[�����ς�邲�Ƃ�1�񂾂��s������
	void Battle();				//�o�g���̏���

public:

	Play();						//�R���X�g���N�^
	~Play();					//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void Run() override;		//�v���C��ʂ̏���

};
