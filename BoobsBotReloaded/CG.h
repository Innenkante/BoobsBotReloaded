#pragma once
class CG
{
public:
	int ServerTime;
	int PlayerState;
	int StaminaTimer;
	unsigned short PlayerStance;
	char _0x000E[0x2];
	int IsIngame;
	char _0x0014[0x4];
	int iVelocity;
	float Origin[3];
	float Velocity[3];
	char _0x0034[0x2C];
	float RefViewAngleY;
	float RefViewAngleX;
	char _0x0068[0xE8];
	int ClientNumber;
	char _0x0154[0x4];
	float ViewAngleY;
	float ViewAngleX;
	char _0x0160[0x3C];
	int Health;
	char _0x01A0[0x1C];
	int MaxEntities;
	char _0x01C0[0x44];
	int AdvancedUAV;

	static CG* GetCG()
	{
		return (CG*)0x008FF100;
	}
};