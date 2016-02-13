#include <cstdio>
#include "rom.h"

bool checkHeader(char *header)
{
	return header[0] == 'N' && header[1] == 'E'
		&& header[2] == 'S' && header[3] == 0x1a;
}

int getPrgBanks(char *header)
{
	return header[4];
}

int getChrBanks(char *header)
{
	return header[5];
}

long setPos(char *header, int bankType, int bankNum)
{
	if( (bankType == PRG_BANK && bankNum > getPrgBanks(header)) 
			|| (bankType == CHR_BANK && bankNum > getChrBanks(header))
			|| ( bankType != CHR_BANK && bankType != PRG_BANK) )
		return 0;
	
	if(bankType == PRG_BANK)
		return 16l + PRG_SIZE * bankNum;
	else if(bankType == CHR_BANK)
		return 16l + PRG_SIZE * getPrgBanks(header) + CHR_SIZE * bankNum;
	return 0;
}
