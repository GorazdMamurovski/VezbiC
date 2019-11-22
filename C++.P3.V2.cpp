#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;


class Stedac
{
 public:
        void vnesi_podatoci();
        void prikazi_podatoci();
        void uplata(unsigned long i);
        void isplata(unsigned long i);
        bool ime(std::string ime);
        long sostojba();

  private:
        int broj;
        char imeprezime[30], adresa[50];
        long saldo;
};

void pecatiSite(Stedac *s,int n);

int main()
{
    Stedac *s;
    int n=0;
    s = new Stedac[20];
    int meni;
    cout << endl;
    cout << "1.Prikaz na podatoci" << endl << "2.Uplata na sredstva";
    cout << endl <<"3.Isplata na sredstva" << endl << "4.Prikaz na saldoto" << endl <<"5.Vnesi nov shtedasc" << endl;
    cout << "6.Kraj" << endl;
    cin >> meni;
    std::string tes;
    unsigned long int uplata;
    while(meni!=6){
            switch (meni) {
                case 1:
                    if(n==0)
                    {
                        cout << "Nema stedaci";
                    }
                    else
                    {
                        pecatiSite(s,n);
                    }
                    break;
                case 2:
                    cout << "Vnesi ime na stedacot " << endl; cin >>tes;
                    for(int i=0;i<n;i++)
                    {
                        if(s[i].ime(tes)){
                            cout << "Vnesi uplata "<<endl;cin>>uplata;
                            s[i].uplata(uplata);
                        }
                    }
                    break;
                case 3:
                    cout << "Vnesi ime na stedacot " << endl; cin >>tes;
                    for(int i=0;i<n;i++)
                    {
                        if(s[i].ime(tes)){
                            cout << "Vnesi isplata "<<endl;cin>>uplata;
                            s[i].isplata(uplata);
                        }
                    }

                    break;
                case 4:
                cout << "Vnesi ime na stedacot " << endl; cin >>tes;
                for(int i=0;i<n;i++)
                {
                    if(s[i].ime(tes)){
                        cout << "sostojba na saldoto e " <<  s[i].sostojba();
                    }
                }

                    break;
                case 5:
                    s[n].vnesi_podatoci();
                    n++;
                    break;
            default:
                cout << "Gresen vlez " <<endl;
                break;

            }
            cout << endl;
            cout << "1.Prikaz na podatoci" << endl << "2.Uplata na sredstva";
            cout << endl <<"3.Isplata na sredstva" << endl << "4.Prikaz na saldoto" << endl <<"5.Vnesi nov shtedasc" << endl;
           cin >> meni;
        }

    return 0;
}
void pecatiSite(Stedac *s,int n){
    for(int i=0;i<n;i++)
    {
        s[i].prikazi_podatoci();
    }
}

bool Stedac::ime(std::string ime){

    if(ime == imeprezime){
        return true;
    }
    else
    {
        return false;
    }
}

void Stedac::vnesi_podatoci(){
    srand (time(NULL));
    broj = rand()%10000;
    cout << "Vnesi ime i prezime " << endl; cin >>imeprezime;
    cout << "Vnesi adresa " << endl; cin>>adresa;
    saldo = 0;
}

void Stedac::prikazi_podatoci(){
    cout << "Korisnik " << imeprezime << " broj " << broj <<" adresa " << adresa << " saldo " << saldo << endl;
}

void Stedac::uplata(unsigned long i)
{
    saldo+=i;
}

void Stedac::isplata(unsigned long i)
{
    if(saldo < i)
    {
        cout << "nemate dovolno pari za isplata";
    }
    else
    {
        saldo-=i;
    }
}

long Stedac::sostojba(){
    return saldo;
}
