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
        vector<ll> m(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            m[x]++;
        }
        for (ll i = 1; i <= n; i++)
        {
            cout << m[i] << " ";
        }
        cout << "\n";
    }
}