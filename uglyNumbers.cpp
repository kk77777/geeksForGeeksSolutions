#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n + 5];
        a[0] = 1;
        ll i2 = 0, i3 = 0, i5 = 0;
        ll nu = 1;
        ll nm2 = 2, nm3 = 3, nm5 = 5;

        for (auto i = 1; i < n; i++)
        {
            nu = min(nm2, min(nm3, nm5));

            a[i] = nu;
            if (nu == nm2)
            {
                i2 = i2 + 1;
                nm2 = 2 * a[i2];
            }
            if (nu == nm3)
            {
                i3 = i3 + 1;
                nm3 = 3 * a[i3];
            }
            if (nu == nm5)
            {
                i5 = i5 + 1;
                nm5 = 5 * a[i5];
            }
        }
        cout << nu << "\n";
    }
}