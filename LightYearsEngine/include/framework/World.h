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

		template<typename actor_type>
		std::weak_ptr<actor_type> spawn_actor();

	private:
		void begin_play();
		void tick(float delta_time);
		Application* m_owning_app;
		bool m_begin_play;

		std::vector<std::shared_ptr<Actor>> m_actors;
		std::vector<std::shared_ptr<Actor>> m_pending_actors;
	};

	template<typename ActorType>
	std::weak_ptr<ActorType> World::spawn_actor()
	{
		auto new_actor{ std::make_shared<ActorType>(this) };
		m_pending_actors.push_back(new_actor);
		return new_actor;
	}
}