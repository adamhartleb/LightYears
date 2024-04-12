#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/Application.h"
#include <iostream>
#include <memory>

std::unique_ptr<ly::Application> GetApplication()
{
	return std::make_unique<ly::GameApplication>();
}

namespace ly
{
	GameApplication::GameApplication()
	{
		auto new_world{ load_world<World>() };
	}

	GameApplication::~GameApplication()
	{
		std::cout << "I got called!!!" << std::endl;
	}
}

