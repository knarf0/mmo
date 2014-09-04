#include "Client.hpp"

Client::Client()
{
	lastRecieved.restart();

	socket.setBlocking(false);

	init();
}	

Client::~Client()
{
	socket.disconnect();
}	

void Client::init()
{
	mouseButtons.init();
	keyButtons.init();
}	

bool Client::isButtonPressed(std::string s)
{
	if (s == "left")
		return mouseButtons.left;
	else if (s == "right")
		return mouseButtons.right;
	else if (s == "middle")
		return mouseButtons.middle;
	else if (s == "wheel")
		return mouseButtons.wheel;

	return false;
}

bool Client::isKeyPressed(std::string s)
{
	if (s == "enter" || s == "return")
		return keyButtons.enter;
	else if (s == "space")
		return keyButtons.space;
	else if (s == "escape")
		return keyButtons.escape;
	else if ((s.size() == 1) && (s[0] - 'a' >= 0) && (s[0] - 'a' < 26))
		return keyButtons.letters[s[0] - 'a'];
	return false;
}

void Client::setKeyPressed(std::string s, bool b)
{
	if (s == "enter")
		keyButtons.enter = b;
	else if (s == "space")
		keyButtons.space = b;
	else if (s == "escape")
		keyButtons.escape = b;
	else if ((s.size() == 1) && (s[0] - 'a' >= 0) && (s[0] - 'a' < 26))
		keyButtons.letters[s[0] - 'a'] = b;
}

void Client::setButtonPressed(sf::Mouse::Button button, bool b)
{
	if (button == sf::Mouse::Left)
		mouseButtons.left = b;
	else if (button == sf::Mouse::Right)
		mouseButtons.right = b;
	else if (button == sf::Mouse::Middle)
		mouseButtons.middle = b;
}

void Client::setKeyPressed(sf::Keyboard::Key k, bool b)
{
	if (k == sf::Keyboard::Key::A)
		keyButtons.letters[0] = b;
	else if (k == sf::Keyboard::Key::B)
		keyButtons.letters[1] = b;
	else if (k == sf::Keyboard::Key::C)
		keyButtons.letters[2] = b;
	else if (k == sf::Keyboard::Key::D)
		keyButtons.letters[3] = b;
	else if (k == sf::Keyboard::Key::E)
		keyButtons.letters[4] = b;
	else if (k == sf::Keyboard::Key::F)
		keyButtons.letters[5] = b;
	else if (k == sf::Keyboard::Key::G)
		keyButtons.letters[6] = b;
	else if (k == sf::Keyboard::Key::H)
		keyButtons.letters[7] = b;
	else if (k == sf::Keyboard::Key::I)
		keyButtons.letters[8] = b;
	else if (k == sf::Keyboard::Key::J)
		keyButtons.letters[9] = b;
	else if (k == sf::Keyboard::Key::K)
		keyButtons.letters[10] = b;
	else if (k == sf::Keyboard::Key::L)
		keyButtons.letters[11] = b;
	else if (k == sf::Keyboard::Key::M)
		keyButtons.letters[12] = b;
	else if (k == sf::Keyboard::Key::N)
		keyButtons.letters[13] = b;
	else if (k == sf::Keyboard::Key::O)
		keyButtons.letters[14] = b;
	else if (k == sf::Keyboard::Key::P)
		keyButtons.letters[15] = b;
	else if (k == sf::Keyboard::Key::Q)
		keyButtons.letters[16] = b;
	else if (k == sf::Keyboard::Key::R)
		keyButtons.letters[17] = b;
	else if (k == sf::Keyboard::Key::S)
		keyButtons.letters[18] = b;
	else if (k == sf::Keyboard::Key::T)
		keyButtons.letters[19] = b;
	else if (k == sf::Keyboard::Key::U)
		keyButtons.letters[20] = b;
	else if (k == sf::Keyboard::Key::V)
		keyButtons.letters[21] = b;
	else if (k == sf::Keyboard::Key::W)
		keyButtons.letters[22] = b;
	else if (k == sf::Keyboard::Key::X)
		keyButtons.letters[23] = b;
	else if (k == sf::Keyboard::Key::Y)
		keyButtons.letters[24] = b;
	else if (k == sf::Keyboard::Key::Z)
		keyButtons.letters[25] = b;
	else if (k == sf::Keyboard::Key::Return)
		keyButtons.enter = b;
	else if (k == sf::Keyboard::Key::Space)
		keyButtons.space = b;
	else if (k == sf::Keyboard::Key::Escape)
		keyButtons.escape = b;
}	

void Client::setButtonPressed(std::string s, bool b)
{
	if (s == "left")
		mouseButtons.left = b;
	else if (s == "right")
		mouseButtons.right = b;
	else if (s == "middle")
		mouseButtons.middle = b;
	else if (s == "wheel")
		mouseButtons.wheel = b;
}

void Client::disconnect()
{
	socket.disconnect();
}	

bool Client::isInactive()
{
	return lastRecieved.getElapsedTime().asSeconds() > 20.0;
}	

bool Client::isDisconnected()
{
	return (isInactive() || socket.getRemotePort() == 0);
}	

bool Client::receive(sf::Packet & p)
{
	return socket.receive(p) == sf::Socket::Status::Done;
}	

void Client::setMousePosition(int x, int y)
{
	mousePosition_.x = x;
	mousePosition_.y = y;
}

sf::Vector2i Client::getMousePosition()
{
	return mousePosition_;
}	
