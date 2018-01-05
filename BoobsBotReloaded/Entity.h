#pragma once
#include "Vector.h"
enum EntityType : short
{
	General = 0,
	Player = 1,
	Player_Corpse = 2,
	Item = 3,
	Explosive = 4,
	Invisible = 5,
	ScriptMover = 6,
	Sound = 7,
	FX = 8,
	Loop_FX = 9,
	Primary_Light = 10,
	Turret = 11,
	Helicopter = 12,
	Plane = 13,
	Vehicle = 14,
	Vehicle_Map = 15,
	Vechicle_Corpse = 16,
	Vechicle_Spawner = 17
};

class Entity
{
	char _0x0000[0x2];
	short Valid;
	char _0x0004[0x10];
	Vector3D Origin;
	Vector3D Angles;
	char _0x002C[0x3C];
	int Flags;
	char _0x006C[0xC];
	Vector3D OldOrigin;
	char _0x0084[0x18];
	Vector3D OldAngles;
	char _0x00A8[0x28];
	int ClientNumber;
	EntityType Type;
	char _0x00D6[0x12];
	Vector3D NewOrigin;
	char _0x00F4[0x1C];
	Vector3D NewAngles;
	char _0x011C[0x7C];
	BYTE WeaponID;
	char _0x0199[0x37];
	int Alive;
	char _0x01D4[0x24];

	static Entity* GetEntity(int id);
	static std::vector<Entity*> GetEntities(int range);

	bool IsAlive();
};

