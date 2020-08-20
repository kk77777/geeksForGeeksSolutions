#include <iostream>
#include <unordered_map>
#define ll long int

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        bool flag = 0;
        unordered_map<ll, ll> mp;
        for (auto i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mp[x]++;
        }
        for (auto i : mp)
        {
            if (i.second % 2 != 0)
            {
                cout << i.first << "\n";
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << 0 << "\n";
    }
}