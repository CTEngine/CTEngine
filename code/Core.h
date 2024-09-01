#pragma once

#ifdef CTE_PLATFORM_WINDOWS
	#ifdef CTE_BUILD_DLL
		#define CTEngine_API __declspec(dllexport)
	#else
		#define CTEngine_API __declspec(dllimport)
	#endif
#else
	#error CTEngine only supports Windows!
#endif

	