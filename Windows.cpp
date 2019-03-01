#include "sfml/Graphics.hpp"
#include <iostream>
#include "Windows.h"



Windows::Windows()
{
}


Windows::~Windows()
{
}

void Windows::Init(int width, int height)
{
	m_window.create(sf::VideoMode(width, height), "MyTona", sf::Style::Default);
	m_window.setFramerateLimit(60);
};
sf::RenderWindow& Windows::GetWindow()
{
	return m_window;
};
const unsigned int& Windows::GetWidth()
{
	return m_width;
};
const unsigned int& Windows::GetHeight()
{
	return m_height;
};
bool  Windows::IsOpen()
{
	return m_window.isOpen();
};
const sf::Vector2f& Windows::GetWinSize()
{
	std::cout << m_width << ";" << m_height<<std::endl;
	std::cout << m_window.getSize().x << ";" << m_window.getSize().y << std::endl;
	return sf::Vector2f(static_cast<float>(m_width), static_cast<float>(m_height));
};

bool Windows::PollEvent(sf::Event& event)
{
	return m_window.pollEvent(event);
};
void Windows::Close()
{
	m_window.close();
};
void Windows::WinRenderBegin()
{
	m_window.clear(sf::Color::Green);
};
void Windows::WinRendreEnd()
{
	m_window.display();
};