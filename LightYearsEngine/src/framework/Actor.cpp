#include "framework/Actor.h"
#include "framework/Core.h"
#include <memory>

namespace ly
{
	Actor::Actor(std::shared_ptr<World> owning_world)
		: m_owning_world { owning_world }, m_begun_play { false }
	{
	}
	void Actor::begin_play_internal()
	{
		if (!m_begun_play)
		{
			m_begun_play = true;
			begin_play();
		}
	}

	void Actor::begin_play()
	{
		LOG("Actor began play");
	}

	void Actor::tick(float delta_time)
	{
		LOG("Actor ticking");
	}
}