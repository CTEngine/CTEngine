#pragma once

#ifdef CTE_PLATFORM_WINDOWS

extern CTEngine::Application* CTEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Chrono Tech Engine\n");
	auto app = CTEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif