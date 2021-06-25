#include "Result.h"
#include "../SCENEMANAGER/SceneManager.h"
#include <algorithm>
#include <fstream>


void C_RESULT::Initialize()
{
	Add_Sprite(_T("SPRITE//resultbackground.png"));
	result = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//result.png"));
	_1st = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//1st.png"));
	_2nd = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//2nd.png"));
	_3rd = GraphicsDevice.CreateSpriteFromFile(_T("SPRITE//3rd.png"));

	AddFontResourceEx(_T("font/digitalism/digitalism.ttf"), FR_PRIVATE, nullptr);
	font = GraphicsDevice.CreateSpriteFont(_T("digitalism"), FONT_SIZE);

	//!�����L���O�t�@�C���ǂݍ���
	std::ifstream infile("score.dat");

	infile >> ranking_score[FIRST] >> ranking_score[SECOND] >> ranking_score[THIRD];

	//!�����L���O����ւ�
	Ranking();

	//!�����L���O�ۑ�
	std::ofstream outfile("score.dat");
	outfile << ranking_score[FIRST] <<" "<< ranking_score[SECOND] << " " << ranking_score[THIRD];

}

void C_RESULT::Update()
{
	if (Input.GetKeybordInput(Keys_Enter)) { SceneManager::ChangeScene(SceneManager::TITLE); }


}

void C_RESULT::Draw2D()
{
	std::for_each(sprite_list_name.begin(), sprite_list_name.end(), [](SPRITE& _sprite) {SpriteBatch.Draw(*_sprite, Vector3_Zero); });
	SpriteBatch.Draw(*result, result_pos);

	SpriteBatch.Draw(*_1st, Vector3(rank_pos.x, rank_pos.y + SCORE_FIRST , rank_pos.z));
	SpriteBatch.Draw(*_2nd, Vector3(rank_pos.x, rank_pos.y + SCORE_SECOND, rank_pos.z));
	SpriteBatch.Draw(*_3rd, Vector3(rank_pos.x, rank_pos.y + SCORE_THIRD , rank_pos.z));

	SpriteBatch.DrawString(font, Vector2(font_pos.x, font_pos.y + SCORE_FIRST), Color(219,180,0), _T("%d"),   ranking_score[FIRST]);
	SpriteBatch.DrawString(font, Vector2(font_pos.x, font_pos.y + SCORE_SECOND),Color(185,195,201), _T("%d"), ranking_score[SECOND]);
	SpriteBatch.DrawString(font, Vector2(font_pos.x, font_pos.y + SCORE_THIRD), Color(184,115,51), _T("%d"),  ranking_score[THIRD]);
}

void C_RESULT::Add_Sprite(LPCTSTR _sprite_name)
{
	sprite = GraphicsDevice.CreateSpriteFromFile(_sprite_name);
	sprite_list_name.push_back(sprite);
}

void C_RESULT::Ranking() {
	//!3�ʃ����L���O����ւ�
	if (CUI::total > ranking_score[THIRD]) {
		int work = ranking_score[THIRD];
		ranking_score[THIRD] = CUI::total;
	}

	//!2�ʃ����L���O����ւ�
	if (ranking_score[THIRD] > ranking_score[SECOND]) {
		int work = ranking_score[SECOND];
		ranking_score[SECOND] = ranking_score[THIRD];
		ranking_score[THIRD] = work;
	}

	//! 1�ʃ����L���O����ւ�
	if (ranking_score[SECOND] > ranking_score[FIRST]) {
		int work = ranking_score[FIRST];
		ranking_score[FIRST] = ranking_score[SECOND];
		ranking_score[SECOND] = work;
	}
}