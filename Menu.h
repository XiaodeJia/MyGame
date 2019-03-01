/**************************************************************************
* File name           : Menu.h
* File Id             ��MyTona_Test_01
* Abstract            ��This start menu include start,option,exit
*                      -----
* Version             ��1.0
* C++ Version         : 11
* Author              ��David Jia
* Data of compeletion ��26.02.2019
**************************************************************************/
#ifndef _MENU_H_
#define _MENU_H_
#pragma once

class Menu
{
public:
	Menu();
	~Menu();
	void Init(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
	sf::Sprite& GetBackground();
private:
	TextureHolder textures;
	sf::Sprite    spriteBackGround;
	sf::Sprite    spriteNewGame;
	sf::Sprite    spriteOptions;
	sf::Sprite    spriteExit;
	sf::Sprite	  spriteCheck;
};
#endif // !_MENU_H_

