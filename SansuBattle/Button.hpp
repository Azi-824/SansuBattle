//Button.hpp
//�{�^���̃N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ####################
#include "Global.hpp"
#include "Image.hpp"
#include "Music.hpp"

//################# �}�N����` ################
#define BT_IMG_DIR				R"(.\Image\Button)"	//�{�^���̉摜�̃f�B���N�g��

#define BT_START_IMG_NAME		R"(\start.png)"				//�{�^���̉摜(start)
#define BT_END_IMG_NAME			R"(\end.png)"				//�{�^���̉摜(end)

#define BT_SUM_IMG_NAME			R"(\mode_sum.png)"			//�{�^���̉摜(+)
#define BT_DIF_IMG_NAME			R"(\mode_difference.png)"	//�{�^���̉摜(-)
#define BT_PRO_IMG_NAME			R"(\mode_product.png)"		//�{�^���̉摜(*)
#define BT_DEA_IMG_NAME			R"(\mode_dealer.png)"		//�{�^���̉摜(/)
#define BT_SUM_DIF_IMG_NAME		R"(\mode_sum_diff.png)"		//�{�^���̉摜(+-)
#define BT_PRO_DEA_IMG_NAME		R"(\mode_pro_dea.png)"		//�{�^���̉摜(*/)
#define BT_SUM_PRO_IMG_NAME		R"(\mode_sum_pro.png)"		//�{�^���̉摜(+*)
#define BT_SUM_DEA_IMG_NAME		R"(\mode_sum_dea.png)"		//�{�^���̉摜(+/)
#define BT_DIF_PRO_IMG_NAME		R"(\mode_dif_pro.png)"		//�{�^���̉摜(-*)
#define BT_SUM_DIF_PRO_IMG_NAME	R"(\mode_sum_dif_pro.png)"	//�{�^���̉摜�i+-*�j
#define BT_SUM_DIF_DEA_IMG_NAME	R"(\mode_sum_dif_dea.png)"	//�{�^���̉摜�i+-/�j
#define BT_ALL_IMG_NAME			R"(\mode_all.png)"			//�{�^���̉摜�i�l�����Z�j

#define BT_EASY_IMG_NAME		R"(\level_easy.png)"		//�{�^���̉摜(�ȒP)
#define BT_NORMAL_IMG_NAME		R"(\level_normal.png)"		//�{�^���̉摜(����)
#define BT_HARD_IMG_NAME		R"(\level_hard.png)"		//�{�^���̉摜(���)


#define IMG_NAME_ARROW_RIGHT	R"(\Arrow_Right.png)"		//���i�E�j�̉摜
#define IMG_NAME_ARROW_LEFT		R"(\Arrow_Left.png)"		//���i���j�̉摜

#define BT_START_X	150		//�X�^�[�g�{�^��X�ʒu
#define BT_START_Y	500		//�X�^�[�g�{�^��Y�ʒu
#define BT_END_X	500		//�X�^�[�g�{�^��X�ʒu
#define BT_END_Y	500		//�X�^�[�g�{�^��Y�ʒu

#define BT_MODE_DRAW_X		40	//�Q�[�����[�h�̑I�����̕`��J�nX�ʒu
#define BT_MODE_DRAW_Y		40	//�Q�[�����[�h�̑I�����̕`��J�nY�ʒu
#define BT_LEVEL_DRAW_X		0	//���x���̑I�����̕`��J�nX�ʒu
#define BT_LEVEL_DRAW_Y		250	//���x���̑I�����̕`��J�nY�ʒu

#define BT_MODE_INTERVAL_SIDE		30		//�Q�[�����[�h�I�����̊Ԋu(��)
#define BT_MODE_INTERVAL_VERTICAL	100		//�Q�[�����[�h�I�����̊Ԋu(�c)
#define BT_LEVEL_INTERVAL_SIDE		10		//���x���I�����̊Ԋu(�c)
#define BT_LEVEL_INTERVAL_VERTICAL	0		//���x���I�����̊Ԋu(��)
#define BT_START_INTERVAL_SIDE		80		//�X�^�[�g�̑I�����̊Ԋu�i���j

#define RECT_EXPANSION_VALUE	20	//�̈�̊g���
#define RECT_TOUKA_VALUE		0.8	//�̈�̓��ߗ�

#define CHOISE_NONE	-1				//�I�����Ă��Ȃ����

#define PAGE_START	1				//�擪�̃y�[�W


//################# �񋓌^ #################
enum BT_TYPE
{
	BT_START,		//�X�^�[�g
	BT_END			//�G���h
};

//################# �N���X��` ################
class Button
{
private:

	Image* img;	//�摜
	RECT rect;	//�̈�
	static Music* se;	//���ʉ�

	int Element;			//�v�f�ԍ�
	static int ElementCnt;	//�v�f��

public:

	Button(Image*);	//�R���X�g���N�^
	~Button();		//�f�X�g���N�^

	void SetInit(int,int);	//�����ݒ�

	void UpDate();	//�X�V����

	bool OnClick();	//�N���b�N���ꂽ��
	void Draw();	//�`��
	void Draw(int, int);//�`��i�ʒu�w��j
	int GetElement();	//�v�f�ԍ��擾
	int GetWidth();		//�����擾
	int GetHeight();	//�����擾
	void SetRect(int,int);//�̈��ݒ�
	
	template <typename F>
	void Event(F func)	//�N���b�N���ꂽ���̃C�x���g
	{
		func();
	}

};
