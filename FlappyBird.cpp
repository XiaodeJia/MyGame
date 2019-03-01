#include "sfml/Graphics.hpp"
#include <vector>
#include "GameMath.h"
#include "Pipe.h"
#include "FlappyBird.h"



FlappyBird::FlappyBird()
{
}

FlappyBird::~FlappyBird()
{
}

void FlappyBird::Init(const sf::RenderWindow& window)
{
	m_texture.loadFromFile("Assets/Bird.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(static_cast<sf::Vector2f>(m_texture.getSize()) / 2.0f);
	m_sprite.setPosition(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	m_rect = m_sprite.getGlobalBounds();
	m_isAlive = false;
}

void FlappyBird::Reset(const sf::RenderWindow& window)
{
	m_sprite.setPosition(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	m_sprite.setRotation(0.0f);
	m_movement *= 0.0f;
	m_score = 0;
	m_isAlive = true;
}

void FlappyBird::Update(const float delta, const sf::RenderWindow& window, std::vector<Pipe>& pipes)
{
	m_movement.y += m_gravity * delta;
	m_sprite.move(m_movement * delta);
	m_sprite.rotate(m_rotateRate * delta);

	if (m_sprite.getRotation() >= 60.0f && m_sprite.getRotation() <= 330.0f)
	{
		m_sprite.setRotation(60.0f);
	}
		

	if (m_sprite.getPosition().y <= 0.0f || m_sprite.getPosition().y >= static_cast<sf::Vector2f>(window.getSize()).y)
	{
		
		m_isAlive = false;
		return;
	}
	
	m_rect.left = m_sprite.getPosition().x - (m_texture.getSize().x / 2.0f);
	m_rect.top = m_sprite.getPosition().y - (m_texture.getSize().y / 2.0f);

	for (auto& pair : pipes)
	{
		//collision inspect
		if (pair.Intersects(m_rect)) 
		{
			
			m_isAlive = false;
			return;
		}
		if (!pair.m_isPassed && m_sprite.getPosition().x > pair.GetPosition())
		{
			pair.m_isPassed = true;
			m_score++;
		}
	}
}

void FlappyBird::Force()
{
	m_movement.y = m_jumpHeight;
	m_sprite.setRotation(330.0f);
}

int FlappyBird::GetScore() const
{
	return m_score;
}

void FlappyBird::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}
void FlappyBird::Render(sf::RenderWindow& window)
{
	window.draw(*this);
}
bool FlappyBird::IsAlive()
{
	return m_isAlive;
};