#include <stdio.h>

int main()
{
   int broj,cifra,a,delenik;
   a=0;
   char rimski;
   scanf(("%d"),&broj);
   while (cifra!=0)
   {
       if (broj>1000)
       {
           rimski='M';
           delenik=1000;
       }
       else if (broj>100 && broj<1000)
       {
           rimski='C';
           delenik=100;
       }
       else if (broj>10 && broj<100)
       {
           rimski='X';
           delenik=10;
       }
       else
       {
           switch (broj) {
           case 1:
           {
               rimski ='I';
               break;
           }
           case 2:
           {
               rimski ='I';
               printf("%c\n",rimski);
               printf("%c\n",rimski);
               break;
           }case 3:
           {
               rimski ='I';
               printf("%c\n",rimski);
               printf("%c\n",rimski);
               printf("%c\n",rimski);
               break;
           }case 4:
           {
               rimski ='I';
               printf("%c\n",rimski);
               rimski ='V';
               printf("%c\n",rimski);
               break;
           }case 5:
           {
               rimski ='V';
               printf("%c\n",rimski);
               break;
           }case 6:
           {
               rimski ='V';
               printf("%c\n",rimski);
               rimski ='I';
               printf("%c\n",rimski);
               break;
           }case 7:
           {
               rimski ='V';
               printf("%c\n",rimski);
               rimski ='I';
               printf("%c\n",rimski);
               rimski ='I';
               printf("%c\n",rimski);
               break;
           }case 8:
           {
               rimski ='V';
                printf("%c\n",rimski);
               rimski ='I';
               printf("%c\n",rimski);
               rimski ='I';
               printf("%c\n",rimski);
               rimski ='I';
               printf("%c\n",rimski);
               break;
           }case 9:
           {
               rimski ='I';
               printf("%c\n",rimski);
               rimski ='X';
               printf("%c\n",rimski);
               break;
           }
       }
       }
       cifra=broj/delenik;
       broj=broj%delenik;
       while(a<cifra)
       {
          printf("%c",rimski);
          a++;
       }
       a=0;

   }


   return 0;
}
