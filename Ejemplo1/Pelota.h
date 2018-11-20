#include <SFML\Graphics.hpp>
#include "config.h"
#include <SFML\Audio.hpp>
class Pelota
{
private:
	int radio;
public:
	sf::CircleShape body;
	sf::Vector2f velocidad;
	sf::Texture* tpelota;
	

	void Draw(sf::RenderWindow& window);
	void Mover();

	Pelota();


};
