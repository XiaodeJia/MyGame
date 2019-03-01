/**************************************************************************
* File name           : FlapperBird.h
* File Id             £ºMyTona_Test_01
* Abstract            £ºThis file is used for manage bird object including actions and load bird picture.
*                      -----
* Version             £º1.0
* C++ Version         : 11
* Author              £ºDavid Jia
* Data of compeletion £º26.02.2019
**************************************************************************/
#ifndef _FLAPPY_BIRD_H_
#define _FLAPPY_BIRD_H_

#pragma once
class FlappyBird : public sf::Drawable
{
public:
	FlappyBird();
	~FlappyBird();
	void Init(const sf::RenderWindow& window);
	void Reset(const sf::RenderWindow& window);
	void Update(const float delta, const sf::RenderWindow& window, std::vector<Pipe>& pipes);
	void Force();
	int  GetScore() const;
	void Render(sf::RenderWindow& window);
	bool IsAlive();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite    m_sprite;
	sf::Vector2f  m_movement;
	sf::FloatRect m_rect;
	sf::Texture   m_texture;
	float         m_gravity = 758.0f;
	float         m_jumpHeight = -300.0f;
	float         m_rotateRate = 60.0f;
	int           m_score = 0;
	bool          m_isAlive = false;
};
#endif // !_FLAPPY_BIRD_H_

