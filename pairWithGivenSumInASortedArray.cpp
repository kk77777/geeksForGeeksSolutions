#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long int

using namespace std;

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        bool flag = 0;
        vector<ll> v;
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll k;
        cin >> k;
        for (ll i = 0; i < n - 1; i++)
        {
            ll s = i + 1, e = n - 1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (v[mid] + v[i] == k)
                {
                    flag = 1;
                    cout << v[i] << " " << v[mid] << " " << k << "\n";
                    break;
                }
                else if (v[mid] + v[i] > k)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
        }
        if (!flag)
            cout << -1 << "\n";
    }
}