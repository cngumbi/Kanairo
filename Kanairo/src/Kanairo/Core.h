#pragma once
//create a macro kanairo to handle __declspec import and export
//KN IS KANAIRO

#ifdef KN_PLATFORM_WINDOWS
	#ifdef KN_BUILD_DLL
		#define KANAIRO_API __declspec(dllexport)
	#else
		#define KANAIRO_API __declspec(dllimport)
	#endif // KN_BUILD_DLL
#else
	#error Kanairo only support Windows!
#endif // KN_PLATFORM_WINDOWS

