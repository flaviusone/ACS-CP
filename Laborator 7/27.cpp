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
    char c[51];
    int j,i,L,linii=0,fspatii=0,indice,maxim,cif;
  f = Deschide("fisier citit: ", "rt");
  if (!f) return 1;
  for (i = 0; !feof(f); i++)
  /* citeste cate o linie */
  { 
   linii++;cif=0;          
   fgets(c,50,f);
   for(j=0;c[j]!='\0';j++){
      if(c[j]==' ')
        cif++;                  
        }                   
    if (cif==0)fspatii++;
    if (cif>maxim){ 
    maxim=cif;
    indice=i+1;
    }   
    
    }
    
   printf("Procentul liniilor fara spatii este de: %f %\n)",(float)fspatii/linii*100);  
   printf("indicele liniei cu cele mai multe spatii este : %i",indice); 
   fclose(f); 
   getch();    
  }
