#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/Application.h"
#include <iostream>
#include <memory>

std::shared_ptr<ly::Application> GetApplication()
{
	return std::make_shared<ly::GameApplication>();
}

namespace ly
{
	GameApplication::GameApplication()
	{
		auto new_world{ load_world<World>() };
	}
}

