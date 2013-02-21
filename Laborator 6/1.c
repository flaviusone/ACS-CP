#include <stdio.h>

void Umple(char *x, char c, int n){
	char *i;
	for(i=x ; i<x+n ; i++) 
	{ 
		*i = c;  
	} 
	*(x+n) = '\0';
}
/* memoreaza n caractere c, incepand de la adresa x */

void Copie(int n, char *sursa, char *dest){
	char *i,*j; 

	for(i=sursa, j=dest ; i<sursa+n ;j++, i++) {  
		*j=*i;         
	}

}
/* copiaza n octeti de la adresa sursa la adresa dest */

int CopieSir(char *sursa, char *dest){
	char *i,*k,*j;
	k=sursa;
	i=sursa;j=dest;
	for(;;) 
	{ 
		if(*i=='\0'){
			*j=*i;
			break;
		}           
		*j = *i;
		i++;j++;  
	}    
	return i-k;
}
/* copiaza sirul sursa (inclusiv terminatorul) la adresa dest;
rezultat: numarul de octeti copiati */
int main (){

	char a[10],b[10],c[10];
	Umple(a,'L',10);
	printf("%s\n",a);
	Copie(3,a,b);
	printf("%s\n",b);
	printf("%s\n",c);
	printf("%i\n",CopieSir(b,c));
	printf("%s\n",c);
	getch(); 

}
