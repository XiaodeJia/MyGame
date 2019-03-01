/**************************************************************************
* File name           : OverBackgroud.h
* File Id             ��MyTona_Test_01
* Abstract            ��This file display the backgroud when game is over and 
*                       indicate how to do next step
*                      -----
* Version             ��1.0
* C++ Version         : 11
* Author              ��David Jia
* Data of compeletion ��26.02.2019
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



