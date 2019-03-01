#include "MenuHeader.h"
#include "Menu.h"


Menu::Menu()
{

}
Menu::~Menu()
{
}
void Menu::Init(sf::RenderWindow &window)
{
	textures.load(Textures::Image_01, "Assets/ChineseBackground.jpg");
	textures.load(Textures::Image_02, "Assets/NewGame.png");
	textures.load(Textures::Image_03, "Assets/Options.png");
	textures.load(Textures::Image_04, "Assets/Exit.png");
	textures.load(Textures::Image_05, "Assets/CheckPicture.jpg");

	spriteBackGround.setTexture(textures.get(Textures::Image_01));
	spriteNewGame.setTexture(textures.get(Textures::Image_02));
	spriteOptions.setTexture(textures.get(Textures::Image_03));
	spriteExit.setTexture(textures.get(Textures::Image_04));
	spriteCheck.setTexture(textures.get(Textures::Image_05));

	spriteNewGame.setPosition(10, 440);
	spriteOptions.setPosition(10, 490);
	spriteExit.setPosition(10, 540);

	
}
void Menu::Render(sf::RenderWindow &window)
{
	bool isMenu = true;
	int menuNum = 0;
	while (isMenu)
	{
		spriteNewGame.setColor(sf::Color(135, 135, 135));
		spriteOptions.setColor(sf::Color(135, 135, 135));
		spriteExit.setColor(sf::Color(135, 135, 135));

		menuNum = 0;
		window.clear(sf::Color::White);

		if (sf::IntRect(30, 440, 160, 40).contains(sf::Mouse::getPosition(window))) 
		{
			spriteNewGame.setColor(sf::Color(135, 34, 34));
			menuNum = 1;
		}

		if (sf::IntRect(30, 490, 115, 40).contains(sf::Mouse::getPosition(window))) 
		{
			spriteOptions.setColor(sf::Color(135, 34, 34));
			menuNum = 2;
		}

		if (sf::IntRect(30, 540, 65, 40).contains(sf::Mouse::getPosition(window))) 
		{
			spriteExit.setColor(sf::Color(135, 34, 34));
			menuNum = 3;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) 
			{
				isMenu = false;
			}
			if (menuNum == 2)
			{
				window.draw(spriteCheck);
				window.display();
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
			}
			if (menuNum == 3)
			{
				window.close();
				isMenu = false;
			}

		}

		window.draw(spriteBackGround);
		window.draw(spriteNewGame);
		window.draw(spriteOptions);
		window.draw(spriteExit);

		window.display();
	}
};

sf::Sprite& Menu::GetBackground()
{
	return spriteCheck;
}
