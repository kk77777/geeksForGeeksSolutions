#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long int

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
        vector<ll> v(n, 0);
        unordered_map<ll, ll> mp;
        for (auto i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        for (auto i = 0; i < n; i++)
        {
            if (mp[v[i]] == 1)
            {
                cout << v[i] << "\n";
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << 0 << "\n";
    }
}