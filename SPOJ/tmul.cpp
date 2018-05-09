#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long x1, x2;
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> x2;
        cout << x1 * x2 << endl;
    }
    return 0;
}