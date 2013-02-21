#include <stdio.h>
#include <conio.h>

int main()
{
	int n,m,i,j,p,r;
	for(;;)
	{
		printf("Introduceti un set de dade n,m cu n>m si |m|>1: ");
		if (scanf("%i%i",&n,&m) != 2 ) break;
		if (n<=m) break;
		for (p = 0, r = n; r % m == 0;)
		{
			p++;
			r /= m;
		}
		if (r == n)
			printf("Nu sunt divizibile \n");
		else if (p == 1 && r == 1)
			printf("%i = %i ^ %i \n",n,m,p);
		else if (p == 1 && r != 1)
			printf("%i = %i * %i \n",n,m,r);
		else
			printf("%i = %i ^ %i * %i \n",n,m,p,r);
	}
}
