#include "PacketsOperator.hpp"

sf::Packet & operator <<(sf::Packet & packet, const sf::Mouse::Button & button)
{
	if (button == sf::Mouse::Button::Left)
	{
		packet << sf::Int8(0);
	}	
	else if (button == sf::Mouse::Button::Right)
	{
		packet << sf::Int8(1);
	}
	else if (button == sf::Mouse::Button::Middle)
	{
		packet << sf::Int8(2);
	}
	else
	{
		packet << sf::Int8(-1);
	}	
	
	return packet;
}

sf::Packet & operator >>(sf::Packet & packet, sf::Mouse::Button & button)
{
	sf::Int8 code;

	packet >> code;

	if (code == 0)
	{
		button = sf::Mouse::Button::Left;
	}	
	else if (code == 1)
	{
		button = sf::Mouse::Button::Right;
	}	
	else if (code == 2)
	{
		button = sf::Mouse::Button::Middle;
	}
	else
	{
		button = sf::Mouse::Button::ButtonCount;
	}
	
	return packet;
}	

sf::Packet & operator <<(sf::Packet & packet, const sf::Keyboard::Key & key)
{
	if (key == sf::Keyboard::Key::A)
	{
		packet << sf::Int8(0);
	}	
	else if (key == sf::Keyboard::Key::B)
	{
		packet << sf::Int8(1);
	}
	else if (key == sf::Keyboard::Key::C)
	{
		packet << sf::Int8(2);
	}
	else if (key == sf::Keyboard::Key::D)
	{
		packet << sf::Int8(3);
	}
	else if (key == sf::Keyboard::Key::E)
	{
		packet << sf::Int8(4);
	}
	else if (key == sf::Keyboard::Key::F)
	{
		packet << sf::Int8(5);
	}
	else if (key == sf::Keyboard::Key::G)
	{
		packet << sf::Int8(6);
	}
	else if (key == sf::Keyboard::Key::H)
	{
		packet << sf::Int8(7);
	}
	else if (key == sf::Keyboard::Key::I)
	{
		packet << sf::Int8(8);
	}
	else if (key == sf::Keyboard::Key::J)
	{
		packet << sf::Int8(9);
	}
	else if (key == sf::Keyboard::Key::K)
	{
		packet << sf::Int8(10);
	}
	else if (key == sf::Keyboard::Key::L)
	{
		packet << sf::Int8(11);
	}
	else if (key == sf::Keyboard::Key::M)
	{
		packet << sf::Int8(12);
	}
	else if (key == sf::Keyboard::Key::N)
	{
		packet << sf::Int8(13);
	}
	else if (key == sf::Keyboard::Key::O)
	{
		packet << sf::Int8(14);
	}
	else if (key == sf::Keyboard::Key::P)
	{
		packet << sf::Int8(15);
	}
	else if (key == sf::Keyboard::Key::Q)
	{
		packet << sf::Int8(16);
	}
	else if (key == sf::Keyboard::Key::R)
	{
		packet << sf::Int8(17);
	}
	else if (key == sf::Keyboard::Key::S)
	{
		packet << sf::Int8(18);
	}
	else if (key == sf::Keyboard::Key::T)
	{
		packet << sf::Int8(19);
	}
	else if (key == sf::Keyboard::Key::U)
	{
		packet << sf::Int8(20);
	}
	else if (key == sf::Keyboard::Key::V)
	{
		packet << sf::Int8(21);
	}
	else if (key == sf::Keyboard::Key::W)
	{
		packet << sf::Int8(22);
	}
	else if (key == sf::Keyboard::Key::X)
	{
		packet << sf::Int8(23);
	}
	else if (key == sf::Keyboard::Key::Y)
	{
		packet << sf::Int8(24);
	}
	else if (key == sf::Keyboard::Key::Z)
	{
		packet << sf::Int8(25);
	}
	else if (key == sf::Keyboard::Key::Space)
	{
		packet << sf::Int8(26);
	}
	else if (key == sf::Keyboard::Key::Return)
	{
		packet << sf::Int8(27);
	}
	else if (key == sf::Keyboard::Key::Escape)
	{
		packet << sf::Int8(28);
	}
	else
	{
		packet << sf::Int8(-1);
	}
	
	return packet;
}

sf::Packet & operator >>(sf::Packet & packet, sf::Keyboard::Key & key)
{
	sf::Int8 code;

	packet >> code;

	if (code == -1)
	{
		key = sf::Keyboard::Key::Unknown;
	}
	else if (code == 0)
	{
		key = sf::Keyboard::Key::A;
	}
	else if (code == 1)
	{
		key = sf::Keyboard::Key::B;
	}
	else if (code == 2)
	{
		key = sf::Keyboard::Key::C;
	}
	else if (code == 3)
	{
		key = sf::Keyboard::Key::D;
	}
	else if (code == 4)
	{
		key = sf::Keyboard::Key::E;
	}
	else if (code == 5)
	{
		key = sf::Keyboard::Key::F;
	}
	else if (code == 6)
	{
		key = sf::Keyboard::Key::G;
	}
	else if (code == 7)
	{
		key = sf::Keyboard::Key::H;
	}
	else if (code == 8)
	{
		key = sf::Keyboard::Key::I;
	}
	else if (code == 9)
	{
		key = sf::Keyboard::Key::J;
	}
	else if (code == 10)
	{
		key = sf::Keyboard::Key::K;
	}
	else if (code == 11)
	{
		key = sf::Keyboard::Key::L;
	}
	else if (code == 12)
	{
		key = sf::Keyboard::Key::M;
	}
	else if (code == 13)
	{
		key = sf::Keyboard::Key::N;
	}
	else if (code == 14)
	{
		key = sf::Keyboard::Key::O;
	}
	else if (code == 15)
	{
		key = sf::Keyboard::Key::P;
	}
	else if (code == 16)
	{
		key = sf::Keyboard::Key::Q;
	}
	else if (code == 17)
	{
		key = sf::Keyboard::Key::R;
	}
	else if (code == 18)
	{
		key = sf::Keyboard::Key::S;
	}
	else if (code == 19)
	{
		key = sf::Keyboard::Key::T;
	}
	else if (code == 20)
	{
		key = sf::Keyboard::Key::U;
	}
	else if (code == 21)
	{
		key = sf::Keyboard::Key::V;
	}
	else if (code == 22)
	{
		key = sf::Keyboard::Key::W;
	}
	else if (code == 23)
	{
		key = sf::Keyboard::Key::X;
	}
	else if (code == 24)
	{
		key = sf::Keyboard::Key::Y;
	}
	else if (code == 25)
	{
		key = sf::Keyboard::Key::Z;
	}
	else if (code == 26)
	{
		key = sf::Keyboard::Key::Space;
	}
	else if (code == 27)
	{
		key = sf::Keyboard::Key::Return;
	}
	else if (code == 28)
	{
		key = sf::Keyboard::Key::Escape;
	}
	else
	{
		key = sf::Keyboard::Key::Unknown;
	}	
	
	return packet;
}

sf::Packet & operator <<(sf::Packet & packet, const sf::Event & event)
{
	if (event.type == sf::Event::EventType::Closed)
	{
		packet << sf::Int8(0);
	}	
	else if (event.type == sf::Event::EventType::Resized)
	{
		packet << sf::Int8(1);
		packet << event.size.width;
		packet << event.size.height;
	}
	else if (event.type == sf::Event::EventType::LostFocus)
	{
		packet << sf::Int8(2);
	}
	else if (event.type == sf::Event::EventType::GainedFocus)
	{
		packet << sf::Int8(3);
	}
	else if (event.type == sf::Event::EventType::TextEntered)
	{
		packet << sf::Int8(4);
		packet << event.text.unicode;
	}
	else if (event.type == sf::Event::EventType::KeyPressed)
	{
		packet << sf::Int8(5);
		packet << event.key.code;
		packet << event.key.alt;
		packet << event.key.control;
		packet << event.key.shift;
		packet << event.key.system;
	}	
	else if (event.type == sf::Event::EventType::KeyReleased)
	{
		packet << sf::Int8(6);
		packet << event.key.code;
		packet << event.key.alt;
		packet << event.key.control;
		packet << event.key.shift;
		packet << event.key.system;
	}
	else if (event.type == sf::Event::EventType::MouseWheelMoved)
	{
		packet << sf::Int8(7);
		packet << event.mouseWheel.delta << event.mouseWheel.x << event.mouseWheel.y;
	}
	else if (event.type == sf::Event::EventType::MouseButtonPressed)
	{
		packet << sf::Int8(8);
		packet << event.mouseButton.button << event.mouseButton.x << event.mouseButton.y;
	}	
	else if (event.type == sf::Event::EventType::MouseButtonReleased)
	{
		packet << sf::Int8(9);
		packet << event.mouseButton.button << event.mouseButton.x << event.mouseButton.y;
	}
	else if (event.type == sf::Event::EventType::MouseMoved)
	{
		packet << sf::Int8(10);
		packet << event.mouseMove.x;
		packet << event.mouseMove.y;
	}
	else if (event.type == sf::Event::EventType::MouseEntered)
	{
		packet << sf::Int8(11);
	}	
	else if (event.type == sf::Event::EventType::MouseLeft)
	{
		packet << sf::Int8(12);
	}
	else if (event.type == sf::Event::EventType::JoystickButtonPressed)
	{
		packet << sf::Int8(13);
		packet << event.joystickButton.joystickId << event.joystickButton.button;
	}	

	else if (event.type == sf::Event::EventType::JoystickButtonReleased)
	{
		packet << sf::Int8(14);
		packet << event.joystickButton.joystickId << event.joystickButton.button;
	}	

	else if (event.type == sf::Event::EventType::JoystickMoved)
	{
		packet << sf::Int8(15);
		packet << event.joystickMove.joystickId << event.joystickMove.axis << event.joystickMove.position;
	}
	else if (event.type == sf::Event::EventType::JoystickConnected)
	{
		packet << sf::Int8(16);
		packet << event.joystickConnect.joystickId;
	}
	else if (event.type == sf::Event::EventType::JoystickDisconnected)
	{
		packet << sf::Int8(17);
		packet << event.joystickConnect.joystickId;
	}
	else 
	{
		packet << sf::Int8(18);
	}	

	return packet;
}

sf::Packet & operator >>(sf::Packet & packet, sf::Event & event)
{
	sf::Int8 code;

	packet >> code;

	if (code == 0)
	{
		event.type = sf::Event::EventType::Closed;
	}
	else if (code == 1)
	{
		event.type = sf::Event::EventType::Resized;
		packet >> event.size.width >> event.size.height;
	}
	else if (code == 2)
	{
		event.type = sf::Event::EventType::LostFocus;
	}
	else if (code == 3)
	{
		event.type = sf::Event::EventType::GainedFocus;
	}
	else if (code == 4)
	{
		event.type = sf::Event::EventType::TextEntered;
		packet >> event.text.unicode;
	}
	else if (code == 5)
	{
		event.type = sf::Event::EventType::KeyPressed;
		packet >> event.key.code >>event.key.alt >> event.key.control >> event.key.shift >> event.key.system;
	}
	else if (code == 6)
	{
		event.type = sf::Event::EventType::KeyReleased;
		packet >> event.key.code  >>event.key.alt >> event.key.control >> event.key.shift >> event.key.system;
	}
	else if (code == 7)
	{
		event.type = sf::Event::EventType::MouseWheelMoved;
		packet >> event.mouseWheel.delta >> event.mouseWheel.x >> event.mouseWheel.y;
	}
	else if (code == 8)
	{
		event.type = sf::Event::EventType::MouseButtonPressed;
		packet >> event.mouseButton.button >> event.mouseButton.x >> event.mouseButton.y;
	}
	else if (code == 9)
	{
		event.type = sf::Event::EventType::MouseButtonReleased;
		packet >> event.mouseButton.button >> event.mouseButton.x >> event.mouseButton.y;
	}
	else if (code == 10)
	{
		event.type = sf::Event::EventType::MouseMoved;
		packet >> event.mouseMove.x >> event.mouseMove.y;
	}	
	else if (code == 11)
	{
		event.type = sf::Event::EventType::MouseEntered;
	}
	else if (code == 12)
	{
		event.type = sf::Event::EventType::MouseLeft;
	}	
	else
	{
		event.type = sf::Event::Count;
	}	

	return packet;
}	
