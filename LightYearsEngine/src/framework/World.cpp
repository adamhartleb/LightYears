#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"
#include "framework/Application.h"

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
		for (auto actor : m_pending_actors)
		{
			m_actors.push_back(actor);
			actor->begin_play_internal();
		}

		for (auto actor : m_actors)
		{
			actor->tick(delta_time);
		}

		m_pending_actors.clear();

		tick(delta_time);
	}
	void World::begin_play()
	{
		LOG("began play");
	}
	void World::tick(float delta_time)
	{
		//LOG("tick at frame rate %f", 1.f / delta_time);
	}

	void World::spawn_actor()
	{
		auto new_actor = new Actor{ this };
		m_pending_actors.push_back(new_actor);
	}

	World::~World()
	{
	}
}