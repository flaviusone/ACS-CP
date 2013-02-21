#include <stdio.h>
#include <conio.h>

int main(){
	int p,x,min;
	printf("Introduceti un sir de numere terminat printrun caracter non numeric: ");

	for(;;){
		if (scanf("%i ",&p) == 0) 
			break;
		else
			min=p; /* daca se citeste primul numar atunci min este temporar setat ca el pentru a evita erori */
		for (;;){
			if(scanf("%i ",&x) == 0){
				break; /*daca nu se citeste numar dupa primul atunci gata " nu exista numere " */
			}

			if (x > p){
				if (x < min){
					min = x;
				}
			}               
		}

		break;           
	}

	if(min == p) 
		printf("Nu sunt numere cu valoare mai mica");
	else
		printf("Cea mai mica valoare dintre cele mai mari decat prima este %i  ",min);    
	getch();    
}
