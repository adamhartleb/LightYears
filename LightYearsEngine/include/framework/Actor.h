#pragma once
#include <memory>

namespace ly
{
	class World;
	class Actor
	{
	public:
		Actor(std::shared_ptr<World> owning_world);

		void begin_play_internal();
		virtual void begin_play();
		virtual void tick(float delta_time);
	private:
		bool m_begun_play;
		std::shared_ptr<World> m_owning_world;
	};
}