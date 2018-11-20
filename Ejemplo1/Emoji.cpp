#include "Emoji.h"



Emoji::Emoji(int jugador, sf::Vector2f posicion)
{
	radio = 30;
	

	this->jugador = jugador;
	//body.setFillColor(sf::Color::White);


	temoji = new sf::Texture();
	if (jugador == 1) {
		temoji->loadFromFile("emoji2.png");
	}
	if (jugador == 2) {
		temoji->loadFromFile("emoji1.png");
	}


	buff.loadFromFile("sonidoenojo.wav");

	// Le asignamos el buffer cargado
	sonido_grito.setBuffer(buff);
	// establecemos el volumen a 80
	sonido_grito.setVolume(80);
	body.setTexture(temoji);


	body.setRadius(radio);
	body.setPosition(posicion.x, posicion.y);
}

void Emoji::MoverArriba()
{
	body.move(0, -0.1);
}

void Emoji::MoverAbajo()
{
	body.move(0, 0.1);
}

void Emoji::MoverDerecha()
{
	body.move(0.1, 0);
}

void Emoji::MoverIzquierda()
{
	body.move(-0.1, 0);
}

void Emoji::Mover()
{
	if (jugador == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			
			if(body.getPosition().y > 10+radio)
				MoverArriba();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if(body.getPosition().y < HEIGHT-10-radio)
				MoverAbajo();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if(body.getPosition().x >10+radio )
				MoverIzquierda();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (body.getPosition().x< WIDTH - radio-10)
				MoverDerecha();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
			sf::Clock clock;
			body.setRadius(50);

			if (clock.getElapsedTime() < sf::seconds(4)) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					if (body.getPosition().y > 10 + radio) {
						MoverArriba();
						MoverArriba();
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (body.getPosition().y < HEIGHT - 10 - radio) {
						MoverAbajo();
						MoverAbajo();
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					if (body.getPosition().x > 10 + radio) {
						MoverIzquierda();
						MoverIzquierda();
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (body.getPosition().x < WIDTH - radio - 10)
					{
						MoverDerecha();
						MoverDerecha();
					}

				}
			}

		}
		else {
			body.setRadius(30);
		}

	}
	else if (jugador == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (body.getPosition().y > 10 + radio) {
				MoverArriba();
			}
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (body.getPosition().y < HEIGHT - 10 - radio)
				MoverAbajo();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (body.getPosition().x >10+radio)
				MoverIzquierda();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (body.getPosition().x < WIDTH-radio-10)
				MoverDerecha();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			sf::Clock clock;
			body.setRadius(50);
			if (clock.getElapsedTime() < sf::seconds(4)) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					if (body.getPosition().y > 10+radio) {
						MoverArriba();
						MoverArriba();
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					if (body.getPosition().y < HEIGHT - 10 - radio) {
						MoverAbajo();
						MoverAbajo();
					}
						
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					if (body.getPosition().x > 10+radio) {
						MoverIzquierda();
						MoverIzquierda();
					}
						
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
				{
					if (body.getPosition().x < WIDTH -  radio - 10) 
					{
						MoverDerecha();
						MoverDerecha();
					}	
						
				}
			}
			
		}
		else
		{
			body.setRadius(30);
		}
	}
}

void Emoji::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

