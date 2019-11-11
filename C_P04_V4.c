#include <stdio.h>

int main()
{
   int a,suma;
   a=0;
   suma=0;
   while (a<=10){
       suma=suma+a;
       a=a+1;
       printf("%d %d\n",suma,a);
   }
   return 0;
}
