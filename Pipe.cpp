#include "sfml/Graphics.hpp"
#include "GameMath.h"
#include "Pipe.h"


Pipe::Pipe(const sf::Texture& texture, const float position, const sf::RenderWindow& window) : m_originalPosition(3 * 400)
{
	this->m_texture = &texture;
	float offset = GameMath::RandomFloat(-(texture.getSize().y / 3.0f), texture.getSize().y / 3.0f);

	m_top.setTexture(texture);
	m_top.setOrigin(static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y / 2.0f));
	m_top.setScale(1.0f, -1.0f);
	m_top.setPosition(position, offset);

	m_bottom.setTexture(texture);
	m_bottom.setOrigin(static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y / 2.0f));
	m_bottom.setPosition(position, static_cast<float>(window.getSize().y) + offset);
}
Pipe::~Pipe()
{
};
void Pipe::Update(const float delta, const sf::RenderWindow& window)
{
	m_top.move(-m_speed * delta, 0.0f);
	m_bottom.move(-m_speed * delta, 0.0f);

	if (m_top.getPosition().x <= 0)
	{
		float offset = GameMath::RandomFloat(-(m_texture->getSize().y / 3.0f), m_texture->getSize().y / 3.0f);
		m_top.setPosition(m_originalPosition, offset);
		m_bottom.setPosition(m_originalPosition, static_cast<float>(window.getSize().y) + offset);
		m_isPassed = false;
	}
}

bool Pipe::Intersects(const sf::FloatRect& rect) const
{
	return m_top.getGlobalBounds().intersects(rect) || m_bottom.getGlobalBounds().intersects(rect);
}

const float Pipe::GetPosition() const
{
	return m_top.getPosition().x;
}

void Pipe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_top);
	target.draw(m_bottom);
}
void Pipe::SetPosition(const float position, const sf::RenderWindow& window)
{
	m_top.setPosition(position, -50);
	m_bottom.setPosition(position, static_cast<float>(window.getSize().y) +50);
};