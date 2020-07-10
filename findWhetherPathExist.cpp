#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
        return true;
    return false;
}

int dr[] = {0, -1, 1, 0};
int dc[] = {-1, 0, 0, 1};

int bfs(pair<int, int> src, pair<int, int> dt, int n, vector<vector<int>> &v)
{
    queue<pair<int, int>> q;
    q.push(src);
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int a, b;
        for (int i = 0; i < 4; i++)
        {
            a = temp.first + dr[i];
            b = temp.second + dc[i];
            if (isValid(a, b, n))
            {
                if (v[a][b] == 2)
                {
                    return true;
                }
                if (v[a][b] == 3)
                {
                    q.push({a, b});
                }
            }
        }
        v[temp.first][temp.second] = 0;
    }
    return false;
}

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        pair<int, int> src, dt;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
                if (v[i][j] == 1)
                {
                    src = {i, j};
                }
                if (v[i][j] == 2)
                {
                    dt = {i, j};
                }
            }
        }
        bfs(src, dt, n, v) ? cout << 1 : cout << 0;
        cout << "\n";
    }
}