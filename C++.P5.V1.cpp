#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;

class Date {
public:
   Date( int = 1, int = 1, int = 2007 );
   void print() const;
   int den();
   int mesec();
   int godina();
private:
   int month;
   int day;
   int year;
   int checkDay( int );
};

int Date::den(){
    return day;
}

int Date::mesec(){
    return month;
}
int Date::godina(){
    return year;
}

Date::Date( int mn, int dy, int yr )
{
   if ( mn > 0 && mn <= 12 )
      month = mn;
   else {
      month = 1;
      cout << "Mesec " << mn << " ne postoi. Postavi go month na 1.\n";
   }

   year = yr;
   day = checkDay( dy );

}

int Date::checkDay( int testDay )
{
   static const int daysPerMonth[ 13 ] =
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   if ( month == 2 &&
        testDay == 29 &&
        ( year % 400 == 0 ||
         ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

   cout << "Denot " << testDay << " e greshen. Postavi vrednost za day na 1.\n";

   return 1;
}

void Date::print() const
   { cout << month << '/' << day << '/' << year << endl; }



class Zivotno{
private:
    Date datugRaganje;
    Date datumZoloska;
    Date poslednaVakcina;
    char ime[25];
    char tip;
    char pol;
public:
    Zivotno(char *ime=NULL,char tip=' ',char pol=' ',int a=1,int b=1,int c=1,int a1=1,int b1=1,int c1=1);
    void prikaziPodatoci();
    void presmetajVakcina();
    char vratiTip();

};

void Zivotno::presmetajVakcina(){
     Date datumVakcina = Date(11,24,2019);
     if(tip=='c')
     {
         if(poslednaVakcina.godina()+1==datumVakcina.godina()){
             if(poslednaVakcina.mesec()==datumVakcina.mesec()){
                 if(poslednaVakcina.den()-datumVakcina.den()<7)
                 {
                     cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
                 }
             }
         }
         else{
             if(poslednaVakcina.godina()+1<datumVakcina.godina())
             {
                 cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
             }
         }
     }
     if(tip=='p'){
         if(poslednaVakcina.godina()+1==datumVakcina.godina()){
             if(poslednaVakcina.mesec()==datumVakcina.mesec()){
                 if(poslednaVakcina.den()-datumVakcina.den()<7)
                 {
                     cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
                 }
             }
         }
         else{
             if(poslednaVakcina.godina()+1<datumVakcina.godina())
             {
                 cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
             }
             if(poslednaVakcina.godina()==datumVakcina.godina())
             {
                 if(poslednaVakcina.mesec()+6<datumVakcina.mesec())
                 {
                     cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
                 }
             }
         }
     }
     if(tip=='b'){
         if(poslednaVakcina.godina()+1==datumVakcina.godina()){
             if(poslednaVakcina.mesec()==datumVakcina.mesec()){
                 if(poslednaVakcina.den()-datumVakcina.den()<7)
                 {
                     cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
                 }
             }
         }
         else{
             if(poslednaVakcina.godina()+1<datumVakcina.godina())
             {
                 cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
             }
             if(poslednaVakcina.godina()==datumVakcina.godina())
             {
                 if(poslednaVakcina.mesec()+8<datumVakcina.mesec())
                 {
                     cout<<"Zivonoto "<< ime <<" e za vakcinacija"<<endl;
                 }
             }
         }
     }



}

char Zivotno::vratiTip(){
    return tip;
}

Zivotno::Zivotno(char *imeZ,char tipZ,char polZ,int a,int b,int c,int a1,int b1,int c1):datugRaganje(a,b,c),datumZoloska(a1,b1,c1),poslednaVakcina(a1,b1,c1){
    if(imeZ==NULL)
    {
        char zbor[20] ="asd";
        imeZ=zbor;
    }
    strncpy_s( ime, imeZ, 25);
    tip=tipZ;
    pol=polZ;
}

void Zivotno::prikaziPodatoci(){
    cout << "Ime: " << ime << endl << "Tip: " << tip << endl << "Pol: " << pol << endl;
    cout << "Datum ragjanje: " ;
    datugRaganje.print();
    cout << "Datum zoloska ";
    datumZoloska.print();
    cout << "Datum vakcina ";
    poslednaVakcina.print();
}

int main()
{
    int meni;
    Zivotno zivotni[10];
    int i=0;
    int denR,mesecR,godinaR,denD,mesecD,godinaD;

    char imeG[25];
    char *ime;
    char pol,tip;
    char vnesiTip;
    cout << "izberi: "<<endl<<"1.Dodadi zivotno 2.Brojna sostojba 3.Zivotni vo dadena grupa 4.Cela lista 5.Zivotni so treba da se vakciniraat 6.Izlez"<<endl;
    cin >> meni;
    while(meni!=6){
        switch (meni) {
        case 1:
            cout << "Vnesi ime" << endl; cin>>imeG;
            ime=imeG;
            cout << "Vnesi Tip(p-ptica,v-vlekac,c-cicac)" <<endl; cin>>tip;
            cout << "Vnesi Pol(m-maski,z-zenski)" <<endl; cin>>pol;
            cout << "Vnesi den na datum na ragjanje" << endl; cin>>denR;
            cout << "Vnesi mesce na datum na ragjanje" << endl; cin>>mesecR;
            cout << "Vnesi godina na datum na ragjanje" << endl; cin>>godinaR;
            cout << "Vnesi den na datum na donesuvanje" << endl; cin>>denD;
            cout << "Vnesi mesec na datum na donesuvanje" << endl; cin>>mesecD;
            cout << "Vnesi godina na datum na donesuvanje" << endl; cin>>godinaD;
            zivotni[i] = Zivotno(ime,tip,pol,denR,mesecR,godinaR,denD,mesecD,godinaD);
            i++;
            break;
        case 2:
            cout <<"Brojot za zivotni e: " << i <<endl;
            break;
        case 3:
            cout <<"Vnesi tip na zivotno" ; cin >> vnesiTip;
            for(int j=0;j<i;j++)
            {
                if(zivotni[j].vratiTip()==vnesiTip){
                    zivotni[j].prikaziPodatoci();
                }
            }
            break;
        case 4:
            for(int j=0;j<i;j++){
                zivotni[j].prikaziPodatoci();
            }
            break;
        case 5:
            for(int j=0;j<i;j++){
                zivotni[j].presmetajVakcina();
            }
            break;
        }
        cout << "izberi: "<<endl<<"1.Dodadi zivotno 2.Brojna sostojba 3.Zivotni vo dadena grupa 4.Cela lista 5.Zivotni so treba da se vakciniraat 6.Izlez"<<endl;
        cin >> meni;
    }

    return 0;
}

