#include <stdio.h>
#include <conio.h>

int main()
{
	int n,i,j;

	printf("Introduceti un numar de elemente n pozitiv ");
	if(scanf("%i ",&n) != 1 )
		return 0;
	if(n<0) return 0;
	fflush(stdin);

	int v[n];
	for(i=0 ; i<n ; i++)   /* secventa citire vector */
	{
		if(scanf(" %i",&v[i]) !=1 )
		{
			return 0;
		};
	}

	for(i=0 ; i<n ; i++)       /*secventa de prelucrare */
	{
		if(v[i]<0)
		{
			for(j=i+1 ; j<n ; j++)    /* secventa de eliminare a numarului */
			{
				v[i]=v[j];
				n--;
			}
		}
	}

	for(i=0 ; i<n ; i++)   /*secventa de afisare */
	{
		printf("v[%i]= %i ",i,v[i]);
	}
	getch();
}
