#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<long long, long long> mem;

long long memoization(int n)
{
    long long r = mem[n];
    if (n == 0)
        return 0;
    else if (r == 0)
    {
        r = max((long long)n, (memoization(n/2) + memoization(n/3) + memoization(n/4)));
        mem[n] = r;
    }
    return r;
}

int main()
{
    int num;
    while(cin >> num)
    {
        cout << memoization(num) << endl;
    }
    return 0;
}