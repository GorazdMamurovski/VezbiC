#include <map>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <iterator>
#include <time.h>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int i = 0;
int j = 0;
int dvaK =0;
int cetiriK =0;
int sestK =0;
int osumK =0;
int desetK=0;
bool paren(int x){
    if(x%2==0){
        i++;
        return true;
    }
    else{
        return false;
    }
}

bool pomalOddvaK(int x){
    if(x<2000){
        j++;
        return true;
    }
    else{
        return false;
    }
}

bool od2k(int x){
    if(x>2000){
        dvaK++;
        return true;
    }
    else{
        return false;
    }
}

bool od4k(int x){
    if(x>4000){
        cetiriK++;
        return true;
    }
    else{
        return false;
    }
}

bool od6k(int x){
    if(x>6000){
        sestK++;
        return true;
    }
    else{
        return false;
    }
}

bool od8k(int x){
    if(x>8000){
        osumK++;
        return true;
    }
    else{
        return false;
    }
}


int main(){
    srand(time(0));
    unsigned short int a[10000],x;
    for(x=0;x<10000;x++){
      a[x]=rand()%9999;
    }

    const size_t SIZE = sizeof a / sizeof a[0];
    int b[SIZE];
    ostream_iterator<int> output(cout, "\n") ;

    copy_if(a,a+SIZE,b,paren);

    copy_if(a,a+SIZE,b,pomalOddvaK);
    copy_if(a,a+SIZE,b,od2k);
    copy_if(a,a+SIZE,b,od4k);
    copy_if(a,a+SIZE,b,od6k);
    copy_if(a,a+SIZE,b,od8k);
    int zbir=0;
    for(int i=0;i<10000;i++){
        zbir+=a[i];
    }
    zbir=zbir/10000;

    cout<<"Parni broevi ima "<<i<<endl;
    cout<<"Broevi pomali od 2k ima "<<j<<endl;
    cout<<"Broj na broevi od 2k do 4k ima "<<dvaK-cetiriK<<endl;
    cout<<"Broj na broevi od 4k do 6k ima "<<cetiriK-sestK<<endl;
    cout<<"Broj na broevi od 6k do 8k ima "<<sestK-osumK<<endl;
    cout<<"Broj na broevi od 8k do 10k ima "<<osumK<<endl;
    cout<<"Sredna vrednost na elementite e "<<zbir<<endl;
    return 0;
}
