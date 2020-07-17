#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vector<ll> a, b;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (a[i] * b[i]);
        }
        cout << sum << "\n";
    }
}