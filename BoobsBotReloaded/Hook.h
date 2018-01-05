#pragma once
#include <functional>

namespace Hook
{
	namespace internal
	{
		std::function<void()> UiCallback;
		std::function<void()> FrameCallback;
		void* DetourFunction(BYTE * src, const BYTE * dst, const int len);
	}

	void InstallUICallback(std::function<void()> ui_callback);
	void InstallFrameCallback(std::function<void()> frame_callback);
}
