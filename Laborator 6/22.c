#include <stdio.h>

int *estrchr(char *s, char caracter){
	char *p;
	p=s;
	for(;;p++) 
	{ 
		if(*p==caracter) return p;                     
		if(*p=='\0') return NULL;     
	}     
}

int main () {
	int *p;
	char s[]="student";
	p = estrchr(s,'d');
	printf("%s",p);
	getch(); 



}
