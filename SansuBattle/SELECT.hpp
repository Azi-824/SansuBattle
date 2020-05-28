//SELECT.hpp
//�I�������Ǘ�����N���X

#pragma once

//#################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "DxLib.h"
#include "IMAGE.hpp"
#include "KEYDOWN.hpp"
#include <vector>

//##################### �}�N����` ######################
#define SELECT_IMG_DIR			R"(.\MY_IMG\Select)"		//�I�����̉摜�f�B���N�g��

#define IMG_NAME_SELECT_DAMMY1	R"(\dammy01.png)"			//�I�����̃_�~�[�摜1
#define IMG_NAME_SELECT_DAMMY2	R"(\dammy02.png)"			//�I�����̃_�~�[�摜2
#define IMG_NAME_SELECT_DAMMY3	R"(\dammy03.png)"			//�I�����̃_�~�[�摜3
#define IMG_NAME_SELECT_DAMMY4	R"(\dammy04.png)"			//�I�����̃_�~�[�摜4
#define IMG_NAME_SELECT_DAMMY5	R"(\dammy05.png)"			//�I�����̃_�~�[�摜5
#define IMG_NAME_SELECT_DAMMY6	R"(\dammy06.png)"			//�I�����̃_�~�[�摜6

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
enum CODE_SELECT_LEVEL
{
	CODE_LEVEL_SUM,					//��Փx�A�a�i�����Z�j
	CODE_LEVEL_DIFFERENCE,			//��Փx�A���i�����Z�j
	CODE_LEVEL_PRODUCT,				//��Փx�A�ρi�|���Z�j
	CODE_LEVEL_DEALER,				//��Փx�A���i����Z�j
	CODE_LEVEL_SUM_DEFFERENCE,		//��Փx�A�a���i�����Z�A�����Z�j
	CODE_LEVEL_PRODUCT_DEALER,		//��Փx�A�Ϗ��i�|���Z�A����Z�j
};

enum CODE_SELECT_STAGE
{
	CODE_STAGE_EASY,		//�ȒP
	CODE_STAGE_NORMAL,		//����
	CODE_STAGE_HARD			//���
};

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
