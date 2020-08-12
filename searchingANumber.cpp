#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, k;
        bool flag = 0;
        cin >> n >> k;
        vector<ll> v;
        for (auto i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (auto i = 0; i < n; i++)
        {
            if (v[i] == k)
            {
                cout << i + 1 << "\n";
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << "\n";
        }
    }
}