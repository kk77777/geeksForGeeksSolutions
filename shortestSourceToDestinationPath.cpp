#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}

int dr[] = {0, -1, 1, 0};
int dc[] = {-1, 0, 0, 1};

int bfs(int x, int y, int n, int m, vector<vector<int>> &v)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    map<pair<int, int>, int> d;
    d[{0, 0}] = 0;
    int ans = -1;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        if (temp.first == x && temp.second == y)
        {
            ans = d[temp];
            break;
        }
        int a, b;
        for (int i = 0; i < 4; i++)
        {
            a = temp.first + dr[i];
            b = temp.second + dc[i];
            if (isValid(a, b, n, m))
            {
                if (v[a][b] == 1)
                {
                    d[{a, b}] = d[temp] + 1;
                    q.push({a, b});
                }
            }
        }
        v[temp.first][temp.second] = 0;
    }
    return ans;
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
        int ans;
        int x, y;
        cin >> x >> y;
        if (v[0][0] == 0 || v[x][y] == 0)
        {
            ans = -1;
        }
        else
        {
            ans = bfs(x, y, n, m, v);
        }
        cout << ans << "\n";
    }
}