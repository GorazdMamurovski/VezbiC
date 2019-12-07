#include <vector>
#include <list>
#include <iostream>
#include <algorithm>



using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include <iterator>

template < class T >
void printList( const std::list< T > &listRef );

int main(){
    std::list<string> adresi1;
    std::list<string> adresi2;
    std::list<string> adresi3;
    char adresa1[30] = "gorazdmamurovski@yahoo.com";
    char adresa2[30] = "gogo@yahoo.com";
    char adresa3[30] = "mamur@yahoo.com";
    char adresa4[30] = "jovan@yahoo.com";
    char adresa5[30] = "stefan@yahoo.com";
    char adresa6[30] = "viktor@yahoo.com";
    adresi1.push_front(adresa1);
    adresi1.push_front(adresa2);
    adresi1.push_front(adresa3);
    adresi2.push_front(adresa1);
    adresi2.push_front(adresa4);
    adresi2.push_front(adresa5);
    adresi3.push_front(adresa6);
    adresi3.push_front(adresa4);
    adresi3.push_front(adresa2);
    printList( adresi1 );
    cout<<endl;
    printList( adresi2 );
    cout<<endl;
    printList( adresi3 );
    cout<<endl;
    adresi1.splice(adresi1.end(),adresi2);
    adresi1.splice(adresi1.end(),adresi3);
    adresi1.unique();
    printList( adresi1 );
    cout<<endl;
    return 0;
}

template < class T >

void printList( const std::list< T > &listRef )
{
   if ( listRef.empty() )
      cout << "Listаta e prazna";
   else {
      std::ostream_iterator< T > output( cout, " " );
      std::copy( listRef.begin(), listRef.end(), output );
   }
}
