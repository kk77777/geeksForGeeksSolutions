#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll fib(int x)
{
    ll a[x + 5];
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= x; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[x];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w;
        cin >> w;
        cout << fib(w) << "\n";
    }
}