#include <bits/stdc++.h>
using namespace std;

bool flag = 0;

int printPath(vector<vector<int>> p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int dfs(int x, int y, vector<vector<int>> &v, vector<vector<int>> &p, int n)
{
    if (x < 0 || y < 0 || x >= n || y >= n || p[x][y] == 1 || flag == 1)
    {
        return 0;
    }

    p[x][y] = 1;

    if (x == n - 1 && y == n - 1)
    {
        flag = 1;
        printPath(p, n);
        return 0;
    }

    for (int i = 1; i <= v[x][y]; i++)
    {
        dfs(x, y + i, v, p, n);
        dfs(x + i, y, v, p, n);
    }

    p[x][y] = 0;
    return 0;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        flag = 0;
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        vector<vector<int>> p(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        int ans = dfs(0, 0, v, p, n);
        if (!flag)
            cout << -1 << "\n";
    }
}