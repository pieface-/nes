#include <iostream>
//#include <string>
#include <fstream>
#include "util.h"
#include "rom.h"
#include "sprite.h"

int main (int argc, char *argv[])
{
	using namespace std;

	if(argc!=2)
	{
		usage(argv[0]);
		return 0;
	}

	ifstream rom(argv[1], ios::in | ios::binary);

	if(!rom)
	{
		printf("Error: rom file %s not found\n", argv[1]);
		usage(argv[0]);		
		return 0;
	}

	unsigned long int pos;
	char header[16];
	char spriteData[16]; 	

	rom.read(header, 16);
	if(!checkHeader(header))
	{
		printf("Error: file %s is not a valid nes rom\n", argv[1]);
		return 0;
	}
	printf("%s is a valid rom\n", argv[1]);
	printf("%s has %d PRG banks and %d CHR banks\n", argv[1], getPrgBanks(header), getChrBanks(header));
	pos = setPos(header, CHR_BANK, 0);
	pos += 0*16;
	printf("The pos is at %d\n", pos);
	rom.seekg(pos);
	rom.read(spriteData, 16);	
	Sprite* s = new Sprite(spriteData);
	printf("%s\n", s->toString());
}

