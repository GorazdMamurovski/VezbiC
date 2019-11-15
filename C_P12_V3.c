/* Program vezba11_01.c
   Shto raboti sledniot program?*/

/* Sledniot program go dava brojot na 1 vo bitovite dali e paren ili neparen*/
#include <stdio.h>

int misterija( unsigned bitovi );
void prikaziBitovi( unsigned vrednost );

int main()
{
   unsigned x;
   printf( "Vnesi cel broj: " );
   scanf( "%u", &x );
   prikaziBitovi(x);
   printf( "Rezultatot e %d\n", misterija( x ) );
   return 0;
}

int misterija( unsigned bitovi )
{
   unsigned i;
   unsigned maska = 1 << 31;
   unsigned total = 0;

   for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
      if ( ( bitovi & maska ) == maska ) {
         total++;
      }
   }
   return !( total % 2 ) ? 1 : 0;
}

void prikaziBitovi( unsigned vrednost )
{
   unsigned c; /* brojach */

   /* definiraj prikazhiMaska i shiftiraj ja vo levo za 31 bit */
   unsigned prikazhiMaska = 1 << 31;

   printf( "%10u = ", vrednost );

   /* pomini niz bitovite */
   for ( c = 1; c <= 32; c++ ) {
      putchar( vrednost & prikazhiMaska ? '1' : '0' );
      vrednost <<= 1; /* shiftiraj ja vrednosta vo levo za 1 */

      if ( c % 8 == 0 ) { /* ispechati prazno mesto posle 8 bita */
         putchar( ' ' );
      } /* kraj if */
   } /* kraj for */
   putchar( '\n' );
} /* kraj na funkcijata prikaziBitovi */

