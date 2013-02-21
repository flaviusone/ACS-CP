/*---  ProgL5.c  ---*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

/* directive necesare pentru utilizarea randomize() */
#include <time.h>
#ifndef random
#define random(n) (rand() % (n))
#endif
#ifndef randomize
#define randomize() (srand((unsigned)time(NULL)))
#endif

#define MAX 30

int CitVect (int v[], int nrmax)
	/* citeste cel mult nrmax elemente vector si intoarce numarul lor */
{ int n;
	for (n = 0; n < nrmax; n++)
		if (scanf ("%i", v + n) != 1) break;  /* s-a intalnit valoare nenumerica */
	return n;
}

void IniVect (int n, int v[], int m, int M)
{ int i;
	for (i = 0; i < n; i++)
	{ v[i] = m + random (M - m + 1); }
}

void AfiVect (int n, int v[], int m)
	/* afiseaza n valori din v, cate m pe un rand */
{ int i = 0;
	for (; i < n; i++)
	{ printf ("%7i", v[i]);
		if (i % m == m-1) printf ("\n");
	}
	if (n % m > 0) printf ("\n"); /* daca e la rand nou adica n % m = 0 mai sari un rand */
}

int MedieSiProcent(int v[], int nv, double *am, double *ap)
	/* parcurge o singura data vectorul v, pentru a determina
	   numarul de valori care indeplinesc o conditie la alegere, 
	   respectiv media aritmetica si procentul acestora, pe care,
	   daca este cazul, le memoreaza la adresele am si ap */

{
	int nr=0,si=0,st=0,i;
	for (i=0 ; i<nv ; i++){
		st=st+v[i]; /*suma totala */
		if (v[i] % 2 != 0 ){
			nr++; /*nr de nr impare */
			si=si+v[i];  /* suma nr impare */
		}
	}       
	if(nr!=0){
		*am = (double)si/nr ;
		*ap = (double)si/st * 100;
	}
	return 0;
}           
int IP(int v[], int nv)
	/* parcurge o singura data vectorul v, pentru a determina
	   indicele primei valori care indeplineste o conditie
	   la alegere; daca nu exista astfel de valori rezultatul este -1
	   */
{
	int indice=-1,i;
	for(i=0 ; i<nv ; i++){
		if (v[i] % 2 ==0){ /*conditia sa fie par */
			indice=i;
			break;}
	}
	return indice;
}
int Putere(int x, int X)
	/* verifica daca |X| este o putere a lui |x|; intoarce 0 sau valoare putere */
{int p=0;
	for(;;){
		if( X % 2 == 0){
			X = X / 2;
			p++;
		}else if ( X == 1 ) return p;
		else return 0; 

	}
}

int main ()
{ int x[MAX], y[MAX], nx, ny;
	double ma=0,pr=0;
	randomize();
	nx = 5 + random(MAX-4);
	IniVect (nx, x, -50, 50);
	printf ("\nVectorul x:\n");
	AfiVect (nx, x, 10);
	printf ("Introduceti valori intregi, terminand cu un caracter nenumeric\n");
	ny = CitVect(y, MAX);
	if (ny == 0) return 0;
	printf ("\nSecventa citita:\n");
	AfiVect (ny, y, 5);
	/////////////////////////// punctul 1
	MedieSiProcent(y,ny,&ma,&pr); 
	if (ma != 0){ 
		printf ("\n Media aritmetica a nr impare este: %lf\n", ma);
		printf ("\n Procentul nr impare este: %lf\n", pr);
	}                 
	/////////////////////////// punctul 2
	int indice = IP(y,ny);
	if (indice != -1 )
		printf ("\nPrima valoare para din vectorul y se afla pe pozitia: %i\n", indice);  
	else
		printf ("\nNu exista valori pare in vectorul y\n"); 
	/////////////////////////// punctul 3
	int i;
	for (i=0 ; i<ny ; i++){
		int p = Putere(2 , y[i] );
		if ( p != 0 )
			printf("y[%i] = %i = 2 ^ %i \n",i,y[i],p);
	}       
	getch();
	return 1;
}
