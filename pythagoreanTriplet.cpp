#include <bits/stdc++.h>
using namespace std;
#define ll long int

bool solve(vector<ll> v, ll n)
{
    for (auto i = 0; i < n; i++)
    {
        ll temp = v[i] * v[i];
        v[i] = temp;
    }
    sort(v.begin(), v.end());
    for (auto i = n - 1; i >= 2; i--)
    {
        ll a = 0;
        ll b = i - 1;
        while (a < b)
        {
            if (v[a] + v[b] == v[i])
            {
                return true;
            }
            if (v[a] + v[b] < v[i])
            {
                a++;
            }
            else
            {
                b--;
            }
        }
    }
    return false;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        solve(v, n) ? cout << "Yes\n" : cout << "No\n";
    }
}