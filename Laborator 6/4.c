#include <stdio.h>


//	void Umple(char *x, char c, int n)
/* memoreaza n caractere c, incepand de la adresa x */

//	void Copie(int n, char *sursa, char *dest)
/* copiaza n octeti de la adresa sursa la adresa dest */

//	int CopieSir(char *sursa, char *dest)
/* copiaza sirul sursa (inclusiv terminatorul) la adresa dest;
rezultat: numarul de octeti copiati */

int DifLg(char *s1, char *s2){
	/* determina diferenta dintre lungimile sirurilor s1 si s2, 
	   fara a folosi strlen si cat mai eficient; 
	   rezultatul este negativ daca s1 este mai scurt si pozitiv in caz contrar */ 
	/*	Exemple:	DifLg("alfa", "abecedar") -> -4
		DifLg("da", "nu") -> 0
		DifLg("calculator", "ac") -> 8  */
	int ok1=1,ok2=1;
	int i=s1-s2;
	for(;;){
		if(*s1=='\0' ) ok1=0;
		else if (ok1==1) s1++;
		if(*s2=='\0' ) ok2=0;
		else if (ok2==1) s2++;
		if(ok1==0 && ok2==0) break;
	}
	return s1-s2-i;            

}
int main (){
	int d;
	d = DifLg("calculator","ac");
	printf("Diferenta s1 si s2 = %i",d);
	getch(); 
	return 0;
}
