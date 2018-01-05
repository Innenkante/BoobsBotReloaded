#pragma once
#include <windows.h>
#include "Vector.h"
#include "RefDef.h"

class Trace; //dirty luul
using CL_Trace = void(__cdecl*)(Trace*, float start[3], float end[3], int, DWORD mask);
CL_Trace Tracer = (CL_Trace)0x55A820;

class Trace
{
public:
	float fraction; //0x0000  
	float surfaceDirection[3];
	__int32 ID0367A628; //0x0010  
	char unknown20[8]; //0x0014
	__int32 hitType; //0x001C  
	WORD entityNum; //0x0020  
	char unknown34[6]; //0x0022
	BYTE allsolid; //0x0028  
	BYTE startsolid; //0x0029  
	BYTE ID0367A828; //0x002A  
	char unknown43[5]; //0x002B
	float endpos[3];
	BYTE ID0367AFA8; //0x003C  
	char unknown61[3]; //0x003D
	__int32 materialType; //0x0040 

	static Trace TraceToTarget(Vector3D target)
	{
		auto cg = CG::GetCG();
		auto refDef = RefDef::GetRefDef();

		Trace t;
		float start[] { refDef->Origin.X,refDef->Origin.Y,refDef->Origin.Z };
		float end[]{ target.X,target.Y,target.Z };

		Tracer(&t, start, end, cg->ClientNumber, 0x803003);

		return t;
	}
};
