#pragma once
#include "Vector.h"
class RefDef
{
public:
	char _0x0000[0x8];
	int Width;
	int Height;
	int FovX;
	int FovY;
	Vector3D Origin;
	Vector3D ViewAxis[3];
	char _0x0048[0x24];
	float ZoomProgress;
	char _0x0070[0x4ABC];
	Vector3D ViewAngles;
	char _0x4B34[0x30];
	float WeaponViewAngleX;
	float WeaponViewAngleY;

	static RefDef* GetRefDef()
	{
		return (RefDef*)0x0096A280;
	}
};