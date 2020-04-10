#include <bits/stdc++.h>
#define ll long int
using namespace std;

ll solve(vector<ll> &a, ll n)
{

    vector<ll> mxl(n, 0);
    vector<ll> mxr(n, 0);

    mxl[0] = a[0];

    for (ll i = 1; i < n; i++)
    {
        mxl[i] = max(mxl[i - 1], a[i]);
    }

    mxr[n - 1] = a[n - 1];

    for (ll i = n - 2; i >= 0; i--)
    {
        mxr[i] = max(mxr[i + 1], a[i]);
    }
    vector<ll> w(n, 0);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        w[i] = min(mxl[i], mxr[i]) - a[i];
        sum += w[i];
    }
    return sum;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vector<ll> a;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        cout << solve(a, n) << "\n";
    }
}