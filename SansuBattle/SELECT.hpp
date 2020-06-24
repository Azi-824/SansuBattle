//Select.hpp
//�I�������Ǘ�����N���X

#pragma once

//#################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "Image.hpp"
#include "KeyDown.hpp"
#include "Music.hpp"
#include <vector>

//##################### �}�N����` ######################
#define SELECT_IMG_DIR			R"(.\MY_IMG\Select)"		//�I�����̉摜�f�B���N�g��

#define IMG_NAME_SELECT_SUM			R"(\select_sum.png)"			//�Q�[�����[�h�I�����i�����Z�j�̉摜
#define IMG_NAME_SELECT_DIFFERENCE	R"(\select_difference.png)"		//�Q�[�����[�h�I�����i�����Z�j�̉摜
#define IMG_NAME_SELECT_PRODUCT		R"(\select_product.png)"		//�Q�[�����[�h�I�����i�|���Z�j�̉摜
#define IMG_NAME_SELECT_DEALER		R"(\select_dealer.png)"			//�Q�[�����[�h�I�����i����Z�j�̉摜
#define IMG_NAME_SELECT_SUM_DIFF	R"(\select_sum_diff.png)"		//�Q�[�����[�h�I�����i�����Z�A�����Z�j�̉摜
#define IMG_NAME_SELECT_PRO_DEA		R"(\select_pro_dea.png)"		//�Q�[�����[�h�I�����i�|���Z�A����Z�j�̉摜

#define IMG_NAME_SELECTLEVEL_EASY	R"(\select_level_easy.png)"		//���x���I�����i�ȒP�j�̉摜
#define IMG_NAME_SELECTLEVEL_NORMAL	R"(\select_level_normal.png)"	//���x���I�����i���ʁj�̉摜
#define IMG_NAME_SELECTLEVEL_HARD	R"(\select_level_hard.png)"		//���x���I�����i����j�̉摜

#define SELECT_GAMEMODE_DRAW_X		40	//�Q�[�����[�h�̑I�����̕`��J�nX�ʒu
#define SELECT_GAMEMODE_DRAW_Y		50	//�Q�[�����[�h�̑I�����̕`��J�nY�ʒu
#define SELECT_LEVEL_DRAW_X		0		//���x���̑I�����̕`��J�nX�ʒu
#define SELECT_LEVEL_DRAW_Y		250		//���x���̑I�����̕`��J�nY�ʒu

#define SELECT_GAMEMODE_INTERVAL_SIDE		30		//�Q�[�����[�h�I�����̊Ԋu(��)
#define SELECT_GAMEMODE_INTERVAL_VERTICAL	120		//�Q�[�����[�h�I�����̊Ԋu(�c)
#define SELECT_LEVEL_INTERVAL_SIDE			10		//���x���I�����̊Ԋu(�c)

#define RECT_EXPANSION_VALUE	20	//�̈�̊g���
#define RECT_TOUKA_VALUE		0.4	//�̈�̓��ߗ�

#define CHOISE_NONE	-1				//�I�����Ă��Ȃ����

//##################### �񋓌^ #######################

using std::vector;

//##################### �N���X��` ######################
class Select
{

private:

	vector<Image*> SelectImage;					//�I�����̉摜
	RECT rect;									//�I�����̗̈�
	static vector<Music*> Key_se;				//�L�[�{�[�h����̎��̌��ʉ�

	vector<int> SelectCode;						//�I�����̃R�[�h�ԍ�
	vector<int>::iterator NowSelectCode;		//���ݑI��ł���R�[�h�ԍ�

	int Choise_SelectCode;						//�I�񂾑I�����̃R�[�h�ԍ�

	bool IsChoise;								//�I��������

	int DrawX;									//�`��J�nX�ʒu
	int DrawY;									//�`��J�nY�ʒu
	int DrawWidth_Range;						//�`�敝�͈̔�
	int RowNum;									//�`��͈͂̒��ŕ`��ł����̐�
	int Interval_Side;							//�I�����̊Ԋu(��)
	int Interval_Vertical;						//�I�����̊Ԋu(�c)

	void Next();								//���̑I������
	void Next(int);								//�w�肳�ꂽ�����A���̑I������
	void Prev();								//�O�̑I������
	void Prev(int);								//�w�肳�ꂽ�����A�O�̑I������

public:

	Select(vector<Image*>);						//�R���X�g���N�^
	~Select();									//�f�X�g���N�^

	bool GetIsChoise();							//�I���������擾
	int GetChoiseSelectCode();					//�I�񂾑I�����̃R�[�h�ԍ�

	void SetInit(int,int,int,int,int interval_vertical = 0);	//�����ݒ�
	void Init();								//������

	void Add(Image*);							//�I������ǉ�

	void Draw();								//�I������`��

	void Operation(KeyDown*);					//�L�[����

};
