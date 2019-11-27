
#include <cstring>
#include <cassert>
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

class Vraboten{
private:
    char *ime;
    char *prezime;
    int godVrab;
public:
    Vraboten(char *name,char *surname);
    void postavi(int god);
    void prikaziPod();
};

char prazno[2]=" ";

Vraboten::Vraboten(char *name,char *surname){
    ime = new char[strlen(name)+1];
    prezime = new char[strlen(surname)+1];
    strcpy(ime,name);
    strcpy(prezime,surname);
    godVrab=2000;
}

void Vraboten::postavi(int god){
    godVrab=god;
}

void Vraboten::prikaziPod(){
    cout<<"Vraboten so ime "<<ime<<" prezime "<<prezime<<" i godina na vrabotuvanje "<<godVrab<<endl;
}

class Profesor: public Vraboten{
protected:
    char *zvanje;
    char *oblast;
    int brojPredmeti;
public:
    Profesor();
    Profesor(char *name,char *surname,char *zvanjeP,char *oblastP,int brojP);
    void prikaziPodatoci();
};

void Profesor::prikaziPodatoci(){
    prikaziPod();
    cout<<"Po zvanje "<<zvanje<<" vo oblast "<<oblast<<" so broj na predmeti "<<brojPredmeti<<endl;
}

Profesor::Profesor():Vraboten(prazno,prazno){
    zvanje=prazno;
    oblast=prazno;
    brojPredmeti=0;
}

Profesor::Profesor(char *name,char *surname,char *zvanjeP,char *oblastP,int brojP):Vraboten(name,surname){
    zvanje = new char[strlen(zvanjeP)+1];
    oblast = new char[strlen(oblastP)+1];
    strcpy(zvanje,zvanjeP);
    strcpy(oblast,oblastP);
    brojPredmeti=brojP;
}

class Asistent: public Vraboten{
protected:
    char *zvanje;
    char *mentor;
    int brojPredmeti;
public:
    Asistent();
    Asistent(char *name,char *surname,char *zvanjeP,char *mentorP,int brojP);
    void prikaziPodatoci();
};

Asistent::Asistent(char *name,char *surname,char *zvanjeP,char *mentorP,int brojP):Vraboten(name,surname){
    zvanje = new char[strlen(zvanjeP)+1];
    mentor = new char[strlen(mentorP)+1];
    strcpy(zvanje,zvanjeP);
    strcpy(mentor,mentorP);
    brojPredmeti=brojP;
}

Asistent::Asistent():Vraboten(prazno,prazno){
    zvanje=prazno;
    mentor=prazno;
    brojPredmeti=0;
}

void Asistent::prikaziPodatoci(){
    prikaziPod();
    cout<<"Po zvanje "<<zvanje<<" so mentor "<<mentor<<" so broj na predmeti "<<brojPredmeti<<endl;
}

class Demonstrator: public Vraboten{
protected:
    int rabotnoVremeOd;
    int rabotnoVremeDo;
public:
    Demonstrator();
    Demonstrator(char *name,char *surname,int rabotnoOd,int rabotnoDo);
    void prikaziPodatoci();
};

Demonstrator::Demonstrator(char *name,char *surname,int rabotnoOd,int rabotnoDo):Vraboten(name,surname){
    rabotnoVremeOd=rabotnoOd;
    rabotnoVremeDo=rabotnoDo;
}

Demonstrator::Demonstrator():Vraboten(prazno,prazno){
    rabotnoVremeDo=0;
    rabotnoVremeOd=0;
}

void Demonstrator::prikaziPodatoci(){
    prikaziPod();
    cout<<"So rabotno vreme od "<<rabotnoVremeOd<<" do "<<rabotnoVremeDo<<endl;
}

int main(){
    int meni,vnVrab,brojCasovi;
    int p=0;
    int d=0;
    int a=0;
    int vremeOd,vremeDo;
    char ime[20];
    char prezime[20];
    char zvanje[20];
    char oblast[20];
    char mentor[20];
    Profesor profesori[20];
    Asistent *asistenti;
    asistenti = new Asistent[20];
    Demonstrator *demonstratori;
    demonstratori = new Demonstrator[20];
    cout<<"1.Dodadi nov vraboten 2.Prikazi lista 3.kraj";
    cin>>meni;
    while(meni!=3){
        switch (meni)
        {
        case 1:
            cout<<"vnesi Ime: ";
            cin>>ime;
            cout<<endl;
            cout<<"vnesi Prezime: ";
            cin>>prezime;
            cout<<endl;
            cout<<"vnesi 1 za Profesor, 2 za asistent i 3 za demonstrator"<<endl;
            cin>>vnVrab;
            if(vnVrab==1){
                cout<<"Vnesi zvanje ";
                cin>>zvanje;
                cout<<endl;
                cout<<"Vnesi oblast ";
                cin>>oblast;
                cout<<endl;
                cout<<"Vnesi broj na casovi ";
                cin>>brojCasovi;
                cout<<endl;
                Profesor gogo(ime,prezime,zvanje,oblast,brojCasovi);
                profesori[p] = gogo;
                p++;
            }
            if(vnVrab==2){
                cout<<"Vnesi zvanje ";
                cin>>zvanje;
                cout<<endl;
                cout<<"Vnesi mentor ";
                cin>>mentor;
                cout<<endl;
                cout<<"Vnesi broj na casovi ";
                cin>>brojCasovi;
                cout<<endl;
                Asistent mamur(ime,prezime,zvanje,mentor,brojCasovi);
                asistenti[a] = mamur;
                a++;
            }
            if(vnVrab==3){
                cout<<"Vnesi vreme od ";
                cin>>vremeOd;
                cout<<endl;
                cout<<"Vnesi vreme do ";
                cin>>vremeDo;
                cout<<endl;
                Demonstrator tod(ime,prezime,vremeOd,vremeDo);
                demonstratori[d] = tod;
                d++;
            }
            break;

        case 2:
            cout<<"Vnesi 1 za profesori 2 za asistenti 3 za demonstratori"<<endl;
            cin>>vnVrab;
            if(vnVrab==1){
                for(int i=0;i<p;i++)
                {
                    profesori[i].prikaziPodatoci();
                }
            }
            if(vnVrab==2){
                for(int i=0;i<a;i++)
                {
                    asistenti[i].prikaziPodatoci();
                }
            }
            if(vnVrab==3){
                for(int i=0;i<d;i++)
                {
                    demonstratori[i].prikaziPodatoci();
                }
            }
            break;
        }
        cout<<"1.Dodadi nov vraboten 2.Prikazi lista 3.kraj";
        cin>>meni;
    }
    return 0;
}
