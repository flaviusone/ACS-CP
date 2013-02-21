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
CitTrI(FILE* f, int a[][MAXC],int* nL)
{ int i,j;
	fscanf(f, "%i", nL);
	for (i = 1; i < *nL; i++){
		for (j = 1; j < i+1; j++)
			fscanf(f,"%i", a[i]+j);
	} 

	return 0;

}
rezolvare(int a[][MAXC],int b[],int rex[],int nL){
	int i,j;
	for (i = 1; i < nL; i++){
		for (j = 1; j < i+1; j++)      
			rex[i]=b[i]/a[i][i]-rex[i-1];  
	}
	return 0;
}

/* Afisare matrice */
void AfiMat(int a[][MAXC], int nL)
{ int i,j;
	printf("%i", nL);
	for (i = 1; i < nL; i++){
		for (j = 1; j < i+1; j++)
			printf ("%5i", a[i][j]);      
		printf("\n"); 
	}
}

/* alte functii de prelucrare */

int main()
{ int x[MAXL][MAXC] = {{0}};
	int y[MAXL],solutii[MAXL];
	int nL, nC, i, j, indiceLinie, indiceColoana;
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
	CitTrI(f, x,&nL);
	/* if(CitTrI(f, x, &nL) != complet)
	   { printf("Eroare date\n");
	   getch();
	   } 
	   */  
	AfiMat(x, nL);        

	//  rezolvare(x,y, solutii,nL);   
	//      for (i = 1; i < nL; i++)
	// printf("%5i", solutii[i]); 
	getch();
	return 0;
}
