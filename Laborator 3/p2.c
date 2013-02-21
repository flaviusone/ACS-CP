#include <stdio.h>
#include <conio.h>

int main(){
	double x;
	int nr=0,nrx=0;
	printf("Introduceti secventa de valori reale terminata cu cacarcter nenumeric: ");
	for(;;){
		if (scanf("%lf",&x) == 0) break;
		nr++;
		if ( x == (long)x){  /*verificam daca x este egal cu x truncat */
			nrx++;
		}
	}
	if(nr != 0)
		if (nrx == 0) 
			printf("Procentul de valori numai cu parte intreaga este de 100 %%");
		else        
			printf("Procentul de valori numai cu parte intreaga este de %4.2f ", (float)nrx*100 / nr);
	else
		printf("Nu s-au introdus numere :(");

	getch();
}


