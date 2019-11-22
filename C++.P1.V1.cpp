#include <iostream>

using namespace std;
inline float plostinaKrug(float a)
{
    return a*a*3.14;
}

int main()
{
    float a;
    cin >> a;
    cout << plostinaKrug(a);
    cout << endl;
    return 0;
}
