#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Emoji.h"
#include "config.h"
#include <cmath>
#include "Pelota.h"
#include "Ambiente.h"
#include <SFML\Audio.hpp>
#include <stdlib.h>


int score1 = 0;
int score2 = 0;



using namespace sf;


bool intersects(sf::CircleShape& c1, sf::RectangleShape& rect2) {
	sf::FloatRect circle = c1.getGlobalBounds();
	sf::FloatRect rectangle = rect2.getGlobalBounds();
	return circle.intersects(rectangle);
}
bool intersects(sf::CircleShape& c1, sf::CircleShape& c2) {
	sf::FloatRect circle1 = c1.getGlobalBounds();
	sf::FloatRect circle2 = c2.getGlobalBounds();
	return circle1.intersects(circle2);
}
bool intersects(sf::Sprite& c1, sf::CircleShape& c2) {
	sf::FloatRect circle1 = c1.getGlobalBounds();
	sf::FloatRect circle2 = c2.getGlobalBounds();
	return circle1.intersects(circle2);
}



class Control {
public:

	
	int empezar() {
		srand(time(NULL));

		int r = rand() % 361;


		sf::VideoMode videomode(WIDTH, HEIGHT);
		sf::RenderWindow window(videomode, "Emoji Soccer");

		Pelota Ball;
		Ball.body.setOrigin(Ball.body.getGlobalBounds().height / 2, Ball.body.getGlobalBounds().width / 2);

		Emoji Jugador1(1, sf::Vector2f(WIDTH - 40, HEIGHT / 2));
		Emoji Jugador2(2, sf::Vector2f(30, HEIGHT / 2));

		Jugador2.body.setOrigin(Jugador2.body.getGlobalBounds().height / 2, Jugador2.body.getGlobalBounds().width / 2);
		Jugador1.body.setOrigin(Jugador1.body.getGlobalBounds().height / 2, Jugador1.body.getGlobalBounds().width / 2);

		sf::Font fuente;
		fuente.loadFromFile("Europhonic.otf");

		sf::Text player1score;
		player1score.setFont(fuente);
		player1score.setString("0");
		player1score.setPosition(WIDTH / 2 + 30, 20);

		sf::Text player2score;
		player2score.setFont(fuente);
		player2score.setString("0");
		player2score.setPosition(WIDTH / 2 - 30, 20);



		Ambiente<RectangleShape> Ambiente;

		SoundBuffer buffer;
		// Cargamos un archivo en el buffer
		if (!buffer.loadFromFile("pop.wav"))
		{
			return EXIT_FAILURE;
		}

		// Creamos un sonido
		sf::Sound sonido_pelota;
		// Le asignamos el buffer cargado
		sonido_pelota.setBuffer(buffer);
		// establecemos el volumen a 80
		sonido_pelota.setVolume(80);

		// Creamos un objeto música
		sf::Music musica;
		// Abrimos el fichero de música que queremos reproducir
		musica.openFromFile("AudioInicio");
		// Activamos el loop cuando acabe empezará de nuevo
		musica.setLoop(true);
		// Empezamos a reproducir nuesta música
		musica.play();







		while (window.isOpen()) {
			window.clear(sf::Color::Green);
			Ambiente.draw(window);
			Ball.Draw(window);
			Jugador1.Draw(window);
			Jugador2.Draw(window);
			window.draw(player1score);
			window.draw(player2score);



			window.display();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			Jugador1.Mover();
			Jugador2.Mover();





			if (intersects(Ball.body, Ambiente.arcoLeft)) {
				r = rand() % 361;
				score1++;
				sonido_pelota.play();
				player1score.setString(std::to_string(score1));
				Jugador1.body.setPosition(WIDTH - 40, HEIGHT / 2);
				Jugador2.body.setPosition(30, HEIGHT / 2);
				Ball.body.setPosition(WIDTH / 2, HEIGHT / 2);
				float Modulo = sqrt(pow(Ball.velocidad.x, 2) + pow(Ball.velocidad.y, 2));
				Ball.velocidad.x = Modulo * sin(r);
				Ball.velocidad.y = Modulo * cos(r);

				std::cout << "Player1=  " << score1 << std::endl;

			}
			if (intersects(Ball.body, Ambiente.arcoRight)) {
				r = rand() % 361;
				score2++;
				player2score.setString(std::to_string(score2));
				Jugador1.body.setPosition(WIDTH - 40, HEIGHT / 2);
				Jugador2.body.setPosition(30, HEIGHT / 2);
				Ball.body.setPosition(WIDTH / 2, HEIGHT / 2);
				float Modulo = sqrt(pow(Ball.velocidad.x, 2) + pow(Ball.velocidad.y, 2));
				Ball.velocidad.x = Modulo * sin(r);
				Ball.velocidad.y = Modulo * cos(r);
				std::cout << "Player2 =  " << score2 << std::endl;

			}

			if (intersects(Ball.body, Ambiente.up)) {
				sonido_pelota.play();
				Ball.body.setPosition(Ball.body.getPosition().x, 10 + Ball.body.getRadius());
				Ball.velocidad.y = -Ball.velocidad.y;
			}
			if (intersects(Ball.body, Ambiente.down)) {
				sonido_pelota.play();
				Ball.body.setPosition(Ball.body.getPosition().x, HEIGHT - 11 - Ball.body.getRadius());
				Ball.velocidad.y = -Ball.velocidad.y;

			}
			if (intersects(Ball.body, Ambiente.outleft)) {
				sonido_pelota.play();

				Ball.body.setPosition(WIDTH - 10 - Ball.body.getRadius(), Ball.body.getPosition().y);
				Ball.velocidad.x = -Ball.velocidad.x;
			}

			if (intersects(Ball.body, Ambiente.outright)) {
				sonido_pelota.play();
				Ball.body.setPosition(10 + Ball.body.getRadius(), Ball.body.getPosition().y);
				Ball.velocidad.x = -Ball.velocidad.x;
			}

			if (intersects(Ball.body, Jugador1.body)) {
				sonido_pelota.play();
				float Modulo = sqrt(pow(Ball.velocidad.x, 2) + pow(Ball.velocidad.y, 2));
				float distancia = sqrt(pow(Ball.body.getPosition().x - Jugador1.body.getPosition().x, 2) + pow(Ball.body.getPosition().y - Jugador1.body.getPosition().y, 2));
				float seno = (-Ball.body.getPosition().y + Jugador1.body.getPosition().y) / distancia;
				float coseno = (-Ball.body.getPosition().x + Jugador1.body.getPosition().x) / distancia;
				Ball.velocidad.x = -(Modulo*coseno);
				Ball.velocidad.y = -(Modulo*seno);

			}
			if (intersects(Ball.body, Jugador2.body)) {


				sonido_pelota.play();
				float Modulo = sqrt(pow(Ball.velocidad.x, 2) + pow(Ball.velocidad.y, 2));
				float distancia = sqrt(pow(Ball.body.getPosition().x - Jugador2.body.getPosition().x, 2) + pow(Ball.body.getPosition().y - Jugador2.body.getPosition().y, 2));
				float seno = (-Ball.body.getPosition().y + Jugador2.body.getPosition().y) / distancia;
				float coseno = (-Ball.body.getPosition().x + Jugador2.body.getPosition().x) / distancia;
				Ball.velocidad.x = -(Modulo*coseno);
				Ball.velocidad.y = -(Modulo*seno);

			}
			Ball.Mover();

		}
		return 0;
	}

};



