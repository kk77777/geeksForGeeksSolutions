#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int res(vector<int> v, int n, int k)
{
    int sum = 0, ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == k)
        {
            ans = i + 1;
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
        if (mp.find(sum - k) != mp.end())
        {
            if (ans < i - mp[sum - k])
            {
                ans = i - mp[sum - k];
            }
        }
    }
    return ans;
}

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << res(v, n, k) << "\n";
    }
}
