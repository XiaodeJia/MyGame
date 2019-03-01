/**************************************************************************
* File name           : ResourceHolder.h
* File Id             ��MyTona_Test_01
* Abstract            ��This file provides a container to manage many sprites by map
*
*
*                      -----
* Version             ��1.0
* C++ Version         : 11
* Author              ��David Jia
* Data of compeletion ��26.02.2019
**************************************************************************/
#ifndef _RESOUCE_IDENTIFIER_H
#define _RESOUCE_IDENTIFIER_H

namespace sf {
	class Texture;
	class Font;
}

namespace Textures {
	enum ID {
		Image_01 = 0,
		Image_02,
		Image_03,
		Image_04,
		Image_05
	};
}

namespace Fonts {
	enum ID {
		Main = 0
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>   TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>         FontHolder;

#endif //GAME_RESOUCEIDENTIFIERS_H#pragma once
