#include <iostream>
#include <vector>
#include <algorithm>
#define ll long int
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

using namespace std;

int msis(vector<ll> &v, int n)
{
    if (n == 1)
        return v[0];
    vector<ll> t(n, 0);
    for (int i = 0; i < n; i++)
    {
        t[i] = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                t[i] = max(t[i], v[i] + t[j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, t[i]);
    }
    return ans;
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
        cout << msis(v, n) << "\n";
    }
}