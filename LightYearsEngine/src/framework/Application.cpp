#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

ly::Application::Application() 
	: m_window{sf::VideoMode(1024, 1440), "Light Years"},
	m_target_frame_rate{60.f},
	m_tick_clock{},
	m_current_world{nullptr}
{
}

void ly::Application::run()												
{
	m_tick_clock.restart();
	const float delta_time{ 1.f / m_target_frame_rate };
	float accumulated_time{ 0.f };


	while (m_window.isOpen())
	{
		sf::Event window_event {};
		while (m_window.pollEvent(window_event))
		{
			switch (window_event.type)
			{
			case sf::Event::EventType::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (window_event.key.scancode == sf::Keyboard::Scan::Escape)
				{
					m_window.close();
					break;
				}
			}
		}

		accumulated_time += m_tick_clock.restart().asSeconds();
		while (accumulated_time > delta_time)
		{
			tick_internal(delta_time);
			accumulated_time -= delta_time;
		}

		render_internal();
	}
}

void ly::Application::tick_internal(float delta_time)
{
	tick(delta_time);

	if (m_current_world)
	{
		m_current_world->begin_play_internal();
		m_current_world->tick_internal(delta_time);
	}
}

// render_internal ensures the window is cleared/displayed. the render function is virtual so the client can render whatever they want.
void ly::Application::render_internal()
{
	m_window.clear();

	render();

	m_window.display();
}

void ly::Application::render()
{
	sf::RectangleShape rect{ sf::Vector2f(100.f, 100.f) };
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);
	rect.setOrigin(50.f, 50.f);
	m_window.draw(rect);
}

void ly::Application::tick(float delta_time)
{
	LOG("ticking at frame rate: %f", 1.f / delta_time);
}
