//Select.hpp
//�I�������Ǘ�����N���X

#pragma once

//#################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "Image.hpp"
#include "KeyDown.hpp"
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

#define SELECT_GAMEMODE_DRAW_X		20	//�Q�[�����[�h�̑I�����̕`��J�nX�ʒu
#define SELECT_GAMEMODE_DRAW_Y		20	//�Q�[�����[�h�̑I�����̕`��J�nY�ʒu
#define SELECT_LEVEL_DRAW_X		0		//���x���̑I�����̕`��J�nX�ʒu
#define SELECT_LEVEL_DRAW_Y		250		//���x���̑I�����̕`��J�nY�ʒu

#define SELECT_INTERVAL		10		//�I�����̊Ԋu

#define CHOISE_NONE	-1				//�I�����Ă��Ȃ����

//##################### �񋓌^ #######################

//##################### �N���X��` ######################
class Select
{

private:

	Image* SelectImage;							//�I�����̉摜

	std::vector<int> SelectCode;				//�I�����̃R�[�h�ԍ�
	std::vector<int>::iterator NowSelectCode;	//���ݑI��ł���R�[�h�ԍ�

	int Choise_SelectCode;						//�I�񂾑I�����̃R�[�h�ԍ�

	bool IsCreateSelect;						//�I��������ꂽ��
	bool IsChoise;								//�I��������

	int DrawX;									//�`��J�nX�ʒu
	int DrawY;									//�`��J�nY�ʒu
	int DrawWidth_Range;						//�`�敝�͈̔�
	int RowNum;									//�`��͈͂̒��ŕ`��ł����̐�

public:

	Select(const char *,const char *,int);		//�R���X�g���N�^
	~Select();									//�f�X�g���N�^

	bool GetIsCreateSelect();					//�I��������ꂽ���擾
	bool GetIsChoise();							//�I���������擾
	bool GetChoiseSelectCode();					//�I�񂾑I�����̃R�[�h�ԍ�

	void SetInit(int,int,int);					//�����ݒ�
	void Init();								//������

	bool Add(const char*, const char*,int);		//�I������ǉ�

	void Draw();								//�I������`��

	void Operation(KeyDown*);					//�L�[����
	void Next();								//���̑I������
	void Next(int);								//�w�肳�ꂽ�����A���̑I������
	void Prev();								//�O�̑I������
	void Prev(int);								//�w�肳�ꂽ�����A�O�̑I������

};
