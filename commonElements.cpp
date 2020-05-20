#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        bool flag = 0;

        ll x, y, z;
        cin >> x >> y >> z;

        set<ll> a;
        set<ll> b;
        set<ll> c;
        for (auto i = 0; i < x; i++)
        {
            ll q;
            cin >> q;
            a.insert(q);
        }
        for (auto i = 0; i < y; i++)
        {
            ll q;
            cin >> q;
            b.insert(q);
        }
        for (auto i = 0; i < z; i++)
        {
            ll q;
            cin >> q;
            c.insert(q);
        }

        set<ll>::iterator it1;
        set<ll>::iterator it2;
        set<ll>::iterator it3;

        it1 = a.begin();
        it2 = b.begin();
        it3 = c.begin();

        while (it1 != a.end() && it2 != b.end() && it3 != c.end())
        {
            // cout<<*it1<<" "<<*it2<<" "<<*it3<<"\n";
            if (*it1 == *it2 && *it2 == *it3)
            {
                flag = 1;
                cout << *it1 << " ";
                it1++;
                it2++;
                it3++;
            }
            else if (*it1 < *it2)
            {
                it1++;
            }
            else if (*it2 < *it3)
            {
                it2++;
            }
            else
            {
                it3++;
            }
        }

        if (flag == 0)
        {
            cout << -1;
        }
        cout << "\n";
    }
}