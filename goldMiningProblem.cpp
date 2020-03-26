#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n + 5][m + 5];
        int g[n + 5][m + 5];

        memset(g, 0, sizeof g);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int j = m - 1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                int r, rd, ru;
                if (j == m - 1)
                {
                    r = 0;
                }
                else
                {
                    r = g[i][j + 1];
                }
                if (j == m - 1 || i == 0)
                {
                    ru = 0;
                }
                else
                {
                    ru = g[i - 1][j + 1];
                }
                if (j == m - 1 || i == n - 1)
                {
                    rd = 0;
                }
                else
                {
                    rd = g[i + 1][j + 1];
                }

                g[i][j] = a[i][j] + max(r, max(ru, rd));
            }
        }
        int res = g[0][0];

        for (int i = 1; i < n; i++)
        {
            res = max(res, g[i][0]);
        }
        cout << res << "\n";
    }
}