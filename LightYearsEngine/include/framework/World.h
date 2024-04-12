#pragma once
#include "framework/Core.h"
#include "framework/Application.h"
#include <vector>
#include <memory>

namespace ly
{
	class Actor;
	class Application;
	class World
	{
	public:
		World(Application* owning_app);

		void begin_play_internal();
		void tick_internal(float delta_time);

		virtual ~World();

		void spawn_actor();

	private:
		void begin_play();
		void tick(float delta_time);
		Application* m_owning_app;
		bool m_begin_play;

		std::vector<Actor*> m_actors{};
		std::vector<Actor*> m_pending_actors{};
	};
}