#include <iostream>
#include <vector>
#include <unordered_map>
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
        int n;
        cin >> n;
        vector<int> v;
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int k;
        cin >> k;
        for (int i = 0; i < n; i++)
        {
            if (mp[v[i]] != 0)
            {
                cnt += mp[v[i]];
                // cout<<mp[v[i]]<<"\n";
                mp[v[i]] = 0;
            }
            else
            {
                v[i] - k >= 0 ? mp[v[i] - k]++ : NULL;
                mp[v[i] + k]++;
            }
        }
        (k == 0) ? cout << cnt / 2 << "\n" : cout << cnt << "\n";
    }
}