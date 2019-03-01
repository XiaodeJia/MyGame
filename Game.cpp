#include "GameHeader.h"
#include "MenuHeader.h"
#include "Menu.h"
#include "Game.h"

Game::Game()
{
	m_window.Init(1024, 612);
	m_bird.Init(m_window.GetWindow());
	m_pipeManage.Init(m_window.GetWindow());
	m_background.Init(m_window.GetWindow());
	m_menu.Init(m_window.GetWindow());
}
Game::~Game()
{
	if (m_window.IsOpen())
	{
		m_window.Close();
	}
};
//should combining with Run. need optimization later
void Game::Start()
{
	m_menu.Render(m_window.GetWindow());
	Run();
}
void Game::Run()
{
	while (m_window.IsOpen())
	{
		m_delta = m_clock.restart();

		while (m_window.PollEvent(m_event))
		{
			if (m_event.type == sf::Event::Closed)
			{
				m_window.Close();
			}
			else if (m_event.type == sf::Event::KeyPressed)
			{
				if (m_event.key.code == sf::Keyboard::Space)
				{
					if (m_bird.IsAlive())
					{
						m_bird.Force();
					}
					else
					{
						m_bird.Reset(m_window.GetWindow());
						m_pipeManage.Reset(m_window.GetWindow());
					}

				}
				else if (m_event.key.code == sf::Keyboard::Escape)
				{
					m_menu.Render(m_window.GetWindow());
				}
			}
		}
		//update pipe/bird and score
		if (m_bird.IsAlive())
		{
			m_pipeManage.Update(m_delta.asSeconds(), m_window.GetWindow());
			m_bird.Update(m_delta.asSeconds(), m_window.GetWindow(), m_pipeManage.GetPipeGroup());
			m_score.CalculateScore(m_bird);
		}
		//send screen
		GameRender();
	}
}

void Game::GameRender()
{
	m_window.WinRenderBegin();
	m_background.RunRendr(m_window.GetWindow());
	m_bird.Render(m_window.GetWindow());
	m_pipeManage.Render(m_window.GetWindow());

	if (!m_bird.IsAlive())
	{
		m_background.Render(m_window.GetWindow());
	}
	m_score.Render(m_window.GetWindow());
	
	m_window.WinRendreEnd();
};

void Game::Close()
{
	m_window.Close();
};