#include <stdio.h>
#include <stdlib.h>
int mnoziSoStepenOdDva(unsigned broj,int stepen);
int main()
{
    unsigned broj;
    int stepen;
    int rezultat;
    printf("Vnesi broj \n");
    scanf("%u",&broj);
    printf("Vnesi stepen na 2 \n");
    scanf("%d",&stepen);
    rezultat = mnoziSoStepenOdDva(broj,stepen);
    printf("%d \n",rezultat);
    return 0;
}

int mnoziSoStepenOdDva(unsigned broj,int stepen){
    for(int i=0;i<stepen;i++){
        broj = broj<<1;
    }
    return broj;
}
