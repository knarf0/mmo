#ifndef SERVER
#define SERVER

#include "Client.hpp"

class Server
{
	private :
	
	unsigned int port;	
	Game game;
	sf::TcpListener listener;
	std::list<Client> clients;
	sf::Clock uptime_;
	bool mustShutDown_;

	public :

	Server(unsigned int);
	~Server();
	void checkNewConnections();
	void checkDisconnections();
	void update();
	void receivePackets();
	void processMessage(sf::Packet &, std::list<Client>::iterator &);
	void processEvent(sf::Packet &, std::list<Client>::iterator &);
	void processPacket(sf::Packet &, std::list<Client>::iterator &);
	bool noClients();
	bool mustShutDown();
	float uptime();
};	

#endif
