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
        for (auto i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll max = -1;
        ll i = v.size();
        stack<ll> s;
        while (i > 0)
        {
            i--;
            if (v[i] >= max)
            {
                s.push(v[i]);
                max = v[i];
            }
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
    }
}