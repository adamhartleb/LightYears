#include "EntryPoint.h"
#include "framework/Application.h"
#include <memory>

int main()
{
	auto app = GetApplication();
	app->run();
}