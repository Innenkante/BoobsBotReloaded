#include "stdafx.h"
#include "Misc.h"

void Misc::NoRecoil(bool enabled)
{
	if (enabled)
		*(int*)0x54F8DD = 235;
	else
		*(int*)0x54F8DD = 116;
}
