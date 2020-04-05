#include <bits/stdc++.h>
#define ll long int
using namespace std;

ll binarySearch(ll a[], ll s, ll e, ll k)
{
    if (s <= e)
    {
        ll mid = s + (e - s) / 2;

        if (a[mid] == k)
        {
            return 1;
        }
        else if (a[mid] < k)
            return binarySearch(a, mid + 1, e, k);
        else
            return binarySearch(a, s, mid - 1, k);
    }
    return 0;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        binarySearch(a, 0, n - 1, k) ? cout << 1 << "\n" : cout << -1 << "\n";
    }
}