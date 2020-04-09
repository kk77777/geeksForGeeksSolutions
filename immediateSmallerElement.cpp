#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(vector<ll> &a, ll n)
{
    vector<ll> v;
    stack<ll> s;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }

        else if (!s.empty() && s.top() < a[i])
        {
            v.push_back(s.top());
        }
        else
        {
            v.push_back(-1);
        }
        s.push(a[i]);
    }

    reverse(v.begin(), v.end());
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
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
        solve(a, n);
    }
}