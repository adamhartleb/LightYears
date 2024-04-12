#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace ly {
	Application::Application()
		: m_window{ sf::VideoMode(1024, 1440), "Light Years" },
		m_target_frame_rate{ 60.f },
		m_tick_clock{},
		m_current_world{ nullptr }
	{
	}

	Application::~Application()
	{
		LOG("Why was i called?");
	}

	void Application::run()
	{
		m_tick_clock.restart();
		const auto delta_time{ 1.f / m_target_frame_rate };
		auto accumulated_time{ 0.f };


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

			accumulated_time += m_tick_clock.restart().asSeconds();
			while (accumulated_time > delta_time)
			{
				tick_internal(delta_time);
				accumulated_time -= delta_time;
			}

			render_internal();
		}
	}

	void Application::tick_internal(float delta_time)
	{
		tick(delta_time);

		if (m_current_world)
		{
			m_current_world->begin_play_internal();
			m_current_world->tick_internal(delta_time);
		}
	}

	// render_internal ensures the window is cleared/displayed. the render function is virtual so the client can render whatever they want.
	void Application::render_internal()
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

	void Application::tick(float delta_time)
	{
		/*LOG("ticking at frame rate: %f", 1.f / delta_time);*/
	}

	void Application::load_world()
	{
		m_current_world = new World{ this };
	}
}


