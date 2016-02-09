#include <cstdio>

bool checkHeader(char *header)
{
	return header[0] == 'N' && header[1] == 'E'
		&& header[2] == 'S' && header[3] == 0x1a;
}

int getPrgBanks(char *header)
{
	return header[4];
}

int getPrgBanks(char *header)
{
	return header[5];
}
