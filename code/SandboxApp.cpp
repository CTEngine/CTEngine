#include <CTEngine.h>

class Sandbox : public CTEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

CTEngine::Application* CTEngine::CreateApplication()
{
	return new Sandbox();
}