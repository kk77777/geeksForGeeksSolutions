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
        vector<ll> v;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll csum = v[0];
        ll maxm = v[0];
        ll res = v[0];
        for (ll i = 1; i < n; i++)
        {
            csum = max(csum + v[i], v[i]);
            if (csum > res)
            {
                res = csum;
            }
        }
        cout << res << "\n";
    }
}