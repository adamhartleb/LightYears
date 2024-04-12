#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/World.h"
#include <memory>

namespace ly
{
	class World;
	class Application
	{
	public:
		Application();
		~Application();
		void run();

		template<typename world_type>
		std::weak_ptr<world_type> load_world();
	private:
		void tick_internal(float delta_time);
		void render_internal();
		virtual void render();
		virtual void tick(float delta_time);

		const float m_target_frame_rate;
		sf::RenderWindow m_window;
		sf::Clock m_tick_clock;

		std::shared_ptr<World> m_current_world;
	};
	template<typename world_type>
	std::weak_ptr<world_type> Application::load_world()
	{
		auto new_world{ std::make_shared<world_type>(this) };
		m_current_world = new_world;
		return new_world;
	}
}