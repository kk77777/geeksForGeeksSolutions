#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int solve(vector<ll> &v, ll n, ll s)
{
    ll csum = v[0];
    ll start = 0;
    for (ll i = 1; i <= n; i++)
    {
        while (csum > s && start < i - 1)
        {
            csum = csum - v[start];
            start++;
        }
        if (csum == s)
        {
            cout << start + 1 << " " << i << "\n";
            return 1;
        }
        if (i < n)
        {
            csum = csum + v[i];
        }
    }
    cout << -1 << "\n";
    return 0;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, s;
        cin >> n >> s;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        solve(v, n, s);
    }
    return 0;
}