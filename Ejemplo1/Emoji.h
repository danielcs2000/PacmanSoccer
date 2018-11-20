#pragma once

#include <SFML\Graphics.hpp>
#include "config.h"

#include <SFML\Audio.hpp>
class Emoji
{
private:
	int radio;
	float velocidad;
	int jugador;
public:
	sf::Texture* temoji;
	sf::CircleShape body;
	sf::SoundBuffer buff;
	// Cargamos un archivo en el buffer
	sf::Sound sonido_grito;


	Emoji(int jugador, sf::Vector2f posicion);
	void MoverArriba();
	void MoverAbajo();
	void MoverDerecha();
	void MoverIzquierda();
	void Mover();
	void Draw(sf::RenderWindow& window);
};

