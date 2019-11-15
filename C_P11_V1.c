/* Program p09_15.c
   Povekjenamenski sortirachki program
   koj koristi pokazhuvachi kon funkcii */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char broj[50];
    char normalenBroj[10];
    int dBroj;
    long lBroj;
    char *podelenBroj;
    gets( broj );
    podelenBroj = strtok( broj," " );
    printf( "%s\n", podelenBroj );
    podelenBroj = memmove(podelenBroj,&podelenBroj[1],3);
    memcpy(normalenBroj,podelenBroj,3);
    dBroj = atoi(normalenBroj);
    podelenBroj = strtok( NULL, " " );
    podelenBroj = strtok(podelenBroj,"-");
    lBroj = atol(podelenBroj)*10000;
    podelenBroj = strtok( NULL, " " );
    lBroj += atol(podelenBroj);
    printf("Drzavniot broj %d ostanatiot %li \n",dBroj,lBroj);



}

