#include <cstring>
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template <class T>
class Mnozestvo{
    T *mnoz;
    static int brojMn;
    int brojEl;
public:
    Mnozestvo(int brojM);
    void dodadi(T el);
    void pecati();
    T najgolem();
    int brojElementi();

};

template <class T>
int Mnozestvo<T>::brojElementi(){
    return brojMn;
}

template <class T>
int Mnozestvo<T>::brojMn = 0;

template <class T>
Mnozestvo<T>::Mnozestvo(int brojM){
    mnoz = new T[brojM];

    brojEl = 0;
}

template<class T>
T Mnozestvo<T>::najgolem(){
    T temp = mnoz[0];
    for(int i=1;i<brojEl;i++)
    {
        if(temp<mnoz[i]){
            temp=mnoz[i];
        }
    }
    return temp;
}

template <>
char * Mnozestvo<char *>::najgolem(){
    char * temp = mnoz[0];
    for(int i=1;i<brojEl;i++)
    {
        if(strlen(temp)<strlen(mnoz[i])){
            temp=mnoz[i];
        }
    }
    return temp;
}

template <class T>
void Mnozestvo<T>::dodadi(T el){
    mnoz[brojEl]=el;
    brojEl++;
    brojMn++;
}


template <class T>
void Mnozestvo<T>::pecati(){
    for(int i=0;i<brojEl;i++){
        cout<<mnoz[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Mnozestvo<int> mnozestvoInt(5);
    Mnozestvo<float> mnozestvoFloat(5);
    Mnozestvo<char *> mnozestvoChar(5);
    int meni;
    int brojI;
    float brojF;
    char string[10];
    int s=0;
    cout<<"Izberi meni: "<<endl;
    cout<<"1.Dodaj element vo A"<<endl;
    cout<<"2.Dodaj element vo B"<<endl;
    cout<<"3.Dodaj element vo C"<<endl;
    cout<<"4.Prikazi go A"<<endl;
    cout<<"5.Prikazi go B"<<endl;
    cout<<"6.Prikazi go C"<<endl;
    cout<<"7.Prikazi najgolemi elementi"<<endl;
    cout<<"8.Prikazi broj na elementi vo mnozestvata"<<endl;
    cout<<"9.Kraj"<<endl;
    cin>>meni;
    while(meni!=9){
        switch (meni) {
        case 1:
            cout<<"Vnesi int vo mnozestvoto A: "<<endl;
            cin>>brojI;
            mnozestvoInt.dodadi(brojI);
            break;
        case 2:
            cout<<"Vnesi float vo mnozestvoto B: "<<endl;
            cin>>brojF;
            mnozestvoFloat.dodadi(brojF);
            break;
        case 3:
            cout<<"Vnesi string vo elementot C"<<endl;
            cin>>string;
            mnozestvoChar.dodadi(string);
            s++;
            break;
        case 4:
            mnozestvoInt.pecati();
            break;
        case 5:
            mnozestvoFloat.pecati();
            break;
        case 6:
            mnozestvoChar.pecati();
            break;
        case 7:
            cout<<"Mnozestvo A najgolem element e: "<<mnozestvoInt.najgolem()<<endl;
            cout<<"Mnozestvo B najgolem element e: "<<mnozestvoFloat.najgolem()<<endl;
            cout<<"Mnozestvo C najgolem element e: "<<mnozestvoChar.najgolem()<<endl;
            break;
        case 8:
            cout<<"Mnozestvo A ima: "<<mnozestvoInt.brojElementi()<<endl;
            cout<<"Mnozestvo B ima: "<<mnozestvoFloat.brojElementi()<<endl;
            cout<<"Mnozestvo C ima: "<<mnozestvoChar.brojElementi()<<endl;
            break;
        }
        cout<<"Izberi meni: "<<endl;
        cout<<"1.Dodaj element vo A"<<endl;
        cout<<"2.Dodaj element vo B"<<endl;
        cout<<"3.Dodaj element vo C"<<endl;
        cout<<"4.Prikazi go A"<<endl;
        cout<<"5.Prikazi go B"<<endl;
        cout<<"6.Prikazi go C"<<endl;
        cout<<"7.Prikazi najgolemi elementi"<<endl;
        cout<<"8.Prikazi broj na elementi vo mnozestvata"<<endl;
        cout<<"9.Kraj"<<endl;
        cin>>meni;
    }
    return 0;
}
