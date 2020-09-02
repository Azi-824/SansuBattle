//Button.cpp
//�{�^���̃N���X

//############### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Button.hpp"

//############### �N���X��` ###############

int Button::ElementCnt = 0;	//�v�f��
Music* Button::se;			//���ʉ�

//�R���X�g���N�^
Button::Button(Image* img)
{
	this->img = img;
	rect = { 0 };	//�̈揉����
	Element = ElementCnt++;	//�v�f�ԍ��ݒ�
	if (se == NULL)	//���ʉ�����Ȃ�
	{
		se = new Music(MUSIC_DIR_SE, SE_NAME_KETTEI);	//���ʉ��ǉ�
	}
}

//�f�X�g���N�^
Button::~Button()
{
	delete img;	//img�j��
	delete se;	//se�j��
}

//�����ݒ�
void Button::SetInit(int x,int y)
{
	img->SetInit();	//�摜�����ݒ�
	SetRect(x, y);	//�̈�ݒ�
	se->SetInit(DX_PLAYTYPE_BACK, 60);	//���ʉ�

}

//�����ݒ�
void Button::SetInit()
{
	img->SetInit();	//�摜�����ݒ�
	se->SetInit(DX_PLAYTYPE_BACK, 60);	//���ʉ�
}

//�{�^�����N���b�N���ꂽ��
bool Button::OnClick()
{
	se->Reset();	//�Đ���ԃ��Z�b�g
	bool click = Mouse::OnLeftClick(rect);
	if (click)	//�N���b�N���ꂽ��
		se->PlayOne();	//���ʉ��Đ�

	return click;
}

//�`��
void Button::Draw()
{
	//�}�E�X���{�^���̗̈�̒��ɂ��邩
	if (Mouse::HoverRect(rect))	//�̈���̎�
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, RECT_TOUKA_VALUE * TOUKA_MAX_VALUE);	//���߂�����
		DrawBox(rect.left, rect.top, rect.right, rect.bottom, COLOR_GRAY, TRUE);	//�����l�p�`��`��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//���߂���߂�
	}
	img->Draw(rect.left, rect.top);
}

//�`��i�ʒu�w��j
void Button::Draw(int x, int y)
{
	SetRect(x, y);	//�̈�Đݒ�
	//�}�E�X���{�^���̗̈�̒��ɂ��邩
	if (Mouse::HoverRect(rect))	//�̈���̎�
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, RECT_TOUKA_VALUE * TOUKA_MAX_VALUE);	//���߂�����
		DrawBox(x, y, x + img->GetWidth(), y + img->GetHeight(), COLOR_GRAY, TRUE);	//�����l�p�`��`��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//���߂���߂�
	}
	img->Draw(x,y);
}

//�v�f�ԍ��擾
int Button::GetElement()
{
	return Element;
}

//�����擾
int Button::GetWidth()
{
	return img->GetWidth();
}

//�����擾
int Button::GetHeight()
{
	return img->GetHeight();
}

//�̈��ݒ�
void Button::SetRect(int x, int y)
{
	rect.left = x;
	rect.top = y;
	rect.right = x + img->GetWidth();
	rect.bottom = y + img->GetHeight();
}
