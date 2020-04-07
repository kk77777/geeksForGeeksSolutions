#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll res = -1, pos = -1;
ll solve(vector<ll> &a, ll l, ll r, ll x)
{
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (a[mid] <= x)
        {
            if (a[mid] > res)
            {
                res = a[mid];
                pos = mid;
                l = mid + 1;
            }
        }
        else if (a[mid] > x)
        {
            r = mid - 1;
        }
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        res = -1;
        pos = -1;
        ll n, x;
        cin >> n >> x;
        vector<ll> a;
        for (ll i = 0; i < n; i++)
        {
            ll y;
            cin >> y;
            a.push_back(y);
        }
        cout << solve(a, 0, n - 1, x) << "\n";
    }
    return 0;
}