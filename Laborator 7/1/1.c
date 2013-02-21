#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <string.h>

FILE* Deschide(char antet[], char *mod)
	/* deschide fisier cu nume citit de la stdin */
{ FILE* f = NULL;
	char nume[21];
	printf("%s", antet);
	fflush(stdin); scanf("%s", nume);
	f = fopen(nume, mod);
	if (!f)
	{ printf("Eroare la deschidere %s\n", nume);
		getch();
	}
	return f;
}
int main(){
	FILE *f, *rez;
	char c;
	int i,L,linii=0,fcifre=0,indice,maxim,cif;
	f = Deschide("fisier citit: ", "rt");
	if (!f) return 1;

	//rez = Deschide("fisier rezultate: ", "wt");
	//  if (!rez) return 2;
	for (i = 0; !feof(f); i++)
		/* citeste cate o linie */
	{ for (L = 0; ; L++)
		{ 
			c = fgetc(f);
			if(c>='0' && c<='9')
				cif++;
			/* test sfarsit fisier sau linie */
			if (c == EOF || c == '\n') break;
		}  
		linii++;
		if (cif>0)fcifre++;
		if (cif>maxim){ 
			maxim=cif;
			indice=i+1;
		}
		cif=0;

	}
	printf("Procentul liniilor fara cifre este de: %f %\n)",(float)fcifre/linii*100);  
	printf("indicele liniei cu cele mai multe cifre este : %i",indice); 
	getch();    
}
