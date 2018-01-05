#pragma once
class CGS
{
public:
	char _0x0000[0x8];
	int Width;
	int Height;
	char _0x0010[0x14];
	char GameType[4];
	char _0x0028[0x1C];
	char HostName[64];
	char _0x0084[0xC4];
	int MaxClients;
	char _0x014C[0x4];
	char MapName[64];
	char _0x0190[0x43F0];

	static CGS* GetCGS()
	{
		return (CGS*)0x008FABA0;
	}

	bool IsFFA()
	{
		if (strstr(GameType, "dm") || strstr(GameType, "gun"))
			return true;
	}
};