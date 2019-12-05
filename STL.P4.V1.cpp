#include <vector>

#include <iostream>

#include <algorithm>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Imenik{
    char *ime;
    int telBroj;
public:
    Imenik(char *name,int number);
    void pecati();
    char *vratiIme();
};

void Imenik::pecati(){
    cout<<"Ime: "<<ime<<" Telefonski broj: "<<telBroj<<endl;
}

Imenik::Imenik(char *name,int number){
    ime = new char[strlen(name)+1];
    strcpy(ime,name);
    telBroj = number;
}

char * Imenik::vratiIme(){
    return ime;
}

bool sporedi(Imenik imA,Imenik imB){
    char *imeA = new char[strlen(imA.vratiIme())+1];
    strcpy(imeA,imA.vratiIme());
    char *imeB = new char[strlen(imB.vratiIme())+1];
    strcpy(imeB,imB.vratiIme());
    return imeA[0]<=imeB[0];
}

int main(){
    vector <Imenik> imenikA;
    char ime[20] = "Gorazd";
    int broj = 111;
    Imenik imBr(ime,broj);
    imenikA.push_back(imBr);
    char ime2[20] = "Tomislav";
    int broj2=200;
    Imenik imBr2(ime2,broj2);
    imenikA.push_back(imBr2);
    char ime3[20] = "Anja";
    int broj3=3434;
    Imenik imBr3(ime3,broj3);
    imenikA.push_back(imBr3);
    cout<<"Ne sortirani"<<endl;
    for(int i=0;i<imenikA.size();i++){
        imenikA[i].pecati();
    }
    cout<<"Sortirani"<<endl;
    sort(imenikA.begin(),imenikA.end(),sporedi);
    for(int i=0;i<imenikA.size();i++){
        imenikA[i].pecati();
    }

    return 0;
}
