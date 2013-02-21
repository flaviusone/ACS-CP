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
	char c;
	int i,x,nr=0,tot=0;
	FILE *f, *rez;
	f = Deschide("fisier citit: ", "rt");
	if (!f) return 1;

	rez = Deschide("fisier rezultate: ", "wt");
	if (!rez) return 2;
	fscanf(f,"%i",&x);
	tot=1;
	for (i = 0; !feof(f); i++){
		/* citeste cate o linie */
		fscanf(f,"%c",&c);
		if(c == '0' ) 
			fprintf(f,"1");
		else
			fprintf(f,"0");
	}   
	fclose(f); 
	fclose(rez);
	getch();
	return 0;   
}
/* scrie indice si lungime linie */

