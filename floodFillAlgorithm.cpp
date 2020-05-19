#include <bits/stdc++.h>
using namespace std;

int a[105][105];
int n, m;

int dfs(int x, int y, int gc, int cc)
{
    if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] != cc)
        return 0;
    a[x][y] = gc;
    dfs(x - 1, y, gc, cc);
    dfs(x, y - 1, gc, cc);
    dfs(x, y + 1, gc, cc);
    dfs(x + 1, y, gc, cc);
}

int main()
{
    //code
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        int x, y, gc, cc;
        cin >> x >> y >> gc;
        cc = a[x][y];
        dfs(x, y, gc, cc);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
        }
        cout << "\n";
    }
}