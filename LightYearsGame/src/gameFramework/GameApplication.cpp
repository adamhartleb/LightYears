#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/Application.h"
#include "framework/World.h"
#include <memory>

ly::unique<ly::Application> GetApplication()
{
	return std::make_unique<ly::GameApplication>();
}

ly::GameApplication::GameApplication()
{
	ly::Application::load_world<World>();
}
