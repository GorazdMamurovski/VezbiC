#include <cstring>
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template <class T>
class Zapis{
public:
    T x;
    T y;
    T z;
    friend void pogolemo(Zapis<T> &A);
    Zapis(T a,T b,T c);

};

template <class T>
Zapis<T>::Zapis(T a,T b,T c){
    x=a;
    y=b;
    z=c;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"z = "<<z<<endl;
}

//Nemoze so private vika A.x/A.y/A.z se private i ne se kompajlira iako e friend funkcija

template <class T>
void pogolemo(Zapis<T> &A){
    if(A.x+A.y+A.z>10000){
        cout<<"Zbirot e pogolem od 10000"<<endl;
    }
    else{
        cout<<"Zbirot ne e pogolem od 100000"<<endl;
    }
}

int main(){
    Zapis<int> zapisI1(100,200,300);
    Zapis<int> zapisI2(1000,20000,3000);
    Zapis<float> zapisF1(100.6,200.2,300.3);
    Zapis<float> zapisF2(1000.2,20000.1,3000);
    pogolemo<int>(zapisI1);
    pogolemo<int>(zapisI2);
    pogolemo<float>(zapisF1);
    pogolemo<float>(zapisF2);
    return 0;
}
