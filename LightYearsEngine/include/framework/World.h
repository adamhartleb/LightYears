#pragma once
#include "framework/Core.h"
#include "framework/Application.h"

namespace ly
{
	class Application;
	class World
	{
	public:
		World(Application* owning_app);

		void begin_play_internal();
		void tick_internal(float delta_time);

		virtual ~World();
	private:
		void begin_play();
		void tick(float delta_time);
		shared<Application> m_owning_app;
		bool m_begin_play;
	};
}