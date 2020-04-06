#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        ll n;
        cin >> n;

        ll minm = INT_MAX;
        ll index = 0;
        ll temp;
        ll x = 0;

        for (auto i = 0; i < n; ++i)
        {
            temp = x;
            cin >> x;
            if (x <= minm && temp != x)
            {
                minm = x;
                index = i;
            }
        }
        cout << index << "\n";
    }
    return 0;
}