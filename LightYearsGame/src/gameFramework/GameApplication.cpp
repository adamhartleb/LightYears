#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/Application.h"
#include "framework/World.h"
#include <memory>

std::unique_ptr<ly::Application> GetApplication()
{
	return std::make_unique<ly::Application>();
}

ly::GameApplication::GameApplication()
{
	ly::Application::load_world<World>();
}
