#include <bits/stdc++.h>
using namespace std;

#define ll long int

int index(vector<ll> v, ll n, ll k)
{
    ll l = 0, h = n - 1;
    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        if (v[mid] == k)
            return mid;
        else if (v[l] <= v[mid])
        {
            if (v[l] <= k && v[mid] >= k)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (v[mid] <= k && v[h] >= k)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }
    return -1;
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
        ll k;
        cin >> k;

        cout << index(v, n, k) << "\n";
    }
}