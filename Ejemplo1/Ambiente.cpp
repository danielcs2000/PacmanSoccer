#include "Ambiente.h"



Ambiente::Ambiente()
{
	outleft.setFillColor(sf::Color::Black);
	outleft.setSize(sf::Vector2f(10, HEIGHT));
	outleft.setPosition(WIDTH - 10, 0);

	outright.setFillColor(sf::Color::Black);
	outright.setSize(sf::Vector2f(10, HEIGHT));
	outright.setPosition(0, 0);

	mid.setFillColor(sf::Color::Black);
	mid.setSize(sf::Vector2f(15, HEIGHT));
	mid.setPosition(WIDTH / 2, 0);

	up.setFillColor(sf::Color::Black);
	up.setSize(sf::Vector2f(WIDTH, 10));
	up.setPosition(0, 0);

	down.setFillColor(sf::Color::Black);
	down.setSize(sf::Vector2f(WIDTH, 10));
	down.setPosition(0, HEIGHT - 10);

	arcoLeft.setFillColor(sf::Color::White);
	arcoLeft.setSize(sf::Vector2f(10, 110));
	arcoLeft.setPosition(10, HEIGHT/2-52);

	arcoRight.setFillColor(sf::Color::White);
	arcoRight.setSize(sf::Vector2f(10, 110));
	arcoRight.setPosition(WIDTH-18, HEIGHT / 2 - 52);

	campo.loadFromFile("campo.png");
	spritecampo.setTexture(campo);
	spritecampo.setScale((float)WIDTH / spritecampo.getTexture()->getSize().x, (float)HEIGHT / spritecampo.getTexture()->getSize().y);

}

void Ambiente::draw(sf::RenderWindow& window)
{
	window.draw(outleft);
	
	window.draw(outright);
	
	window.draw(mid);
	
	window.draw(up);
	
	window.draw(down);
	
	window.draw(arcoLeft);

	window.draw(arcoRight);

	window.draw(spritecampo);

}


