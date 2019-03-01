/**************************************************************************
* File name           : Pipe.h
* File Id             £ºMyTona_Test_01
* Abstract            £ºThis file provide basic pipe functions including init, update position
*                       
*                      -----
* Version             £º1.0
* C++ Version         : 11
* Author              £ºDavid Jia
* Data of compeletion £º26.02.2019
**************************************************************************/
#ifndef _PIPE_H_
#define _PIPE_H_
#pragma once
class Pipe : public sf::Drawable
{
public:
	Pipe(const sf::Texture& texture, const float position, const sf::RenderWindow& window);
	void Update(const float delta, const sf::RenderWindow& window);
	bool Intersects(const sf::FloatRect& rect) const;
	const float GetPosition() const;
	void SetPosition(const float position, const sf::RenderWindow& window);
	~Pipe();
public:
	bool m_isPassed = false;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite         m_top;
	sf::Sprite         m_bottom;
	const sf::Texture* m_texture; //get from pipe manager, no resposible to delete
	float              m_speed = 200.0f;
	float              m_originalPosition;
};

#endif // !_PIPE_H_
