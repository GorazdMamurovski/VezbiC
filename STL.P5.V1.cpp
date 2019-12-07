#include <vector>

#include <iostream>
#include <algorithm>



using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

#include <iterator>


template <class T>
void palindrom(std::vector<T> vektor){
    int flag = 1;
    int s;
    for(int i=0;i<vektor.size()/2;i++){
        s=vektor[vektor.size()-i-1];
        if(vektor[i]!=vektor[s]){
            cout<<"Brojot ne e palindrom"<<endl;
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout<<"Brojot e palindrom"<<endl;
    }

}

int main(){
    int array[5]={0,1,2,3,4};
    int array2[5]={1,2,3,2,1};
    std::vector<int> vektor(array,array+5);
    std::vector<int> vektor2(array2,array+5);
    float arrayF[5]={0.1,1.2,2.3,3.4,4.5};
    float arrayF2[5]={1.1,2.2,3.3,2.2,1.1};
    std::vector<int> vektorF(array,array+5);
    std::vector<int> vektorF2(array2,array+5);
    std::ostream_iterator< int > output( cout, " " );
    palindrom(vektor);
    palindrom(vektor2);
    palindrom(vektorF);
    palindrom(vektorF2);
    cout<<endl;

    return 0;
}
