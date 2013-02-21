#include <stdio.h>
#include <conio.h>

int main(){
	float xv=0,xc=0;
	int nou,old,nr;
	printf("Introduceti sirul de numere terminat cu un caracter nenumeric: ");
	for(;;){
		if(scanf("%i ", &xv)== 0)    
			break;
		nr=1;
		if(xv > 0 ){
			old=1;
		}else if(xv==0) { 
			old=0;
		}else{
			old=-1;
		}
		while (scanf("%i",&xc) != 0 ){
			if(xc > 0 ){
				nou=1;
			}else if(xc==0) { 
				nou=0;
			}else{
				nou=-1;
			}
			if(nou == old){
				nr++;

			}else
			{
				if (old==-1){
					printf("sunt %i nr negative \n",nr); }
				else if (old==0){
					printf("sunt %i nr nule \n",nr);}
				else{
					printf("sunt %i nr pozitive \n",nr);
				}    
				old=nou;
				nr=1;                
			}
		}
		break;      
	} 
	getch();
}
