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
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll s = 0, l = n - 1;
        while (s <= l)
        {
            if (s == l)
            {
                cout << v[l] << " ";
                s++;
            }
            else
            {
                cout << v[l] << " ";
                cout << v[s] << " ";
                s++;
                l--;
            }
        }
        cout << "\n";
    }
}