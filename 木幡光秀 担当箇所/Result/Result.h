#pragma once

/**
 * @file   Result.h
 * @brief  �����L���O��\������N���X
 * @author Mitsuhide Kowata
 * @date �@2021/01/21
 */

#include "../SCENEMANAGER/BaseScreen.h"
#include "../../C_UI/CUI.h"

class C_RESULT : public BaseScene
{
public:

	C_RESULT() {};
	virtual ~C_RESULT() {};

	virtual void Initialize()  override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };
	virtual void Draw2D()      override;
	virtual void DrawAlpha3D() override { return; };

private:
	SPRITE sprite;
	SPRITE result;
	SPRITE _1st, _2nd, _3rd;
	FONT font;

	void Add_Sprite(LPCTSTR _sprite_name);
	void Ranking();
	std::vector<SPRITE> sprite_list_name;


	/**
�@�@* @enum Rank
�@�@* �����L���O�W�v�p
�@�@*/
	enum Rank{FIRST,SECOND,THIRD,NUM};

	/**
�@�@* @enum FontSize
�@�@* �t�H���g�T�C�Y
�@�@*/
	enum FontSize { FONT_SIZE = 150 };

	/**
�@�@* @enum RankPos
�@�@* ���ʉ摜�̍��W
�@�@*/
	enum RankPos {
		RANK_POS_X = 200,
		RANK_POS_Y = 200,
		RANK_POS_Z = -1
	};

	/**
�@�@* @enum FontPos
�@�@* �X�R�A�\�����W
�@�@*/
	enum FontPos {
		FONT_POS_X = 600,
		FONT_POS_Y = 200
	};

	/**
�@�@* @enum ScoreCalculate
�@�@* �X�R�A�\�����W�v�Z�p
�@�@*/
	enum ScoreCalculate {
		SCORE_FIRST  = 0,
		SCORE_SECOND = 150,
		SCORE_THIRD  = 300
	};

	const Vector3 result_pos = Vector3(0, 0, -1);

	Vector3 rank_pos = Vector3(RANK_POS_X, RANK_POS_Y, RANK_POS_Z);
	Vector2 font_pos = Vector2(FONT_POS_X, FONT_POS_Y);

	int ranking_score[NUM]; 
	CUI cui;
};