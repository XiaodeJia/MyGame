/**************************************************************************
* File name           : PipeManager.h
* File Id             £ºMyTona_Test_01
* Abstract            £ºThis file manage all pipes
*
*                      -----
* Version             £º1.0
* C++ Version         : 11
* Author              £ºDavid Jia
* Data of compeletion £º26.02.2019
**************************************************************************/
#ifndef _PIPE_MANAGER_H_
#define _PIPE_MANAGER_H_
#pragma once

const unsigned int PIPE_NUMBER_MAX = 4;

class PipeManager
{
public:
	PipeManager();
	~PipeManager();
	void Init(const sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
	void Update(const float delta, const sf::RenderWindow& window);
	std::vector<Pipe>& GetPipeGroup();
	void Reset(const sf::RenderWindow& window);
private:
	std::vector<Pipe>  m_pipeGroup;
	sf::Texture        m_pipeTexture;
};
#endif // !_PIPE_MANAGER_H_



