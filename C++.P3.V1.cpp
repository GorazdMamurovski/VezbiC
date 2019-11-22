#include <iostream>

using std::cout;
using std::cin;
using std::endl;
class Kvadar{
private:
    int dolzina;
    int shirina;
    int visina;
public:
    int plostina();
    int volumen();
    bool ifKocka();
    void postaviDimenzii();
    void pecati();
};

void pecatiSiteSoNeSeKocka(Kvadar *k,int n);
void pecatiSite(Kvadar *k,int n);
int main()
{
    Kvadar *k;
    int n;
    int brojKvadrat;
    int flag = 0;
    cout << "Vnesi kolku objekti da ima " << endl;
    cin >> n;
    k = new Kvadar[n];
    for (int i=0;i<n;i++){
        cout << "Vnesi dimenzii za " << i+1 << " kvadrat " << endl;
        k[i].postaviDimenzii();
    }
    int minPlos=100000000;
    int minK;
    for (int i=0;i<n;i++)
    {
        if(!k[i].ifKocka()){
            if(k[i].plostina()<minPlos)
            {
                minPlos=k[i].plostina();
                minK=i;
                flag = 1;
            }
        }
    }
    if(flag==1)
    {
        cout << "Najmala plostina ima kvadarot " << minK+1 << " so plostina " << k[minK].plostina() << endl;
    }

    int meni;
    cout << endl;
    cout << "1.Pecati dimenzii za site objekti" << endl <<"2.Pecati dimenzii za poedinecen objekt";
    cout << endl <<"3.Pecati gi onie koj go zadovoluvaat uslovot da ne se kvadrat" << endl << "4.Kraj" << endl;
    cin >> meni;
    while(meni!=4){
        switch (meni) {
            case 1:
                pecatiSite(k,n);
            break;
            case 2:
                cout << "Vnesi koj kvadrat" << endl;
                cin >> brojKvadrat;
                k[brojKvadrat].pecati();
            break;
            case 3:
                pecatiSiteSoNeSeKocka(k,n);
            break;

        }
        cout << endl;
        cout << "1.Pecati dimenzii za site objekti" << endl <<"2.Pecati dimenzii za poedinecen objekt";
        cout << endl <<"3.Pecati gi onie koj go zadovoluvaat uslovot da ne se kvadrat" << endl << "4.Kraj" << endl;
        cin >> meni;
    }



    delete k;
    return 0;
}

void pecatiSiteSoNeSeKocka(Kvadar *k,int n){
    for (int i=0;i<n;i++){
        if(!k[i].ifKocka())
        {
            cout << "Kvadrat " << i+1 << endl;
            k[i].pecati();
        }

    }
}

void pecatiSite(Kvadar *k,int n){
    for (int i=0;i<n;i++){
        cout << "Kvadrat " << i+1 << endl;
        k[i].pecati();
    }
}

int Kvadar::plostina(){
    return 2*dolzina*shirina + 2*shirina*visina + 2*visina*dolzina;
}

int Kvadar::volumen(){
    return dolzina*shirina*visina;
}

bool Kvadar::ifKocka(){
    if(dolzina==shirina && dolzina==visina)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Kvadar::postaviDimenzii(){
    cout << "dolzina= "; cin >> dolzina;
    cout << "shirina= "; cin >> shirina;
    cout << "visina= "; cin >> visina;
}

void Kvadar::pecati(){
    cout << "dolzinata e: " << dolzina << " shirinata e: " << shirina << " visinata e "<< visina << endl;
}
