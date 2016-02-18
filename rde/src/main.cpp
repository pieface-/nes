#include <iostream>
//#include <string>
#include <fstream>
#include <stdlib.h>
#include "util.h"
#include "rom.h"
#include "sprite.h"

int main (int argc, char *argv[])
{
	using namespace std;
	int spriteNum = 0;
	if(argc!=2 && argc!=3)
	{
		usage(argv[0]);
		return 0;
	}

	if(argc==3)
	{
		char* end = new char;
		spriteNum = strtol(argv[2], &end, 10);
//		printf("\"%s\"", argv[2]);
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
	pos += spriteNum*16;
	printf("The pos is at %d\n", pos);
	rom.seekg(pos);
	rom.read(spriteData, 16);	
	Sprite* s = new Sprite(spriteData);
	printf("%s\n", s->toString());
}

