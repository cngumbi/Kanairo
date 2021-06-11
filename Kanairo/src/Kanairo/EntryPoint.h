#pragma once


#ifdef KN_PLATFORM_WINDOWS

//how to create/return a kanairo application
extern Kanairo::Application* Kanairo::CreateApplication();


int main(int argc, char* argv[])
{
	
	auto app = Kanairo::CreateApplication();
	app->Run();
	delete app;
}
#endif // KN_PLATFORM_WINDOWS
