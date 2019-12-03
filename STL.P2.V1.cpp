#include <cstring>
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template <class T>
T suma(T *niza,int pocetok,int Kraj,T pocetnaV = T()){
    pocetnaV +=niza[pocetok];
    pocetnaV +=niza[Kraj];
    return pocetnaV;
}

int main(){
    int a[] = {1,2,3,4,5};
    int b = suma(a,0,2,5);

    float c[] = {1.1,2.2,3};
    float d = suma(c,0,1);
    cout<<b;
    cout<<endl;
    cout<<d;
    cout<<endl;
    return 0;
}
