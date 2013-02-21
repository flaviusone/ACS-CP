#include <stdio.h>

int *eststr(char *s1, char *s2){
	char *p,*q,*l;
	for (p=s1;;p++){
		for(q=s2,l=p;;q++,l++){
			if(*q == '\0' ) return p;
			if(*l != *q) break;

		}
		if(*p=='\0') return NULL;
	}

}

int main () {
	char s[]="student";
	char p[]="en";
	//l = estrchr(s,p);
	printf("%s",eststr(s,p));
	getch(); 



}
