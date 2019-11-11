#include <stdio.h>

int main()
{
   int a,suma;
   char c;
   a=0;
   suma=0;
   while (1){
       a=0;
       printf("Vnesi broj:");
       scanf("%d",&a);
       printf("Ushte? (d/n):");
       scanf("%c",&c);
       if (c=='n'){
           break;
       }
       suma=suma+a;
       printf("\n%d\n",suma);
   }
   printf("Sumata e %d\n",suma);
   return 0;
}
