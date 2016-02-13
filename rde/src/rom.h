#ifndef ROM_H
#define ROM_H

#define PRG_BANK 0
#define CHR_BANK 1
#define PRG_SIZE 16384l
#define CHR_SIZE 8192l

bool checkHeader(char *);
int getPrgBanks(char *);
int getChrBanks(char *);
char *getSprite(char *);
long setPos(char *, int, int);

#endif
