#include "C_MAP.h"

/**
 * @fn �@�@�w�i���f���̏����ʒu
 * @brief�@AddParametor�֐��Ŕw�i���f���̏������W�̐ݒ�
 * @return �Ȃ�
 */
void C_MAP::Init()
{
	AddModelParametor(_T("model3D//������//road_8.X"),       ROAD_INTERVAL, road_init_pos);
	AddModelParametor(_T("model3D//��//kari.X"),           PILLAR_INTERVAL, pillar_init_pos);
	AddModelParametor(_T("model3D//bill_side//pro_set.X"),   BILL_INTERVAL, bill_init_pos);

	_iplayer_data.reset(new IPlayerData);
};

void C_MAP:: Update()
{
	//!�v���C���[�̏��擾
	Vector3 player_position = _iplayer_data->GetPlayerPosition("player");

	for (int y = 0; y < model_position.size(); ++y) 
	{
		Vector3 position = *model_position[y].begin();
		int remove_position = REMOVE_POS;

		//!�v���C���[��Z���W��菬�����Ȃ����ꍇ�A
		//!�z��̈�ԑO�̏ꏊ���폜���A�z��̈�Ԍ��ɒǉ�����B
		if (position.z + remove_position <= player_position.z)
		{
			model_position[y].erase(model_position[y].begin());
			model_position[y].push_back(Vector3(position.x, position.y, (model_position[y].back().z + model_scene[y])));
		}
	}

	return;
};

void C_MAP::Draw3D()
{
	for (int y = 0; y < model_position.size(); ++y) 
	{
		for (int x = 0; x < model_position[y].size(); ++x)
		{
			model[y]->SetPosition(model_position[y][x]);
			model[y]->Draw();
		}
	}

	return;
};

/**
 * @fn    �w�i���f���̏������W�v�Z
 * @brief
 * @param (LPCTSTR _filename) �w�i���f����
 * @param (int scene)�@�@�@�@ ���f���̕`�悷��Ԋu
 * @param (Vector3 position)�@���f���̈�ԍŏ��̗v�f�̏������W
 * @return �Ȃ�
 * @detail 
 */
void C_MAP::AddModelParametor(LPCTSTR _filename, int scene, Vector3 position)
{
	Material mtrl;
	mtrl.Emissive = Color(Vector3_One);

	model.push_back(GraphicsDevice.CreateModelFromFile(_filename)); //!���f���̍쐬
	model[model.size() - 1]->SetScale(transform.scale);             //!�X�P�[���̐ݒ�
	model[model.size() - 1]->SetMaterial(mtrl);                     //!�}�e���A���̐ݒ�
	model_scene.push_back(scene);                                   //!���f�����m�̊Ԋu�̐ݒ�
	model_position.resize(model.size());                            //!���f�����̔z��̊m��
	
	int model_size = MODEL_SIZE;

	//!���f���̏������W��ݒ肷��
	for (int i = 0; i < model_size; i++)
	{
		model_position[model.size() - 1].push_back(position + Vector3(0.0f,0.0f,-5 + (i * scene)));
	}
}