#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll x, y;
        cin >> x >> y;
        vector<ll> a, b;
        for (ll i = 0; i < x; i++)
        {
            ll z;
            cin >> z;
            a.push_back(z);
        }
        for (ll i = 0; i < y; i++)
        {
            ll z;
            cin >> z;
            b.push_back(z);
        }
        ll i = 0, j = 0;
        while (i < x && j < y)
        {
            if (a[i] > b[j])
            {
                cout << b[j] << " ";
                j++;
            }
            else if (a[i] < b[j])
            {
                cout << a[i] << " ";
                i++;
            }
            else
            {
                cout << a[i] << " " << a[i] << " ";
                i++;
                j++;
            }
        }
        while (i < x)
        {
            cout << a[i] << " ";
            i++;
        }
        while (j < y)
        {
            cout << b[j] << " ";
            j++;
        }
        cout << "\n";
    }
}