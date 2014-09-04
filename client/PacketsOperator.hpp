#ifndef PACKETSOPERATOR
#define PACKETSOPERATOR

sf::Packet & operator <<(sf::Packet &, const sf::Keyboard::Key &);
sf::Packet & operator >>(sf::Packet &, sf::Keyboard::Key &);

sf::Packet & operator <<(sf::Packet &, const sf::Event &);
sf::Packet & operator >>(sf::Packet &, sf::Event &);

#endif
