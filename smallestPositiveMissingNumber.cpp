#include <iostream>
#include <vector>
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
        vector<ll> v(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > 0 && x <= n)
            {
                v[x - 1] = -1;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (v[i] == 0)
            {
                flag = 1;
                cout << i + 1 << "\n";
                break;
            }
        }
        if (!flag)
        {
            cout << n + 1 << "\n";
        }
    }
}