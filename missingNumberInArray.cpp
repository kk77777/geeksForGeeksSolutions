#include <bits/stdc++.h>
using namespace std;
#define ll long int

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        ll asum = 0;
        for (auto i = 1; i < n; i++)
        {
            ll x;
            cin >> x;
            asum += x;
        }
        ll rsum = n * (n + 1) / 2;
        cout << rsum - asum << "\n";
    }
}