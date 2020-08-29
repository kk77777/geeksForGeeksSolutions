#include <bits/stdc++.h>
using namespace std;

bool vis[30][30];

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, m;

bool isValid(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
        return true;
    return false;
}

int minMoves(pair<int, int> s, pair<int, int> d)
{
    vis[s.first][s.second] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({s, 0});
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        if (p.first.first == d.first && p.first.second == d.second)
            return p.second;
        for (int i = 0; i < 8; i++)
        {
            int x = p.first.first + dx[i];
            int y = p.first.second + dy[i];

            if (isValid(x, y) && !vis[x][y])
            {
                vis[x][y] = true;
                q.push({{x, y}, p.second + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        pair<int, int> s, d;
        cin >> s.first >> s.second >> d.first >> d.second;
        cout << minMoves(s, d) << "\n";
    }
}