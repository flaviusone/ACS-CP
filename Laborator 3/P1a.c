#include <stdio.h>
#include <conio.h>

int main(){
	char c;
	printf("Introduceti sirul de caractere terminat cu caracterul '.' ");
	for(;;){
		scanf("%c",&c);
		if( c == '.') break;  /*daca intalnim '.' atunci gata */
		if(c>='a' && c <= 'z' ){ /*verificam daca caracterul este litera mica */
			printf("%c", c - 32); /*afisam litera mare*/
		}else {
			printf("%c", c);
		}
	}
	getch();         
}
