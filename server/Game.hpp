#ifndef GAME
#define GAME

#include "Client.hpp"
#include "Object.hpp"

class Game
{
	private :

	sf::Clock updateClock;
	std::list<Object> objects;

	public :

	Game();
	sf::Int64 timeSinceLastUpdate();
	void update(std::list<Client>&);
};

#endif
