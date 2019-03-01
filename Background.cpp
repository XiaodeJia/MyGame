#include "sfml/Graphics.hpp"
#include "Background.h"



Background::Background()
{
	m_font.loadFromFile("Assets/Font.ttf");

}


Background::~Background()
{
}

void Background::Init(const sf::RenderWindow& window)
{
	//space to start
	m_space.setFont(m_font);
	m_space.setCharacterSize(24);
	m_space.setFillColor(sf::Color::Blue);
	m_space.setString("Press SPACE To Start!");
	m_space.setOrigin( m_space.getGlobalBounds().left + (m_space.getGlobalBounds().width / 2.0f),
	                        m_space.getGlobalBounds().top + (m_space.getGlobalBounds().height / 2.0f));

	m_space.setPosition(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	m_space.move(0.0, 50.0f);

	//esc to exit
	m_esc.setFont(m_font);
	m_esc.setCharacterSize(24);
	m_esc.setFillColor(sf::Color::Blue);
	m_esc.setString("Press ESC To EXIT!");
	m_esc.setOrigin(m_esc.getGlobalBounds().left + (m_esc.getGlobalBounds().width / 2.0f),
		          m_esc.getGlobalBounds().top + (m_esc.getGlobalBounds().height / 2.0f));

	m_esc.setPosition(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	m_esc.move(0.0, 80.0f);

	//backgroud when running
	m_running.loadFromFile("Assets/runGround.jpg");
	m_spriteRunBackground.setTexture(m_running);

};
void Background::Render(sf::RenderWindow& window)
{
	window.draw(m_space);
	window.draw(m_esc);
};
void Background::RunRendr(sf::RenderWindow& window)
{
	window.draw(m_spriteRunBackground);
};