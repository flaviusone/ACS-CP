#include <stdio.h>
#include <conio.h>

int main(){
	char c;
	printf("Introduceti sirul de caractere terminat cu caracterul '.' ");
	for(;;){
		c=getche();
		if( c == '.') break;
		if(c>='a' && c <= 'z' ){
			printf("%c", c - 32);
		}else {
			printf("%c", c);
		}
	}
	getch();         
}
