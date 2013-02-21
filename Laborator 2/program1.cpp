#include<stdio.h>
#include<conio.h>

int main(){
    int nr=0,npoz=0;
    float suma=0,val,sumapoz=0;
    printf("Introduceti numere reale: ");
    for(;;){
    if(scanf("%f",&val)==0) break;
        if (val > 0){ /*verificam daca val citita este pozitiva */
        sumapoz = sumapoz + val; /*calculam suma nr pozitive */
        npoz++; /* incrementam contorul pt nr pozitive*/
        }     
        suma = suma + val; /*calculam suma tuturor numerelor citite*/
        nr++; /* incrementam contorul */
    }
    printf("suma este %4.2f , am citit %i numere dintre care %i pozitive \n", suma , nr,npoz);
    if (nr != 0 && npoz != 0 ){ 
       printf("media numerelor pozitive este %4.2f\n", sumapoz/npoz);
       float procent= ((float)npoz / nr ) * 100; /* calculam procentul nr pozitive */
       printf("procentul numerelor pozitive este %4.2f \n",procent);
    }
    else
    printf("nu se poate calcula procentul si media nr poz\n");
    
    getch();
    }
