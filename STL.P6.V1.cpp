#include <map>
#include <iostream>
#include <string>


using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

typedef std::multimap< string, int, std::less< string > > mmid;

int main(){
    mmid stedaci;
    int meni;
    char ime[20];
    char prebaraj[20];
    double uplata;
    cout<<"1.Dodaj uplata 2.Prikazi uplata za daden stedac 3.Kraj";
    cout<<endl;
    cin>>meni;
    while(meni!=3){
        switch (meni) {
        case 1:
            cout<<"Vnesi ime i uplata"<<endl;
            cin>>ime;
            cin>>uplata;
            stedaci.insert(mmid::value_type(ime,uplata));
            break;
        case 2:
            cout<<"Vnesi stedac"<<endl;
            cin>>prebaraj;
            for ( mmid::const_iterator iter = stedaci.begin();iter != stedaci.end(); ++iter ){
                string b = iter->first;
                if(!strcmp(prebaraj,b.c_str())){
                    cout << iter->first << '\t'<< iter->second << '\n';
                }
            }
            break;
        }
        cout<<"1.Dodaj uplata 2.Prikazi uplata za daden stedac 3.Kraj";
        cout<<endl;
        cin>>meni;
    }
    return 0;
}
