#include <stdio.h>
#include <stdlib.h>
void prikaziBitovi( unsigned value );
unsigned prevrti(unsigned value);
int main()
{
    unsigned a;
    unsigned broj;
    printf("Vnesi broj \n");
    scanf("%u",&broj);
    a = prevrti(broj);
    prikaziBitovi(broj);
    prikaziBitovi( a );
    return 0;
}

unsigned prevrti(unsigned vrednost){
    {
        unsigned int broj = sizeof(vrednost) * 8 - 1;
        unsigned int prevrtenBroj = vrednost;

        vrednost >>= 1;
        while(vrednost)
        {
           prevrtenBroj <<= 1;
           prevrtenBroj |= vrednost & 1;
           vrednost >>= 1;
           broj--;
        }
        prevrtenBroj <<= broj;
        return prevrtenBroj;
    }
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
