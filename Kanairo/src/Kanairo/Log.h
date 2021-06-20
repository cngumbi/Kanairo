#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kanairo {
	class KANAIRO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//the Log macros
//CORE
#define KN_CORE_TRACE(...)    ::Kanairo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KN_CORE_INFO(...)     ::Kanairo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KN_CORE_WARN(...)     ::Kanairo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KN_CORE_ERROR(...)    ::Kanairo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KN_CORE_FATAL(...)    ::Kanairo::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//CLIENT
#define KN_TRACE(...)         ::Kanairo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KN_INFO(...)          ::Kanairo::Log::GetClientLogger()->info(__VA_ARGS__)
#define KN_WARN(...)          ::Kanairo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KN_ERROR(...)         ::Kanairo::Log::GetClientLogger()->error(__VA_ARGS__)
#define KN_FATAL(...)         ::Kanairo::Log::GetClientLogger()->fatal(__VA_ARGS__)