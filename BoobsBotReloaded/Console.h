#pragma once
#include <iostream>

namespace Console
{
	namespace internal
	{
		static FILE* InputFile;
		static FILE* OutputFile;
	}

	void Initialize();
	template <typename T> void Log(T content)
	{
		std::cout << content << std::endl;
	}

	template <typename T> T Get()
	{
		T x = nullptr;
		std::cin >> x;
		return x;
	}
}
