#pragma once
class Client
{
public:
	int ClientNumber; //0x0000 
	int Valid; //0x0004 
	char _0x0008[4];
	char Name[16]; //0x000C 
	int Team; //0x001C 
	int Team_2; //0x0020 
	int Rank; //0x0024 
	char _0x0028[16];
	int Perk; //0x0038 
	char _0x003C[8];
	int Score; //0x0044 
	char _0x0048[8];
	char BodyName[32]; //0x0050 
	char _0x0070[32];
	char HeadName[32]; //0x0090 
	char _0x00B0[992];
	BYTE IsStanding; //0x0490 
	BYTE IsWalking; //0x0491 
	BYTE IsSprinting; //0x0492 
	char _0x0493[13];
	int IsAttacking; //0x04A0 
	char _0x04A4[4];
	int IsZooming; //0x04A8 
	char _0x04AC[68];
	int WeaponNumber1; //0x04F0 
	char _0x04F4[24];
	int WeaponNumber2; //0x050C 
	char _0x0510[80];

	static Client* GetClient(int id);
	static std::vector<Client*> GetClients(int range);
};