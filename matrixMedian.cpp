#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> v, int n, int m)
{
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, v[i][0]);
        mx = max(mx, v[i][m - 1]);
    }
    int req = (n * m + 1) / 2;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
        }
        if (cnt < req)
        {
            mn = mid + 1;
        }
        else
        {
            mx = mid;
        }
    }
    return mn;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        cout << findMedian(v, n, m) << "\n";
    }
}