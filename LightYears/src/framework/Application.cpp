#include "framework/Application.h"

ly::Application::Application() 
	: m_window{sf::VideoMode(1024, 1440), "Light Years"}
{
}

void ly::Application::Run()
{
	while (m_window.isOpen())
	{
		sf::Event window_event {};
		while (m_window.pollEvent(window_event))
		{
			if (window_event.type == sf::Event::EventType::Closed)
			{
				m_window.close();
			}
		}
	}
}
