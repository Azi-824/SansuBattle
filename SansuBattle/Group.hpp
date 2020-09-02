//Group.hpp
//�����̃{�^���Ȃǂ��A��̃O���[�v�Ƃ��Ĉ������߂̃N���X

#pragma once

//################ �w�b�_�t�@�C���ǂݍ��� #################
#include "Global.hpp"
#include "Button.hpp"

//################ �}�N����` ###################
#define CHOISE_NONE	-1				//�I�����Ă��Ȃ����

#define PAGE_START	1				//�擪�̃y�[�W

using std::vector;

//################ �N���X��` ###################
class Group
{
private:

	int ElementMax;		//�v�f��
	RECT Area;			//�̈�
	vector<Button*> bt;	//�{�^��

	bool IsChoise;								//�I��������
	bool IsBack;								//�߂邩
	int SelectNum;								//�I�������{�^��

	int PageMax;								//�y�[�W��
	int NowPage;								//���݂̃y�[�W

	int DrawX;									//�`��J�nX�ʒu
	int DrawY;									//�`��J�nY�ʒu
	int RowNum;									//�`��͈͂̒��ŕ`��ł����̐�
	int LineNum;								//�`��͈͂̒��ŕ`��ł���s�̐�
	int NowRow;									//���݂̗�ԍ�
	int NowLine;								//���݂̍s�ԍ�
	int Interval_Side;							//�I�����̊Ԋu(��)
	int Interval_Vertical;						//�I�����̊Ԋu(�c)

	void SetInit(int, int, int, int);			//�����ݒ�

	//bool CheckIsNextPage();						//���̃y�[�W�֍s���邩�m�F
	//bool CheckIsPrevPage();						//�O�̃y�[�W�֍s���邩�m�F
	//void NextPage();							//���̃y�[�W��
	//void PrevPage();							//�O�̃y�[�W��

public:

	Group(Button*, int, int, int, int);			//�R���X�g���N�^
	Group(vector<Button*>, int, int, int, int);	//�R���X�g���N�^
	~Group();				//�f�X�g���N�^

	void SetArea(int, int, int, int);	//�̈�ݒ�
	void Add(Button*);		//�ǉ�
	void Draw();			//�`��
	void Clik();			//�N���b�N�����Ƃ��̏���

	bool GetIsSelect();		//�I��������
	int GetSelctNum();		//�I�������{�^�����擾

};
