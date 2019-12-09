#include <map>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <numeric>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Vraboten{
public:
    char *ime;
    int bodovi;
    Vraboten(char *name,int bod);
    friend ostream & operator << (ostream &out, const Vraboten &c);
};

ostream & operator << (ostream &out, const Vraboten &c)
{
    out << c.ime;
    out << " Bodovi:" << c.bodovi << endl;
    return out;
}

Vraboten::Vraboten(char *name,int bod){
    ime = new char[strlen(name)+1];
    strcpy(ime,name);
    bodovi = bod;

}

struct less_than_bod
{
    inline bool operator() (const Vraboten& struct1, const Vraboten& struct2)
    {
        return (struct1.bodovi < struct2.bodovi);
    }
};

int funkcija(Vraboten& v1,Vraboten& v2){
    return v1.bodovi+v2.bodovi;
}




int main(){
    std::ostream_iterator< Vraboten > output( cout, "" );
    std::vector< Vraboten > v1;
    char name[20] = "Gorazd";
    v1.push_back(Vraboten(name,10));
    char name2[20] = "Tomislav";
    v1.push_back(Vraboten(name2,5));
    char name3[20] = "Ivan";
    v1.push_back(Vraboten(name3,15));
    int sum =
    std::accumulate (begin(v1), end(v1), 0,
        [](int i, const Vraboten& o){ return o.bodovi + i; });

    std::sort( v1.begin(), v1.end() ,less_than_bod());
    std::copy( v1.begin(), v1.end(), output );
    cout<<"Vkupnata suma na bodovi e "<<sum<<endl;
    return 0;
}
