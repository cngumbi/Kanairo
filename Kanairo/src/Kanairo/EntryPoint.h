#pragma once


#ifdef KN_PLATFORM_WINDOWS

//how to create/return a kanairo application
extern Kanairo::Application* Kanairo::CreateApplication();


int main(int argc, char* argv[])
{
	//the logging system
	Kanairo::Log::Init();
	KN_CORE_WARN("Initialized Log!");
	int b = 10;
	KN_INFO("Welcome Var={0}" ,b);
	auto app = Kanairo::CreateApplication();
	app->Run();
	delete app;
}
#endif // KN_PLATFORM_WINDOWS
