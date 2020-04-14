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
        priority_queue<ll, vector<ll>, greater<ll>> p;
        for (auto i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            p.push(x);
        }
        ll sum = 0;
        while (p.size() >= 2)
        {
            ll first = p.top();
            p.pop();
            ll second = p.top();
            p.pop();
            sum = sum + first + second;
            p.push(first + second);
        }
        cout << sum << "\n";
    }
}