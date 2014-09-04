#include <iostream>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "main.hpp"
#include "Object.cpp"
#include "PacketsOperator.cpp"
#include "Game.cpp"
#include "Server.cpp"
#include "Client.cpp"

int main()
{
	Server server(53000);

	while (!server.mustShutDown())
		server.update();

	return 0;
}

