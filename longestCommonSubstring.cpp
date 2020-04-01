#include <bits/stdc++.h>
using namespace std;

int t[205][205];

int lcs(string x, string y, int m, int n)
{
    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
                ans = max(ans, t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
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
        memset(t, -1, sizeof t);
        string x, y;
        int m, n;
        cin >> m >> n;
        cin >> x;
        cin >> y;

        cout << lcs(x, y, m, n) << "\n";
    }
}