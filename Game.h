/**************************************************************************
* File name           : Game.h
* File Id             £ºMyTona_Test_01
* Abstract            £ºThis file is the interface to manage all bojects.
*                      -----
* Version             £º1.0
* C++ Version         : 11
* Author              £ºDavid Jia
* Data of compeletion £º26.02.2019
**************************************************************************/
#ifndef _GAME_H_
#define _GAME_H_
#pragma once
class Game
{
public:
	Game();
	~Game();
	void Start();
	void Run();
	void Close();
protected:
	void GameRender();
private:
	sf::Event m_event;
	sf::Clock m_clock;
	sf::Time  m_delta;

	Windows        m_window;
	PipeManager    m_pipeManage;
	FlappyBird     m_bird;
	Score          m_score;
	Background     m_background;
	Menu           m_menu;
};
#endif // !_GAME_H_

