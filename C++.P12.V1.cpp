#include <cstring>
#include <cassert>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Oblik{
private:
    char *imeOblik;
public:
    Oblik(char *ime);
    void printOblik();
};

Oblik::Oblik(char *ime){
    imeOblik = new char[strlen(ime)+1];
    strcpy(imeOblik,ime);
}

void Oblik::printOblik(){
    cout<<"Oblikot e: " <<imeOblik<<endl;
}

class DvoDimenzionaelOblik:public Oblik{
private:
    int brStrani;
public:
    DvoDimenzionaelOblik(char *ime, int broj);
    void printDimenzii();
};

DvoDimenzionaelOblik::DvoDimenzionaelOblik(char *ime, int broj):Oblik(ime){
    brStrani = broj;
}

void DvoDimenzionaelOblik::printDimenzii(){
    printOblik();
    if(brStrani==1){
        cout<<"So edna strana"<<endl;
    }
    else{
        cout<<"So "<<brStrani<<" strani"<<endl;
    }
}

class Triagolnk:public DvoDimenzionaelOblik{
private:
    char *naziv;
    static int brojTriagolnici;
public:
    Triagolnk(char *ime,char *naizvO, int broj);
    void printKlasa();
    void printTria();
};

int Triagolnk::brojTriagolnici = 0;

void Triagolnk::printTria(){
    cout<<"Vkupno ima napraveno "<<brojTriagolnici<<" triagolnici"<<endl;
}

Triagolnk::Triagolnk(char *ime,char *naizvO, int broj):DvoDimenzionaelOblik(ime,broj){
    naziv = new char[strlen(naizvO)+1];
    strcpy(naziv,naizvO);
    brojTriagolnici++;
}

void Triagolnk::printKlasa(){
    printDimenzii();
    cout<<"Triagolnikot e "<<naziv<<endl;
}

class Pravoagolnik:public DvoDimenzionaelOblik{
private:
    char *naziv;
    static int brojPravoagolnici;
public:
    Pravoagolnik(char *ime,char *naizvO, int broj);
    void printPravo();
};

int Pravoagolnik::brojPravoagolnici = 0;

Pravoagolnik::Pravoagolnik(char *ime,char *naizvO, int broj):DvoDimenzionaelOblik(ime,broj){
    naziv = new char[strlen(naizvO)+1];
    strcpy(naziv,naizvO);
    brojPravoagolnici++;
}

void Pravoagolnik::printPravo(){
    printDimenzii();
    cout<<"Pravoagolnikot e "<<naziv<<endl;
}

class TroDimenzionalni:public Oblik{
private:
    int brojStrani;
    int brojLica;
public:
    TroDimenzionalni(char *ime, int broj,int brojlicaT);
    void print();
};

TroDimenzionalni::TroDimenzionalni(char *ime, int broj,int brojlicaT):Oblik(ime){
    brojStrani=broj;
    brojLica= brojlicaT;
}

void TroDimenzionalni::print(){
    printOblik();
    cout<<"So "<<brojStrani<<" razlicni strani i "<<brojLica<<" lica(faces)"<<endl;
}

class Kocka:public TroDimenzionalni{
private:
    char *naziv;
    static int brojKocki;
public:
    Kocka(char *ime,char *naizvO, int broj,int brojLica);
    void printKocka();
};

int Kocka::brojKocki=0;

Kocka::Kocka(char *ime,char *naizvO, int broj,int brojLica):TroDimenzionalni(ime,broj,brojLica){
    naziv = new char[strlen(naizvO)+1];
    strcpy(naziv,naizvO);
    brojKocki++;
}

void Kocka::printKocka(){
    print();
    cout<<"Kockata e "<<naziv<<endl;
}

class Cilindar:public TroDimenzionalni{
private:
    char *naziv;
    static int brojCilindar;
public:
    Cilindar(char *ime,char *naizvO, int broj,int brojLica);
    void printCilindar();
    void printVkupen();
};

int Cilindar::brojCilindar=0;

Cilindar::Cilindar(char *ime,char *naizvO, int broj,int brojLica):TroDimenzionalni(ime,broj,brojLica){
    naziv = new char[strlen(naizvO)+1];
    strcpy(naziv,naizvO);
    brojCilindar++;
}

void Cilindar::printVkupen(){
    cout<<"Vkupno ima napraveno "<<brojCilindar<<" cilindri"<<endl;
}

void Cilindar::printCilindar(){
    print();
    cout<<"Cilindar e so "<<naziv<<endl;
}


int main(){
    char naziv[50] = "razlicni golemina na podlogite";
    char oblik[20] = "cilindar";
    Cilindar c1(oblik,naziv,2,3);
    c1.printCilindar();
    c1.printVkupen();
    cout<<endl;
    char naziv2[50] = "ista golemina na podlogite";
    Cilindar c2(oblik,naziv2,1,3);
    c2.printCilindar();
    c2.printVkupen();
    cout<<endl;
    char naziv3[50] = "ramnostran";
    char oblik2[20] = "triagolnik";
    Triagolnk t1(oblik2,naziv3,1);
    t1.printKlasa();
    t1.printTria();
    cout<<endl;
    char naziv4[50] = "ramnokrak";
    Triagolnk t2(oblik2,naziv4,2);
    t2.printKlasa();
    t2.printTria();
    cout<<endl;



    return 0;
}
