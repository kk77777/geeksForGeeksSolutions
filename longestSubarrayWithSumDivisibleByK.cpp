#include <iostream>
#include <vector>
#include <unordered_map>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int res(vector<int> v, int n, int k)
{
    int sum = 0, ans = 0;
    unordered_map<int, int> mp;
    vector<int> m(n, 0);

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        m[i] = ((sum % k) + k) % k;
    }

    for (int i = 0; i < n; i++)
    {
        if (m[i] == 0)
        {
            ans = i + 1;
        }
        else if (mp.find(m[i]) == mp.end())
        {
            mp[m[i]] = i;
        }
        else
        {
            if (ans < i - mp[m[i]])
            {
                ans = i - mp[m[i]];
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