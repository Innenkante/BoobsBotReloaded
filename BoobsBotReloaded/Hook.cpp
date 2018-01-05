#include "stdafx.h"
#include "Hook.h"

void * Hook::internal::DetourFunction(BYTE * src, const BYTE * dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len + 5);
	DWORD dwBack;

	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &dwBack);
	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
	for (int i = 5; i<len; i++)
		src[i] = 0x90;
	VirtualProtect(src, len, dwBack, &dwBack);
	return (jmp - len);
}



DWORD HkUiCall = 0x00475CE0;
DWORD HkUiJmp = 0x00644280;

__declspec(naked) void HkUi()
{
	__asm
	{
		CALL[HkUiCall]
		PUSHAD;
		PUSHFD;
	}
	Hook::internal::UiCallback();
	__asm
	{
		POPFD;
		POPAD;
		JMP[HkUiJmp]
	}
}

DWORD HkFrameJmp = 0x430436;
__declspec(naked) void HkFrame()
{
	__asm PUSHAD
	__asm PUSHFD
	Hook::internal::FrameCallback();
	__asm POPFD
	__asm POPAD

	__asm PUSH ESI
	__asm MOV ESI, [ESP + 8]
		__asm PUSH ESI

	__asm JMP[HkFrameJmp]
}


void Hook::InstallUICallback(std::function<void()> ui_callback)
{
	internal::UiCallback = ui_callback;
	internal::DetourFunction((BYTE*)0x0064427B, (BYTE*)HkUi, 5);
}

void Hook::InstallFrameCallback(std::function<void()> frame_callback)
{
	internal::FrameCallback = frame_callback;
	internal::DetourFunction((BYTE*)0x430430, (BYTE*)HkFrame, 6);
}
