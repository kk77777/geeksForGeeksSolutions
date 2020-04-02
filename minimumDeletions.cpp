#include <bits/stdc++.h>
using namespace std;

int lps(string x, string y, int m, int n, vector<vector<int>> &t)
{

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
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return (m - t[m][n]);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string x, y;
        int m, n;
        cin >> x;
        y = x;
        reverse(y.begin(), y.end());
        m = x.length();
        n = y.length();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));
        cout << lps(x, y, m, n, t) << "\n";
    }
}