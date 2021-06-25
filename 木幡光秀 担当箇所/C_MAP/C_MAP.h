#pragma once

/**
 * @file   Result.h
 * @brief  �w�i�̃��f�����Z�b�g���w�i��`�悷��N���X
 * @author Mitsuhide Kowata
 * @date �@2020/10/15
 */

#include "../C_OBJECT/Object.h"
#include "../../ESGLib.h"
#include "../CPLAYERDATA/CPlayerData.h"

class C_MAP : public Object
{
public:

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override { return; }

private:

	void AddModelParametor(LPCTSTR _filename, int scene, Vector3 position);

	std::vector<MODEL> model;
	std::vector<std::vector<Vector3>> model_position;
	std::vector<int>                  model_scene;

	MEDIA bg;
	MUSIC bgm;
	const Vector3 road_init_pos   = Vector3(0.0f, -0.25f, 0.0f);
	const Vector3 bill_init_pos   = Vector3(0.0f,  -8.0f, 0.0f);
	const Vector3 pillar_init_pos = Vector3_Zero;

	//!�v���C���[�̃f�[�^�x�[�X
	std::unique_ptr<IPlayerData>   _iplayer_data;

	/**
    * @enum Interval
    * ���f���̕`��Ԋu
    */
	enum Interval {
		//!���H�̕`��Ԋu
		ROAD_INTERVAL   = 17,
		//!���̕`��Ԋu
		PILLAR_INTERVAL = 23,
		//!�����̕`��Ԋu
		BILL_INTERVAL   = 60
	};


	/**
�@�@* @enum Models
�@�@* ���f���̌���폜������W�̎w��
�@�@*/
	enum Models {
		//!�\�����郂�f���̌�
		MODEL_SIZE = 8,
		//!���f�����폜����|�W�V����
		REMOVE_POS = 20
	};
protected:

};