#include <cstdio>

bool checkHeader(char *header)
{
	return header[0] == 'N' && header[1] == 'E'
		&& header[2] == 'S' && header[3] == 0x1a;
}
