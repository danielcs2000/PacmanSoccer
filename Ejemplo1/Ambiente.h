#pragma once
#include<SFML\Graphics.hpp>
#include "config.h"
class Ambiente
{
public:
	Ambiente();
	sf::RectangleShape outleft;

	sf::RectangleShape outright;
	
	sf::RectangleShape mid;

	sf::RectangleShape up;
	
	sf::RectangleShape down;

	sf::RectangleShape arcoLeft;

	sf::RectangleShape arcoRight;

	sf::Texture campo;

	sf::Sprite spritecampo;

	void draw(sf::RenderWindow& window);
};

