#include "framework/World.h"
#include "framework/Core.h"

namespace ly
{
	World::World(Application* owning_app) 
		: m_owning_app{ owning_app }, m_begin_play{false}
	{	
	}
	void World::begin_play_internal()
	{
		if (!m_begin_play)
		{
			m_begin_play = true;
			begin_play();
		}
	}
	void World::tick_internal(float delta_time)
	{
		tick(delta_time);
	}
	void World::begin_play()
	{
		LOG("began play");
	}
	void World::tick(float delta_time)
	{
		LOG("tick at frame rate %f", 1.f / delta_time);
	}

	World::~World()
	{

	}
}