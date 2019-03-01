/**************************************************************************
* File name           : Score.h
* File Id             ��MyTona_Test_01
* Abstract            ��This file is to calculate the score when bird pass pipe and store the highest score
*
*
*                      -----
* Version             ��1.0
* C++ Version         : 11
* Author              ��David Jia
* Data of compeletion ��26.02.2019
**************************************************************************/
#ifndef _SCORE_H_
#define _SCORE_H_
#pragma once
class Score
{
public:
	Score();
	~Score();

	const sf::Text& GetScore();
	const sf::Text& GetHighestScore();
	void CalculateScore(const FlappyBird& bird);
	void Render(sf::RenderWindow& window);
private:
	sf::Font m_font;
	sf::Text m_score;
	sf::Text m_highSoreText;

	std::ifstream m_readScore;
	std::ofstream m_outScore;
	int m_highestScore;
	int m_currentScore;

	int m_highScore;

};
#endif // !_SCORE_H_

