#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

vector<int> t(100000, 0);
int solve()
{
    t[0] = 1;
    t[1] = 1;
    for (auto i = 2; i <= 100000; i++)
    {
        t[i] = (t[i - 1] % mod + t[i - 2] % mod) % mod;
    }
    return 0;
}

int main()
{
    ll tc;
    cin >> tc;
    solve();
    while (tc--)
    {
        ll n;
        cin >> n;
        cout << t[n] << "\n";
    }
}