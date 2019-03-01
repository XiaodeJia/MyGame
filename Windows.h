/**************************************************************************
* File name           : Windows.h
* File Id             £ºMyTona_Test_01
* Abstract            £ºThis file creates windows 
*
*
*                      -----
* Version             £º1.0
* C++ Version         : 11
* Author              £ºDavid Jia
* Data of compeletion £º26.02.2019
**************************************************************************/
#ifndef _WINDOWS_H_
#define _WINDOWS_H_
#pragma once
class Windows
{
public:
	Windows();
	~Windows();
	void Init(int width, int height);
	sf::RenderWindow& GetWindow();
	const unsigned int& GetWidth();
	const unsigned int& GetHeight();
	bool  IsOpen();
	const sf::Vector2f& GetWinSize();
	bool PollEvent(sf::Event& event);
	void Close();
	void WinRenderBegin();
	void WinRendreEnd();
private:
	sf::RenderWindow m_window;
	unsigned int     m_width;
	unsigned int     m_height;
};
#endif // !_WINDOWS_H_



