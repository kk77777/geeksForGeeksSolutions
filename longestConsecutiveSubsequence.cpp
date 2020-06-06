#include <bits/stdc++.h>
using namespace std;

int result(int n, vector<int> v)
{
    int ans = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(v[i] - 1) == s.end())
        {
            int j = v[i];

            while (s.find(j) != s.end())
            {
                j++;
            }
            ans = max(ans, j - v[i]);
        }
    }
    return ans;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << result(n, v) << "\n";
    }
}