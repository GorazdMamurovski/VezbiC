#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::hex;
using std::dec;
using std::oct;
#include <iomanip>
#include <cmath>
using std::setprecision;
using std::setbase;
using std::fixed;



int main(){
    int n,m;
    cout<<"Vnesi n i m"<<endl;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cout.width(m);
        cout<<i<<" ";
        cout.width(m);
        cout<<i*i<<" ";
        cout.width(m);
        cout<<setprecision( 4 )<<sqrt(i)<<" ";
        cout.width(m);
        cout<<setprecision( 4 )<<cbrt(i)<<endl;
    }

    return 0;
}
