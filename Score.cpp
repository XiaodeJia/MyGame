#include"sfml/Graphics.hpp"
#include <iostream>
#include <fstream>
#include "Pipe.h"
#include "FlappyBird.h"
#include "Score.h"



Score::Score()
{
	m_readScore.open("score.txt");
	m_readScore >> m_highScore;
	m_readScore.close();

	m_font.loadFromFile("Assets/Font.ttf");
	m_score.setFont(m_font);
	m_score.setPosition(20, 20);
	m_score.setCharacterSize(24);
	m_score.setFillColor(sf::Color::Red);
	m_score.setString("Score: 0");

	m_highSoreText.setFont(m_font);
	m_highSoreText.setPosition(20, 50);
	m_highSoreText.setCharacterSize(24);
	m_highSoreText.setFillColor(sf::Color::Red);
	m_highSoreText.setString("High Score: " + std::to_string(m_highScore));
}


Score::~Score()
{
}
const sf::Text& Score:: GetScore()
{
	return m_score;
};
const sf::Text& Score::GetHighestScore()
{
	return m_highSoreText;
};
void Score::CalculateScore(const FlappyBird& bird)
{
	if (bird.GetScore() != m_currentScore)
	{
		m_currentScore = bird.GetScore();
		m_score.setString("Score: " + std::to_string(bird.GetScore()));

		if (m_currentScore > m_highScore)
		{
			m_highScore = m_currentScore;
			m_outScore.open("score.txt");
			m_outScore << m_highScore;
			m_outScore.close();
			m_highSoreText.setString("High Score: " + std::to_string(m_highScore));
		}
	}
};
void  Score::Render(sf::RenderWindow& window)
{
	//score.setString("Score: " + std::to_string(current_score));
	window.draw(m_score);
	window.draw(m_highSoreText);
};
