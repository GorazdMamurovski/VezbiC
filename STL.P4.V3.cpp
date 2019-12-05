#include <vector>

#include <iostream>
#include <algorithm>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include <iterator>


bool sporedi(char * imA,char * imB){
    char *imeA = new char[strlen(imA)+1];
    strcpy(imeA,imA);
    char *imeB = new char[strlen(imB)+1];
    strcpy(imeB,imB);
    return imeA[0]<=imeB[0];
}


int main(){
    vector <char *> zborovi;
    char input[100];
    char *podeleno;
    int flag = 0;
    cin.getline(input,sizeof(input));
    podeleno = strtok(input," ");
    zborovi.push_back(podeleno);
    while(podeleno != NULL){
        for(int i=0;i<zborovi.size();i++){
            if(!strcmp(zborovi[i],podeleno)){
                flag=1;
            }
        }
        if(flag ==0 ){
            zborovi.push_back(podeleno);

        }
        flag =0;
        podeleno = strtok(NULL," ");

    }

    sort(zborovi.begin(),zborovi.end(),sporedi);

    for(int i=0;i<zborovi.size();i++){
        cout<<zborovi[i]<<endl;
    }

    return 0;
}
