/*-- AA.c --*/
#include "analize.h"
int Ord(const void* a, const void* b)
{
	int r = strncmp( ((T1*)b)->cj+13, ((T1*)a)->cj+13, 2 );
	if (!r)
		r = strncmp( ((T1*)a)->cj+2, ((T1*)b)->cj+2, 2 );
	if(!r)
		r = ((T1*)b)->gs - ((T1*)a)->gs;              
	return r;

}
int main()
{ T2 *ag;
	T1 *aux;
	FILE*f;
	char id[61],ocupatie[50],annastere[3];
	int na;

	printf("Nume fisier: ", id);
	fflush(stdin); gets(id);


	f = fopen(id, "rt");
	if (!f) { printf("Eroare deschidere fisier %s\n", id); getch(); return -1; }
	fscanf(f, "%i", &na); /* citeste numar analize */
	ag = Aloc(20, na);
	if(!ag){ printf("Eroare alocare"); getch(); return -2; }
	ag->nc = Cit(f, ag);
	fclose(f);
	if (ag->nc == 0){ printf("Fisier vid!!!\n"); getch(); return -3;}
	printf("%i persoane\n", ag->nc);
	Afi(ag);
	qsort(ag->a1, ag->nc, sizeof(T1), Ord);

	annastere[2]='\0';
	printf("\nIntroduceti anul nasterii:");
	scanf("%s",annastere);
	printf("Introduceti ocupatia:");
	scanf("%s",ocupatie);
	int nr;


	nr = Functie1(ag,annastere,ocupatie);
	if (nr<0) printf("Eroare");
	else printf("s-au scris %i linii",nr);





	/*  printf("\n Dupa sortare \n\n");
	    for(aux = ag->a1; aux < ag->a1 + ag->nc; aux++){
	    printf("%c%c: %s  %c%c,%i \n",aux->cj[13],aux->cj[14], aux->id ,aux->cj[2],aux->cj[3], aux->gs);

	    } printez dupa sortare cu functia afi */

	// Elib(&ag);
	printf("\nSfarsit program\n");
	getch();
}
