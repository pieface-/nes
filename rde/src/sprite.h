#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
	
private:
	char * data;

public:
	Sprite();
	Sprite(char [16]);

	char *getData() { return data; }
	char *toString();
};

#endif
