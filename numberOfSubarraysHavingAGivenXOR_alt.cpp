#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a[100], n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> k;
        unordered_map<int, int> mp;
        int xorr = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            xorr = xorr ^ a[i];
            if (xorr == k)
                cnt++;
            if (mp.find(xorr ^ k) != mp.end())
            {
                cnt += mp[xorr ^ k];
            }
            mp[xorr]++;
        }
        cout << cnt << "\n";
    }
    return 0;
}