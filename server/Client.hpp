#ifndef CLIENT
#define CLIENT

struct MouseButtons
{
	bool left;
	bool right;
	bool middle;
	bool wheel;

	void init()
	{
		left = right = middle = wheel = false;
	}
};	

struct KeyButtons
{
	bool letters[26];
	bool enter;
	bool space;
	bool escape;

	void init()
	{
		enter = space = escape = false;

		for (unsigned int i = 0; i < 26; i++)
			letters[i] = false;
	}
};

class Client
{
	public :

	sf::TcpSocket socket;

	private :

	MouseButtons mouseButtons;
	KeyButtons keyButtons;
	sf::Clock lastRecieved;
	sf::Vector2i mousePosition_;

	public :

	Client();	
	~Client();
	void init();
	bool isButtonPressed(std::string);
	bool isKeyPressed(std::string);
	void setButtonPressed(std::string, bool);
	void setButtonPressed(sf::Mouse::Button, bool);
	void setKeyPressed(std::string, bool);
	void setKeyPressed(sf::Keyboard::Key, bool);
	void disconnect();
	bool isInactive();
	bool isDisconnected();
	bool receive(sf::Packet &);
	void setMousePosition(int, int);
	sf::Vector2i getMousePosition();
};	

#endif
