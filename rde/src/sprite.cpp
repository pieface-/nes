#include "sprite.h"

Sprite::Sprite()
{
	data = new char[64];	
}

Sprite::Sprite(char chr[16])
{
	data =  new char[64];
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		{
			char a =  (chr[0+i] & 1 << (7-j)) >> (7-j);
			char b = (chr[8+i] & 1 << (7-j)) >> (7-j);
			data[8*i+j] = a + 2*b;
		}
}

char * Sprite::toString()
{
	char *out = new char[72];
	for(int i = 0; i < 72; i++)
	{
		if(((i+1)%9==0)&&(i!=71))
			out[i] = '\n';
		else if(i==71)
			out[i] =  '\0';
		else
			out[i] = (char) 48 + data[i - (i/9)];
	}
	return out;
}
