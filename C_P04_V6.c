#include <stdio.h>

int main()
{
   int a,suma;
   a=0;
   suma=0;
   while (1){
       scanf("%d",&a);
       if (a==-1){
           break;
       }
       suma=suma+a;
       printf("%d\n",suma);
   }
   printf("Krajna suma e %d\n",suma);
   return 0;
}
