#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct {
        char *id,*ocup,cj[16];
        int gs,*aa;
} T1;

typedef struct grup{
	T1 *a1, *a2;
	int nc, na;
	int *a3;
} T2, *AT2;

AT2 Aloc(int MP, int NA);

void Elib(AT2 *ag);

int Cit(FILE *f, T2 *ag);

void Afi(T2 *ag);
