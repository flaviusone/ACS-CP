/*-- grupa.c --*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 32    /* numar maxim studenti in grupa */

typedef struct
{ char nume[21], prenume[21];
	int note[15];
} TStud;
typedef struct
{ int nrnote, nrstud;
	TStud std[MAXS];
} TGrupa;

int CitStud(FILE* fs, TGrupa *ag)
	/* citeste din fisierul sursa fs, presupus corect,
	   nume, prenume si note studenti */
{ int i = 0, *p, *s; /* nr.studenti cititi, adrese note */

	while (i < MAXS &&
			fscanf(fs, "%s%s", ag->std[i].nume, ag->std[i].prenume) == 2)
	{ p = ag->std[i].note;
		s = p + ag->nrnote;
		while (p < s)
		{ fscanf(fs, "%i", p);
			p++;
		}
		i++;
	} 
	return i;
}

void TabelStud(TGrupa *ag)
	/* afiseaza studentii si notele lor */
{ TStud *as, *xs; /* adresa student, limita sup.as */
	int *p, *s;     /* adresa nota, limita sup.p */
	xs = ag->std + ag->nrstud;
	for (as = ag->std; as < xs; as++)
	{ printf("%2i. %s %-*s|", as - ag->std + 1, 
			as->nume, 41 - strlen(as->nume), as->prenume);
	for (p = as->note, s = p + ag->nrnote; p < s; p++)
		printf("%3i", *p);
	printf("\n");
	}
}
int NrNote(TGrupa *ag,int im,int x){
	TStud *as, *xs; /* adresa student, limita sup.as */
	int *p, *s,nr=0;     /* adresa nota, limita sup.p */
	xs = ag->std + ag->nrstud;
	for (as = ag->std; as < xs; as++)
		if (as->note[im-1] == x) nr++; /* aici trebuie modificat daca vrem indice sa inceapa cu indicele 0 sau 1 */
	return nr;
}
int InfoStud(TGrupa *ag){
	int j,nr=0;
	TStud *as, *xs; /* adresa student, limita sup.as */
	/* adresa nota, limita sup.p */
	xs = ag->std + ag->nrstud;
	for (as = ag->std; as < xs; as++)
		for (j=0 ;j< ag->nrnote ;j++)
			if(as->note[j] == 0){
				nr++;
				printf("\n%s %s are restanta ",as->nume,as->prenume);
				break;
			}
	return nr; 
}
/*- functii de prelucrare a informatiilor despre studenti,
  definite in cadrul laboratorului -*/
/* ..... */


int main()
{ TGrupa g;
	FILE *f;
	char numefis[21], *nf = numefis;

	fflush(stdin);
	printf("\nNume fisier note: ", numefis); gets(numefis);
	f = fopen(nf, "rt");
	if (!f)
	{ printf("Eroare deschidere fisier %s\n", nf);
		return -1;
	}

	/* in fisier, presupus corect, se gasesc nr.de materii (note)
	   si informatiile despre studenti: nume, prenume, note */
	fscanf(f, "%i", &(g.nrnote));
	g.nrstud = CitStud(f, &g);
	fclose(f);
	if (g.nrnote == 0)
	{ printf("Fisier vid!!!\n");
		return -2;
	}
	int i,j,indice;
	TabelStud(&g);
	for (i=0 ; i<11 ;i++){ /*pleaca de la 0 la 11 ca sa il ia si pe 10 */
		printf("\n%i :\t",i);  
		for (j=1 ; j < g.nrnote ; j++ )
			printf("%i\t",NrNote(&g,j,i));  
	}  
	printf("\ns-au afisat %i restantieri",InfoStud(&g));
	/*- apeluri ale functiilor de prelucrare -*/
	/* ..... */

	getch();
}
