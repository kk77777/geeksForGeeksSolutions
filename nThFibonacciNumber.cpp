#include <bits/stdc++.h>
#define ll unsigned long long
#define mod 1000000007
using namespace std;

ll fib(ll n)
{

    ll f[n + 5];
    f[0] = 0;
    f[1] = 1;

    for (auto i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    return f[n];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        cout << fib(n) % mod << "\n";
    }
}