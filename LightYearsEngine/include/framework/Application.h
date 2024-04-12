#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	class World;
	class Application
	{
	public:
		Application();
		~Application();
		void run();
		void load_world();
	private:
		void tick_internal(float delta_time);
		void render_internal();
		virtual void render();
		virtual void tick(float delta_time);

		const float m_target_frame_rate;
		sf::RenderWindow m_window;
		sf::Clock m_tick_clock;

		World* m_current_world;
	};
}