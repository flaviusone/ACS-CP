/*--- Lmat.c ---*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXL 20
#define MAXC 20

typedef enum{esec, incomplet, complet} TRezCitMat;

/* Citire dimensiuni si valori matrice din fisier deja deschis
Parametri: fisier, matrice, adrese memorare dimensiuni
Rezultat: 0 - eroare citire dimensiuni; 
1 - citire incompleta, 2 - citire completa valori */
TRezCitMat CitMatF(FILE* f, int a[][MAXC], int* nL, int* nC)
{ int i,j;
	if (fscanf(f, "%i%i", nL, nC) < 2) return esec;
	for (i = 0; i < *nL; i++)
	{ for (j = 0; j < *nC; j++)
		if (fscanf(f,"%i", a[i]+j) != 1) return incomplet;
	}
	return complet;
}

/* Afisare matrice */
void AfiMat(int a[][MAXC], int nL, int nC)
{ int i,j;
	for (i = 0; i < nL; i++)
	{ for (j = 0; j < nC; j++)
		printf ("%5i", a[i][j]);
		putchar('\n');
	}
}

/* alte functii de prelucrare */
int NLx(int a[][MAXC],int linie,int nC){
	int j,nx = 0;
	for (j = 0; j < nC; j++){
		if (a[linie-1][j] < 0) nx++;}
	return nx;  
}
int NCx(int a[][MAXC],int coloana,int nL){
	int j,nx = 0;
	for (j = 0; j < nL; j++){
		if (a[j][coloana-1] < 0) nx++;}
	return nx;  
}
int MinMax(int a[][MAXC],int nL,int nC,int *min){
	int i,j,max=a[0][0];
	*min=a[0][0];
	for (i = 0; i < nL; i++)
	{ 
		for (j = 0; j < nC; j++){
			if (a[i][j] > max) max=a[i][j];
			if (a[i][j] < *min) *min=a[i][j];
		}

	}  
	return max;   
}

int main()
{ int x[MAXL][MAXC] = {{0}};
	int min,linie,coloana,nL, nC, i, j,a,b;
	FILE* f;
	char numefis[21];

	/* Citire nume si deschidere fisier */
	printf("Nume fisier date: "); fflush(stdin);
	scanf("%s", numefis);
	f = fopen(numefis, "rt");
	if (!f)
	{ printf("Eroare la deschiderea fisierului %s\n", numefis);
		getch();
		return -1;
	}

	/* Citire matrice */
	if(CitMatF(f, x, &nL, &nC) != complet)
	{ printf("Eroare date\n");
		getch();
		return -2;
	}  
	AfiMat(x, nL, nC);       /* Afisare matrice */

	/* utilizare functii de prelucrare */
	printf("Introduceti linia de verificat ");
	scanf("%i",&linie);
	printf("Introduceti coloana de verificat ");
	scanf("%i",&coloana);
	printf("Pe linia %i sunt %i valori negative iar pe coloana %i sunt %i valori negative\n",linie,NLx(x,linie,nC),coloana,NCx(x,coloana,nL));
	printf("Maximul este %i si minimul este %i ",MinMax(x,nL,nC,&min),min);
	getch();
	return 0;
}
