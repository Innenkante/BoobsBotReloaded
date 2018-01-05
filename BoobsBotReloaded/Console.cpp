#include "stdafx.h"
#include <iostream>

void Console::Initialize()
{
	if (!AllocConsole())
		MessageBoxA(NULL, "", "Failed to initialize the console.", 0);

	SetConsoleTitleA("BoobsBotReloaded");
	freopen_s(&internal::InputFile, "CONIN$", "r", stdin);
	freopen_s(&internal::OutputFile, "CONOUT$", "w", stdout);
}

