//SELECT.hpp
//�I�������Ǘ�����N���X

#pragma once

//#################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "IMAGE.hpp"
#include "KEYDOWN.hpp"
#include <vector>

//##################### �}�N����` ######################
#define SELECT_IMG_DIR			R"(.\MY_IMG\Select)"		//�I�����̉摜�f�B���N�g��

#define IMG_NAME_SELECT_SUM			R"(\select_sum.png)"			//�I�����̃_�~�[�摜1
#define IMG_NAME_SELECT_DIFFERENCE	R"(\select_difference.png)"		//�I�����̃_�~�[�摜2
#define IMG_NAME_SELECT_PRODUCT		R"(\select_product.png)"		//�I�����̃_�~�[�摜3
#define IMG_NAME_SELECT_DEALER		R"(\select_dealer.png)"			//�I�����̃_�~�[�摜4
#define IMG_NAME_SELECT_SUM_DIFF	R"(\select_sum_diff.png)"		//�I�����̃_�~�[�摜5
#define IMG_NAME_SELECT_PRO_DEA		R"(\select_pro_dea.png)"		//�I�����̃_�~�[�摜6

#define IMG_NAME_STAGE_DAMMY01	R"(\stage_dammy01.png)"		//�X�e�[�W�I�����̃_�~�[�摜1
#define IMG_NAME_STAGE_DAMMY02	R"(\stage_dammy02.png)"		//�X�e�[�W�I�����̃_�~�[�摜2
#define IMG_NAME_STAGE_DAMMY03	R"(\stage_dammy03.png)"		//�X�e�[�W�I�����̃_�~�[�摜3

#define SELECT_LEVEL_DRAW_X		20	//��Փx�̑I�����̕`��J�nX�ʒu
#define SELECT_LEVEL_DRAW_Y		20	//��Փx�̑I�����̕`��J�nY�ʒu
#define SELECT_STAGE_DRAW_X		50	//�X�e�[�W�̑I�����̕`��J�nX�ʒu
#define SELECT_STAGE_DRAW_Y		20	//�X�e�[�W�̑I�����̕`��J�nY�ʒu

#define SELECT_INTERVAL		20		//�I�����̊Ԋu

#define CHOISE_NONE	-1				//�I�����Ă��Ȃ����

//##################### �񋓌^ #######################

//##################### �N���X��` ######################
class SELECT
{

private:

	IMAGE* SelectImage;							//�I�����̉摜

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

	SELECT(const char *,const char *,int);		//�R���X�g���N�^
	~SELECT();									//�f�X�g���N�^

	bool GetIsCreateSelect();					//�I��������ꂽ���擾
	bool GetIsChoise();							//�I���������擾
	bool GetChoiseSelectCode();					//�I�񂾑I�����̃R�[�h�ԍ�

	void SetInit(int,int,int);					//�����ݒ�
	void Init();								//������

	bool Add(const char*, const char*,int);		//�I������ǉ�

	void Draw();								//�I������`��

	void Operation(KEYDOWN*);					//�L�[����
	void Next();								//���̑I������
	void Next(int);								//�w�肳�ꂽ�����A���̑I������
	void Prev();								//�O�̑I������
	void Prev(int);								//�w�肳�ꂽ�����A�O�̑I������

};
