#include "sfml/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "Pipe.h"
#include "PipeManager.h"



PipeManager::PipeManager()
{
	m_pipeTexture.loadFromFile("Assets/Pipe.png");
}


PipeManager::~PipeManager()
{

}
void PipeManager::Init(const sf::RenderWindow& window)
{

	for (size_t i = 1; i < PIPE_NUMBER_MAX; i++)
	{
		m_pipeGroup.emplace_back(m_pipeTexture, static_cast<float>((i + 1) * 400), window);
	}
};

void PipeManager::Update(const float delta, const sf::RenderWindow& window)
{
	for (auto& pipe : m_pipeGroup)
	{
		pipe.Update(delta, window);
	}
}
std::vector<Pipe>& PipeManager::GetPipeGroup()
{
	return m_pipeGroup;
}

void PipeManager::Render(sf::RenderWindow& window)
{
	for (auto& pipe : m_pipeGroup) window.draw(pipe);
};
void PipeManager::Reset(const sf::RenderWindow& window)
{
	int i = 2;
	for (auto& pipe : m_pipeGroup)
	{
		pipe.SetPosition(static_cast<float>((i) * 400), window);
		pipe.m_isPassed = false;
		++i;
	}
};