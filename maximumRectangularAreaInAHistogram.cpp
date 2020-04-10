#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(vector<ll> a, ll n)
{
    vector<ll> left;
    vector<ll> right;
    stack<pair<ll, ll>> s;
    stack<pair<ll, ll>> t;

    for (ll i = 0; i < n; i++)
    {
        if (s.empty())
        {
            left.push_back(-1);
        }
        else
        {
            while (!s.empty() && s.top().first >= a[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                left.push_back(s.top().second);
            }
            else
            {
                left.push_back(-1);
            }
        }
        s.push({a[i], i});
    }

    ll psudo = n;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (t.empty())
        {
            right.push_back(psudo);
        }
        else
        {
            while (!t.empty() && t.top().first >= a[i])
            {
                t.pop();
            }
            if (!t.empty())
            {
                right.push_back(t.top().second);
            }
            else
            {
                right.push_back(psudo);
            }
        }
        t.push({a[i], i});
    }
    reverse(right.begin(), right.end());

    vector<ll> width;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        x = right[i] - left[i] - 1;
        width.push_back(x);
    }
    ll area = width[0] * a[0];
    for (ll i = 1; i < n; i++)
    {
        ll temp = a[i] * width[i];
        if (temp > area)
        {
            area = temp;
        }
    }
    return area;
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
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        cout << solve(a, n) << "\n";
    }
}