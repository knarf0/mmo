#include "Game.hpp"

Game::Game()
{
	updateClock.restart();
}	

sf::Int64 Game::timeSinceLastUpdate()
{
	return updateClock.getElapsedTime().asMicroseconds();
}	

void Game::update(std::list<Client> & clients)
{
	sf::Int64 time = timeSinceLastUpdate();
	updateClock.restart();

	for (auto object = objects.begin(); object != objects.end(); ++object)
	{
		object->update(time);

		if (object->isDestroyed())
			objects.erase(object--);
	}
}
