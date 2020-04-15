#include <bits/stdc++.h>
#define ll long int
using namespace std;

void solve(vector<ll> &a, ll n)
{
    sort(a.begin(), a.end());
    ll cnt = 0;
    for (ll i = n - 1; i > 1; i--)
    {
        ll j = 0, k = n - 2;
        while (j < k)
        {
            if (a[j] + a[k] == a[i])
            {
                cnt++;
                j++;
                k--;
            }
            else if (a[j] + a[k] < a[i])
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    if (cnt == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << cnt << "\n";
    }
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
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        solve(v, n);
    }
}