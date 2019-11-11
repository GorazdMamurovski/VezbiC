#include <stdio.h>

int main()
{
   int mesec,den,godina;

   printf( "Vnesi data vo oblik dd-mm-yyyy,dd/mm/yyyy ili dd+mm+yyyy: " );
   scanf( "%d%*c%d%*c%d", &den, &mesec, &godina );
   if(mesec == 1)
   {
       printf( "Vneseniot datum e %d januari %d godina.", den, godina );
   }
   if(mesec == 2)
   {
       printf( "Vneseniot datum e %d februari %d godina.", den, godina );
   }
   if(mesec == 3)
   {
       printf( "Vneseniot datum e %d mart %d godina.", den, godina );
   }
   if(mesec == 4)
   {
       printf( "Vneseniot datum e %d april %d godina.", den, godina );
   }
   if(mesec == 5)
   {
       printf( "Vneseniot datum e %d maj %d godina.", den, godina );
   }
   if(mesec == 6)
   {
       printf( "Vneseniot datum e %d juni %d godina.", den, godina );
   }
   if(mesec == 7)
   {
       printf( "Vneseniot datum e %d juli %d godina.", den, godina );
   }
   if(mesec == 8)
   {
       printf( "Vneseniot datum e %d avgust %d godina.", den, godina );
   }
   if(mesec == 9)
   {
       printf( "Vneseniot datum e %d septemvri %d godina.", den, godina );
   }
   if(mesec == 10)
   {
       printf( "Vneseniot datum e %d oktomvri %d godina.", den, godina );
   }
   if(mesec == 11)
   {
       printf( "Vneseniot datum e %d noemvri %d godina.", den, godina );
   }
   if(mesec == 12)
   {
       printf( "Vneseniot datum e %d dekemvri %d godina.", den, godina );
   }


   return 0; /* uspeshen kraj */
}
