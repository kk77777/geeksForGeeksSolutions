#include <iostream>
#include <vector>
#define ll long int
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        int r, m;
        cin >> n;
        vector<ll> a(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a[x]++;
        }
        for (ll i = 1; i <= n; i++)
        {
            if (a[i] > 1)
                r = i;
            if (a[i] == 0)
                m = i;
        }
        cout << r << " " << m << "\n";
    }
}