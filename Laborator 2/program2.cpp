#include<stdio.h>
#include<conio.h>

int main(){
    float x,y;
    int c1=0,c2=0,c3=0,c4=0;
    for (;;){  
    printf("\nIntroduceti x si y : ");   
    if(scanf("%f%f ",&x,&y)!=2) /*citim numerele x si y */
    break;
    if (x != 0 && y != 0){
          if (x>0 && y >0) /* daca x pozitiv y pozitiv => Cadran 1 */
             c1++; /*incrementam contorul pentru cadran*/
          if (x<0 && y>0)  /* daca x pozitiv y pozitiv => Cadran 2 */
             c2++; /*incrementam contorul pentru cadran*/
          if (x<0 && y<0)  /* daca x pozitiv y pozitiv => Cadran 3 */
             c3++; /*incrementam contorul pentru cadran*/
          if (x>0 && y<0)  /* daca x pozitiv y pozitiv => Cadran 4 */
             c4++; /*incrementam contorul pentru cadran*/
            
            }
    }
    printf("In C1=%i elemente\nIn C2=%i elemente\nIn C3=%i elemente\nIn C4=%i elemente\n",c1,c2,c3,c4);     
    getch();     
}
