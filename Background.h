/**************************************************************************
* File name           : OverBackgroud.h
* File Id             £ºMyTona_Test_01
* Abstract            £ºThis file display the backgroud when game is over and 
*                       indicate how to do next step
*                      -----
* Version             £º1.0
* C++ Version         : 11
* Author              £ºDavid Jia
* Data of compeletion £º26.02.2019
**************************************************************************/
#ifndef _OVER_BACKGROUND_
#define _OVER_BACKGROUND_

#pragma once
class Background
{
public:
	Background();
	~Background();
	void Init(const sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
	void RunRendr(sf::RenderWindow& window);
private:
	sf::Font m_font;
	sf::Text m_space;
	sf::Text m_esc;
	sf::Texture m_running;
	sf::Sprite  m_spriteRunBackground;
};
#endif // !_OVER_BACKGROUND_



