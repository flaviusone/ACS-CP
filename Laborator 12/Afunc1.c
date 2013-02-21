#include"analize.h"


int Functie1(T2 *ag, char* annastere, char* ocupatie)
{

	char fname[30];
	FILE *f;
	printf("Introduceti numele fisierului de iesire: ");
	scanf("%s", fname);
	f = fopen(fname, "w");
	if (!f)
		return -1;
	T1 *aux;
	char sx[3] = "";



	char cnp[14]="";
	cnp[13]='\0';
	int nr = 0;
	for (aux = ag->a1; aux < ag->a1 + ag->nc; aux++){
		if(!strcmp(aux->ocup, ocupatie)){
			strncpy(sx,aux->cj+1,2);
			if(!strncmp(annastere, sx,2)){
				nr++;
				strncpy(cnp, aux->cj, 13);
				fprintf(f, "%2i. %s - %s [%i]\n", nr, aux->id, cnp, aux->gs);
			}
		}
	}
	return nr;
}

AT2 Aloc(int MP, int NA){
	T2 *ag;
	ag = (T2*)malloc(sizeof(T2));
	if (!ag)
		return NULL;

	ag->nc = 0;
	ag->na = NA;

	ag->a1 = (T1*)calloc(MP, sizeof(T1));
	ag->a2 = ag->a1 + MP;

	if(!ag->a1)
	{
		free(ag->a1);
		return NULL;
	}
	ag->a3 = (int*)calloc(MP * NA, sizeof(int));
	if(!ag->a3)
	{
		free(ag->a3);
		free(ag->a1);
		return NULL;
	}
	return ag;
}

void Elib(AT2 *ag)
{
	T1 *aux;
	for (aux = (*ag)->a1; aux < (*ag)->a1 + (*ag)->nc; aux++)
	{
		free(aux->id);
		free(aux->ocup);
		free(aux->aa);
		free(aux);
	}
	free((*ag)->a3);
	free((*ag)->a1);
	free(*ag);
	(*ag) = NULL;
}
int Cit(FILE *f, T2 *ag)
{
	T1 *p = ag->a1;
	int i, nc = 0;
	char numeprenume[20], cj[16], ocup[20];
	int gr;
	while(p != ag->a2 && fscanf(f, "%s%s%s",numeprenume, cj, ocup) == 3)
	{
		ag->nc++;

		p->id = (char*)calloc(strlen(numeprenume) + 1, sizeof(char));
		strcpy(p->id, numeprenume);
		strcpy(p->cj, cj);
		p->ocup = (char*)calloc(strlen(ocup) + 1, sizeof(char));
		strcpy(p->ocup, ocup);

		fscanf(f, "%d", &gr);
		p->gs = gr;

		p->aa = (int*)calloc(ag->na + 1, sizeof(int));
		for(i = 0; i < ag->na; i++){
			fscanf(f, "%d", &p->aa[i]);
			ag->a3[nc * ag->na + i] = p->aa[i];
		}
		p++;
		nc++;
	}
	return nc;
}

void Afi(T2 *ag)
{
	T1 *aux;
	int i;
	for (i = 0; i < ag->nc * ag->na; i++)
	{
		if (i % ag->na == 0)
			printf("\n");
		printf("%4d ", ag->a3[i]);
	}
	printf("\n\n");
	for (aux = ag->a1; aux < ag->a1 + ag->nc; aux++)
	{
		printf("%-25s %s %-10s %2i | ", aux->id, aux->cj, aux->ocup, aux->gs);
		for(i = 0; i < ag->na; i++)
			printf("%4d ", aux->aa[i]);
		printf("\n");
	}
}

