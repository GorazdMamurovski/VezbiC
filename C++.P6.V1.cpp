#include <iostream>

using std::cout;
using std::endl;

#include <cstring>
#include <cassert>

class Covek{
private:
    char *ime;
    char *prezime;
    char *adresa;
    long int broj;
public:
    Covek(const char*,const char*,const char*,int);
    ~Covek();
};

Covek::Covek(const char *imeC,const char *prezimeC,const char* adresaC,int brojC){
    ime = new char[strlen(imeC)+1];
    assert(ime!=0);
    strcpy(ime,imeC);
    prezime = new char[strlen(prezimeC)+1];
    assert(prezime!=0);
    strcpy(prezime,prezimeC);
    adresa = new char[strlen(adresaC)+1];
    assert(adresa!=0);
    strcpy(adresa,adresaC);
    broj=brojC;
}

Covek::~Covek(){
    delete [] ime;
    delete [] prezime;
    delete [] adresa;
}

class Stedac{
private:
    Covek lice;
    int bilans;
    int kredit;
    static int brojLica;
    static float kamata;
public:
    Stedac(const char*,const char*,const char*,int);
    ~Stedac();
    static int brojLice();
    void vnesiBilans(int bilansV);
    void zemiKredit(int kreditV);
    static float kamataPrint();
};

void Stedac::vnesiBilans(int bilansV){
    bilans+=bilansV;
}

void Stedac::zemiKredit(int kreditV){
    kredit+=kreditV;
    kamata=kamata+(kredit*0.05);
}

int Stedac::brojLica=0;
float Stedac::kamata=0;

int Stedac::brojLice(){
    return brojLica;
}

float Stedac::kamataPrint(){
    return kamata;
}

Stedac::Stedac(const char *imeC,const char *prezimeC,const char* adresaC,int brojC):lice(imeC,prezimeC, adresaC,brojC){
    brojLica++;
    bilans=0;
    kredit=0;

}

Stedac::~Stedac(){
    brojLica--;
}

int main(){
    cout << "Broj na stedaci na pocetok " <<Stedac::brojLice() <<endl;
    char ime[20]="Gorazd";
    char prezime[20]="Mamurovski";
    char adresa[20]="Karposh";
    int tBroj=123,bilans=100;
    Stedac *gogo = new Stedac(ime,prezime,adresa,tBroj);
    gogo->vnesiBilans(bilans);
    gogo->zemiKredit(1000);
    cout << "Kamata na liceto Gogo " << gogo->kamataPrint()<<endl;
    cout << "Broj na stedaci posle inicializiranje " << Stedac::brojLice() <<endl;

    delete gogo;
    cout <<"Broj na stedaci posle brisenje "<< Stedac::brojLice() <<endl;
    return 0;




}
