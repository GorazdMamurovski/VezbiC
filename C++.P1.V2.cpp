#include <iostream>

using namespace std;
inline float tripleCallByValue(float a)
{
    return a*3;
}
inline void tripleCallByReference(float &a)
{
    a=a*3;
}
int main()
{
    float a;
    cin >> a;
    cout << a << " " << tripleCallByValue(a);
    cout << endl;
    cout << a << " ";
    tripleCallByReference(a);
    cout << a;
    cout << endl;

}
