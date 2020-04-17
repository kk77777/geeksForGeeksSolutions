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
        bool flag = false;
        for (auto i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll i = 0, j = n - 1;
        ll fsum = v[0], bsum = v[n - 1];
        while (i < j)
        {
            if (fsum < bsum)
            {
                i++;
                fsum += v[i];
            }
            else if (fsum > bsum)
            {
                j--;
                bsum += v[j];
            }
            else if (fsum == bsum)
            {
                if (i == j - 1)
                    flag = true;
                i++;
                j--;
                if (i < j)
                {
                    fsum += v[i];
                    bsum += v[j];
                }
            }
        }
        if (fsum == bsum && flag == false)
        {
            cout << i + 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}