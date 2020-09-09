//Scene.cpp

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Scene.hpp"

//############## �N���X��` ################

int Scene::NowScene = 0;	//���݂̃V�[��
bool Scene::GameEnd = false;//�Q�[���G���h�t���O
vector<Font*> Scene::font;	//�t�H���g
vector<Data*> Scene::data;	//�f�[�^
int Scene::GameLevel = -1;	//�Q�[�����x��
int Scene::GameMode = -1;	//�Q�[�����[�h

//�R���X�g���N�^
Scene::Scene()
{
	back = new Image();			//�C���X�^���X����
	bgm.push_back(new Music());	//�C���X�^���X����

	//�t�H���g�֌W
	if (font.empty())	//�t�H���g���쐬���Ă��Ȃ�������
	{
		font.push_back(new Font(FNAME_KOKUBAN, F_SIZE_NORMAL, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));	//�����΂�t�H���g�i�ʏ�T�C�Y�j�쐬
		font.push_back(new Font(FNAME_KOKUBAN, F_SIZE_MINI, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));		//�����΂�t�H���g�i�~�j�T�C�Y�j�쐬
		font.push_back(new Font(FNAME_KOKUBAN, F_SIZE_RANKING, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));	//�����΂�t�H���g�i�����L���O�T�C�Y�j�쐬
		font.push_back(new Font(FNAME_POP, F_SIZE_NORMAL, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));		//�|�b�v�t�H���g�i�ʏ�T�C�Y�j�쐬
		for (auto f : font)
		{
			if (!f->GetIsCreate()) { IsLoad = false; return; }	//�ǂݍ��ݎ��s
		}
	}

	start = false;		//Start�������s������

	IsLoad = false;		//�ǂݍ��߂���
}

//�f�X�g���N�^
Scene::~Scene()
{
	delete back;	//back�j��
	
	for (auto b : bgm) { delete b; }	//bgm�j��
	vector<Music*> v;
	v.swap(bgm);

	Font::ReleaseFont();	//�ǂݍ��񂾃t�H���g���J��
}

//�V�[�����ς�邲�Ƃ�1�񂾂��s������
void Scene::Start()
{

}

//���݂̃V�[�����擾
int Scene::GetNowScene()
{
	return NowScene;
}

//�Q�[���G���h�t���O���擾
bool Scene::IsGameEnd()
{
	return GameEnd;
}

//�t�F�[�h�A�E�g����
bool Scene::FadeOut()
{
	//�t�F�[�h�A�E�g����
	static int cnt = 0;	//�J�E���g�p

	//60�t���[�����A�҂�
	if (cnt < FADE_MAX_CNT)
	{
		++cnt;	//�J�E���g�A�b�v
	}
	else	//60�t���[���o�߂�����
	{
		cnt = 0;		//�J�E���g���Z�b�g
		return true;	//�t�F�[�h�A�E�g�I��
	}

	//�t�F�[�h�A�E�g�̏���
	double ToukaPercent = cnt / (double)FADE_MAX_CNT;							//����%���v�Z
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);		//���߂�����
	DrawBox(GAME_LEFT, GAME_TOP, GAME_WIDTH, GAME_HEIGHT, COLOR_BLACK, true);	//�����l�p��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//���߂���߂�

	return false;	//�t�F�[�h�A�E�g��

}
