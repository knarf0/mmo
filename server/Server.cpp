#include "Server.hpp"

Server::Server(unsigned int p)
{
	mustShutDown_ = false;

	listener.setBlocking(false);

	port = p;

	uptime_.restart();

	listener.listen(port);
}

Server::~Server()
{
}	

void Server::checkNewConnections()
{
	clients.emplace_back();

	if (listener.accept((clients.back()).socket) == sf::Socket::Done)
	{
		std::cout << "New client connected." << std::endl;	
		clients.back().init();
		return;
	}	

	clients.pop_back();
}	

void Server::checkDisconnections()
{
	for (auto i = clients.begin(); i != clients.end(); ++i)
	{
		if (i->isDisconnected())
		{
			clients.erase(i--);
			std::cout << "Client disconnected." << std::endl;
		}	
	}
}	

void Server::processMessage(sf::Packet & p, std::list<Client>::iterator & client)
{
	std::string message;

	p >> message;

	if (message == "disco")
		client->disconnect();
	else if (message == "shutdown")
		mustShutDown_ = true;
	else 
		std::cout << "Unknow message received : " << message  << std::endl;
}	

void Server::processEvent(sf::Packet & p, std::list<Client>::iterator & client)
{
	sf::Event event;

	p >> event;

	if (event.type == sf::Event::EventType::MouseMoved)
	{
		client->setMousePosition(event.mouseMove.x, event.mouseMove.y);
	}
	else if (event.type == sf::Event::EventType::MouseButtonPressed)
	{
		client->setButtonPressed(event.mouseButton.button, true);
	}
	else if (event.type == sf::Event::EventType::MouseButtonReleased)
	{
		client->setButtonPressed(event.mouseButton.button, false);
	}
	else if (event.type == sf::Event::EventType::KeyPressed)
	{
		client->setKeyPressed(event.key.code, true);
	}
	else if (event.type == sf::Event::EventType::KeyReleased)
	{
		client->setKeyPressed(event.key.code, false);
	}
}	

void Server::processPacket(sf::Packet & p, std::list<Client>::iterator & client)
{
	std::string code;

	p >> code;

	if (code == "message")
		processMessage(p, client);
	else if (code == "event")
		processEvent(p, client);
	else
		std::cout << "Unknown packet received : " << code  << std::endl;
}	

void Server::receivePackets()
{
	for (auto client = clients.begin(); client != clients.end(); ++client)
	{
		sf::Packet p;
		if (client->receive(p))
			processPacket(p, client);
	}	
}	

void Server::update()
{
	checkNewConnections();
	checkDisconnections();
	receivePackets();
	game.update(clients);
}

bool Server::noClients()
{
	return clients.empty();
}	

bool Server::mustShutDown()
{
	return mustShutDown_;
}	

float Server::uptime()
{
	return uptime_.getElapsedTime().asSeconds();
}
