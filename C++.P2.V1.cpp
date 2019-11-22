#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template < class T >  //ili template< typename T >
T minimum( T value1, T value2 )
{
   T min = value1;

   if ( value2 < min )
      min = value2;


   return min;
} // kraj na funkciskiot urnek maximum

int main()
{
   int int1, int2, int3;

   cout << "Vnesi dva celi broja: ";
   cin >> int1 >> int2;
   cout << "Minimalniot cel broj e: "
        << minimum( int1, int2);          // int verzija

   double double1, double2;

   cout << "\nVnesi dva double vrednosti: ";
   cin >> double1 >> double2 ;
   cout << "Minimalniot double vrednost e: "
        << minimum( double1, double2 ); // double verzija

   char char1, char2;

   cout << "\nVnesi dva karakteri: ";
   cin >> char1 >> char2;
   cout << "Minimalniot karakter e: "
        << minimum( char1, char2 )        // char verzija
        << endl;

   return 0;
}
