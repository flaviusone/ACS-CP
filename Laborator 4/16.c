#include <stdio.h>
#include <conio.h>

int main ()
{
	int x,i=2,j;
	double eps;
	double s,t1,t2,y;
	printf ("Introduceti puterea x pentru a calcula e^x si precizia minima eps : ");
	if(scanf("%i%lf",&x,&eps) !=2) return 0;
	s=1+x;
	t2=x;
	for(;;)
	{
		t1=t2;
		t2=1;
		for ( j=1 ; j<i+1 ; j++) /*calcul termen nou x^i/i! */
			t2=(t2*x)/j;
		i++;
		y=t1 - t2 ;
		y= abs(y);
		if ( y < eps)  /* daca diferenta mai mica decat eps break */
			break;
		else
			s=s+t2;
	}
	printf("valoarea cu exp(x)= %lf \n",exp(x));
	printf("valoarea cu pow(2.781,x)= %lf \n",pow(2.718,x));
	printf("valoarea cu suma= %lf ",s);
	getch();
}
