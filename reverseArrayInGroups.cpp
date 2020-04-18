#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < n; i += k)
        {
            int left = i;

            int right = min(i + k - 1, n - 1);

            while (left < right)
                swap(v[left++], v[right--]);
        }
        for (ll i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}