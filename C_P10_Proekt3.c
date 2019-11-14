/* Program p09_15.c
   Povekjenamenski sortirachki program
   koj koristi pokazhuvachi kon funkcii */
#include <stdio.h>
#include <stdlib.h>
void VnesiOceni(int Oceni[10][5]);
void PecatiOceni(int Oceni[10][5],const char *studenti[],const char *predmeti[]);
void NajdiMax(int Oceni[10][5],const char *studenti[],const char *predmeti[]);
void NajdiMin(int Oceni[10][5],const char *studenti[],const char *predmeti[]);
void Prosek(int Oceni[10][5],const char *studenti[],const char *predmeti[]);
int main()
{
    const char* studenti[10] = {"Gorazd","Ivan","Todor","Viktor","Nikola","Stefan","Maja","Georgi","Emil","Matea"};
    const char* predmeti[5] = {"VIS","K2","VI","OOP","DM2"};
    void (*f[ 4 ])( int,const char,const char ) = { PecatiOceni, NajdiMax, NajdiMin,Prosek };
    int Oceni[10][5] = { 0 };
    int meni;
    VnesiOceni(Oceni);
    printf("0 Ispechati ja nizata so oceni\n1 Najdi ja maksimalnataocena\n2 Najdi ja minimalnata ocena\n3 Ispecati ja prosechnata ocena za sekoja student\n4 Kraj \n");
    scanf("%d",&meni);
    while(meni>=0 && meni<4){
        (*f[meni])(Oceni,studenti,predmeti);
        scanf("%d",&meni);
    }
    printf( "Izvrshuvanjeto na programata zavrshi.\n" );
    return 0;
}
void VnesiOceni(int Oceni[10][5]){
    srand(time(NULL));
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            Oceni[i][j] = (rand() % 5) + 5;
        }
    }
}
void PecatiOceni(int Oceni[10][5],const char *studenti[],const char *predmeti[])
{
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            printf("%s za predmetot %s ima %d \n",studenti[i],predmeti[j],Oceni[i][j]);
        }
    }

}
void NajdiMax(int Oceni[10][5],const char *studenti[],const char *predmeti[]){
    int max,najgolem;
    max=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            if(Oceni[i][j]>max){
                max=Oceni[i][j];
                najgolem = j;
            }
        }
        printf("%s najgolema ocena iima na predmetot %s so %d \n",studenti[i],predmeti[najgolem],Oceni[i][najgolem]);
        max = 0;
    }
}
void NajdiMin(int Oceni[10][5],const char *studenti[],const char *predmeti[]){
    int min,najmal;
    min=100;
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            if(Oceni[i][j]<min){
                min=Oceni[i][j];
                najmal = j;
            }
        }
        printf("%s najmala ocena iima na predmetot %s so %d \n",studenti[i],predmeti[najmal],Oceni[i][najmal]);
        min = 100;
    }
}
void Prosek(int Oceni[10][5],const char *studenti[],const char *predmeti[]){
    float prosek;
    prosek=0.0;
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            prosek+=Oceni[i][j];
        }
        prosek=prosek/5;
        printf("Na studentot %s prosek mu e %.2f\n",studenti[i],prosek);
        prosek=0;
    }
}
