#pragma once
// the core header file that has the macros
#include "Core.h"
namespace Kanairo {
	// include the macro to handle __declspec
	class KANAIRO_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	//To be defined in client
	Application* CreateApplication();

}