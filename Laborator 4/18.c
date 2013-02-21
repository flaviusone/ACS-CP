#include <stdio.h>
#include <conio.h>

int main()
{
	int nn,n,i,j,s=0,a,b,nr=0;

	printf("Introduceti un numar de elemente n pozitiv "); /*citire n */
	if(scanf("%i",&n) != 1)
		return 0;
	if(n<0) return 0;
	fflush(stdin);

	nn=n;
	printf("Introduceti doi intregi a < b "); /* citire a b */
	if(scanf("%i %i",&a,&b) != 2 )
		return 0;
	if(a>=b) return 0;
	fflush(stdin);


	printf("Introduceti elementele vectorului: ");
	int v[n];
	for(i=0 ; i<n ; i++)   /* secventa citire vector */
	{
		if(scanf(" %i",&v[i]) !=1 )
		{
			return 0;
		};
	}
	for(i=0 ; i<n ; i++)  /* secventa de prelucrari */
	{
		s=s+v[i];
		if(v[i]>a && v[i]<b)
		{
			for(j=i+1 ; j<n ; j++) /* secventa de eliminare a numerelor */
				v[i]=v[j];

			n--;
			nr++;
			s=s+v[i]; /*adunam din nou la suma pentru valoarea care a venit peste cea veche*/
		}
	}


	for(i=0 ; i<n ; i++)   /*secventa de afisare */
	{
		printf("v[%i]= %i ",i,v[i]);
	}
	printf("\n Media aritmetica a valorilor citite %f \n", (float)s/nn);
	printf("Numarul de valori in [%i , %i] = %i \n",a,b,nr);
	getch();
}
