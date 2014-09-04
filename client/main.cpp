#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <TGUI/TGUI.hpp>
#include "PacketsOperator.cpp"

class GuiHandler
{
	private :
	
	tgui::Gui gui;
	
	public :

	void loadGameScreen()
	{
		gui.removeAllWidgets();
	}

	void login(const tgui::Callback & callback)
	{
		if (callback.id != 1)
			return;
	}

	void loadLoginScreen()
	{
		gui.loadWidgetsFromFile("widgetsConf/loadingScreen.txt");

		gui.get("loginButton")->bindCallbackEx(&GuiHandler::login, this, tgui::Button::LeftMouseClicked);
	}

	GuiHandler(sf::RenderWindow & w)
	{
		gui.setWindow(w);
		gui.setGlobalFont("fonts/arial.ttf");

		loadLoginScreen();
	}

	void draw()
	{
		gui.draw();
	}

	void handleEvent(sf::Event & e)
	{
		gui.handleEvent(e);
	}

};

int main()
{
	sf::TcpSocket socket;

	sf::RenderWindow window(sf::VideoMode(800, 600), "MMO");

	window.setPosition(sf::Vector2i(250, 250));

	GuiHandler guiHandler(window);

	socket.connect("localhost", 53000);

	sf::Packet p;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			p << std::string("event") << event;
			socket.send(p);

			if (event.type == sf::Event::Closed)
				window.close();

			guiHandler.handleEvent(event);

			p.clear();
		}

		window.clear();

		guiHandler.draw();

		window.display();
	}

	p << std::string("message") << std::string("shutdown"); 

	socket.send(p);

	socket.disconnect();

	return 0;
}

