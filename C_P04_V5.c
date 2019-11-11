#include <stdio.h>

int main()
{
   int a,proizvod,b;
   b=1;
   scanf("%d",&a);
   proizvod=a;
   while (b<10){
       scanf("%d",&a);
       proizvod=proizvod*a;
       printf("%d %d\n",proizvod,a);
       b++;
   }
   return 0;
}
