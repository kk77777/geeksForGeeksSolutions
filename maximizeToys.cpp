#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n, int k)
{
    int price = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] + price <= k)
        {
            cnt++;
            price += v[i];
        }
        else
        {
            return cnt;
        }
    }
}

int main()
{
    int tc;
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
        sort(v.begin(), v.end());
        cout << solve(v, n, k) << "\n";
    }
}