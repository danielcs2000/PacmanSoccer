#include "Pelota.h"



void Pelota::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Pelota::Mover()
{
	body.move(velocidad.x, velocidad.y);
}

Pelota::Pelota()
{
	
	body.setRadius(20);
	body.setPosition(WIDTH/2, HEIGHT/2);



	tpelota = new sf::Texture();
	tpelota->loadFromFile("fantasma.png");
	body.setTexture(tpelota);


	velocidad = sf::Vector2f(0.15f, 0.15f);
}

