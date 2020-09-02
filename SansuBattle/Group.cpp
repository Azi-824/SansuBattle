//Group.cpp

//############## �w�b�_�t�@�C���ǂݍ��� ###############
#include "Group.hpp"

//############## �N���X��` #################

//�R���X�g���N�^
/*
�����FButton*�F�O���[�v�ɒǉ�����{�^��
�����Fint�Fx�ʒu
�����Fint�Fy�ʒu
�����Fint�F���̊Ԋu
�����Fint�F�c�̊Ԋu
*/
Group::Group(Button* bt,int x, int y, int side,int vertical)
{
	//�����o�[������
	Area = { 0 };			//�̈�
	IsChoise = false;		//�I��������
	PageMax = 0;			//�y�[�W��
	NowPage = PAGE_START;	//���݂̃y�[�W
	DrawX = 0;				//�`��J�nX�ʒu
	DrawY = 0;				//�`��J�nY�ʒu
	RowNum = 0;				//�`��͈͂̒��ŕ`��ł����̐�
	LineNum = 0;			//�`��͈͂̒��ŕ`��ł���s�̐�
	NowRow = 0;				//���݂̗�ԍ�
	NowLine = 0;			//���݂̍s�ԍ�
	Interval_Side = 0;		//�I�����̊Ԋu(��)
	Interval_Vertical = 0;	//�I�����̊Ԋu(�c)
	SelectNum = -1;			//�I�������{�^��

	this->bt.push_back(bt);	//�{�^���ǉ�

	SetInit(x, y, side, vertical);	//�����ݒ�


}

//�R���X�g���N�^
/*
�����Fvector<Button*>�F�O���[�v�ɒǉ�����{�^��
�����Fint�Fx�ʒu
�����Fint�Fy�ʒu
�����Fint�F���̊Ԋu
�����Fint�F�c�̊Ԋu
*/
Group::Group(vector<Button*> bt, int x, int y, int side, int vertical)
{
	//�����o�[������
	Area = { 0 };			//�̈�
	IsChoise = false;		//�I��������
	PageMax = 0;			//�y�[�W��
	NowPage = PAGE_START;	//���݂̃y�[�W
	DrawX = 0;				//�`��J�nX�ʒu
	DrawY = 0;				//�`��J�nY�ʒu
	RowNum = 0;				//�`��͈͂̒��ŕ`��ł����̐�
	LineNum = 0;			//�`��͈͂̒��ŕ`��ł���s�̐�
	NowRow = 0;				//���݂̗�ԍ�
	NowLine = 0;			//���݂̍s�ԍ�
	Interval_Side = 0;		//�I�����̊Ԋu(��)
	Interval_Vertical = 0;	//�I�����̊Ԋu(�c)
	SelectNum = -1;			//�I�������{�^��

	this->bt = bt;			//�{�^���ǉ�
	ElementMax = this->bt.size();	//�v�f���ݒ�

	SetInit(x, y, side, vertical);	//�����ݒ�

}

//�����ݒ�
/*
�����Fint�Fx�ʒu
�����Fint�Fy�ʒu
�����Fint�F���̊Ԋu
�����Fint�F�c�̊Ԋu
*/
void Group::SetInit(int x, int y, int side, int vertical)
{
	DrawX = x;				//�`��J�nX�ʒu�ݒ�
	DrawY = y;				//�`��J�nY�ʒu�ݒ�
	Interval_Side = side;	//�I�����̊Ԋu(��)��ݒ�
	Interval_Vertical = vertical;	//�I�����̊Ԋu(�c)��ݒ�

	SetArea(x, y, GAME_WIDTH, GAME_HEIGHT);	//�̈��ݒ�

	//�`��͈͂̒��ŕ`��ł����̐����v�Z
	while (true)	//�������[�v
	{

		if (x + bt.at(RowNum)->GetWidth() + side <= GAME_WIDTH)	//��ʓ��Ȃ�
		{
			x += bt.at(RowNum)->GetWidth() + side;	//X�̈ʒu�����炷
			++RowNum;	//�J�E���g�A�b�v
		}
		else	//��ʊO�Ȃ�
		{
			break;	//���[�v�I��
		}

		if (RowNum > bt.size() - 1)	//�{�^���̐����A�������I�������
			break;						//���[�v�I��
	}

	//�`��͈͂̒��ŕ`��ł���s�̐����v�Z
	while (true)	//�������[�v
	{		

		if (y + bt.at(LineNum)->GetHeight() + vertical <= GAME_HEIGHT)	//��ʓ��Ȃ�
		{
			y += bt.at(LineNum)->GetHeight() + vertical;	//y�̈ʒu�����炷
			++LineNum;	//�J�E���g�A�b�v
		}
		else	//��ʊO�Ȃ�
		{
			break;	//���[�v�I��
		}

		if (LineNum > bt.size() - 1)	//�{�^���̐����A�������I�������
			break;						//���[�v�I��

	}

	//�I���������ׂĕ`�悷��̂ɁA���y�[�W�K�v���v�Z
	int one_page = RowNum * LineNum;	//1�y�[�W�ɓ���I�����̐�
	do
	{
		++PageMax;	//�y�[�W������
	} while ((one_page * PageMax) < bt.size());
	NowPage = PAGE_START;	//�擪�̃y�[�W�����݂̃y�[�W�ɐݒ�

}

//�f�X�g���N�^
Group::~Group()
{
	for (auto b : bt) { delete b; }
	vector<Button*> v;
	v.swap(bt);
}

//�̈��ݒ�
void Group::SetArea(int x, int y, int width, int height)
{
	Area.left = x;
	Area.top = y;
	Area.right = x + width;
	Area.bottom = y + height;
}

//�{�^���ǉ�
void Group::Add(Button* bt)
{
	this->bt.push_back(bt);	//�{�^���ǉ�
	ElementMax = this->bt.size();	//�v�f���ݒ�
}

//�`��
void Group::Draw()
{
	int NowDrawX = DrawX, NowDrawY = DrawY;		//���݂̕`��ʒu
	int row_cnt = 0;							//�񐔂̃J�E���g
	int line_cnt = 0;							//�s���̃J�E���g
	int now_page = 0;							//�y�[�W�J�E���g

	for (auto b : bt)
	{
		if (row_cnt >= RowNum)		//�񐔂��A�`��ł���͈͂𒴂�����
		{
			NowDrawX = DrawX + GAME_WIDTH * now_page;			//X�̕`��ʒu���ŏ��̈ʒu��
			NowDrawY += b->GetHeight() + Interval_Vertical;		//Y�̕`��ʒu���A�摜�̍����{�Ԋu�����ւ��炷
			++line_cnt;											//�J�E���g�A�b�v
			row_cnt = 0;										//�J�E���g���Z�b�g
		}

		if (line_cnt >= LineNum)	//�s�����A�`��ł���͈͂𒴂�����
		{
			NowDrawX = DrawX + GAME_WIDTH;		//X�̈ʒu��1��ʕ����炵���ʒu��
			NowDrawY = DrawY;					//Y�̈ʒu���ŏ��̈ʒu��
			++now_page;							//�J�E���g�A�b�v
			line_cnt = 0;						//�J�E���g���Z�b�g
		}

		++row_cnt;	//�J�E���g�A�b�v

		b->Draw(NowDrawX,NowDrawY);	//�`��

		NowDrawX += b->GetWidth() + Interval_Side;	//�`��ʒu�����炷
	}
}

//�N���b�N���ꂽ���̏���
void Group::Clik()
{
	for (int i = 0; i < bt.size(); ++i)	//�{�^���̐�
	{
		if (bt.at(i)->OnClick())	//�{�^���������ꂽ�Ƃ�
		{
			SelectNum = i;	//�I�������{�^����ۑ�
			return;			//�����I��
		}
	}
}

//�I���������ǂ����擾
/*
�߂�l�Fbool�Ftrue �I�������F false �I�����Ă��Ȃ�
*/
bool Group::GetIsSelect()
{
	return SelectNum != CHOISE_NONE;
}

//�I�������{�^���̗v�f�ԍ����擾
/*
�߂�l�Fint�F�I�������{�^���̗v�f�ԍ����擾
*/
int Group::GetSelctNum()
{
	return SelectNum;
}

//���̃y�[�W�֍s���邩�m�F
bool Group::CheckIsNextPage()
{
	//���݂̃y�[�W���A�y�[�W�̍ő吔���O��������true
	return NowPage < PageMax;

}

//�O�̃y�[�W�֍s���邩�m�F
bool Group::CheckIsPrevPage()
{
	//���݂̃y�[�W���A�ŏ��̃y�[�W���ゾ������true
	return NowPage > PAGE_START;
}

//���̃y�[�W��
void Group::NextPage()
{
	++NowPage;				//���̃y�[�W��
	DrawX -= GAME_WIDTH;	//�`��ʒu��1�y�[�W�����炷
}

//�O�̃y�[�W��
void Group::PrevPage()
{
	--NowPage;				//�O�̃y�[�W��
	DrawX += GAME_WIDTH;	//�`��ʒu����1�y�[�W�����炷
}