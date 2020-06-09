int cnt = 0;
int dr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[] = {-1, -1, -1, 0, 0, 1, 1, 1};
void check(pair<int, int> p, vector<int> adj[], int n, int m, bool vis[][100])
{

    vis[p.first][p.second] = 1;
    for (auto i = 0; i < 8; ++i)
    {
        int x = p.first + dr[i];
        int y = p.second + dc[i];

        if (x >= n || x < 0 || y >= m || y < 0)
            continue;

        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        if (adj[x][y] == 1)
        {
            check({x, y}, adj, n, m, vis);
        }
    }
}

int findIslands(vector<int> adj[], int n, int m)
{
    cnt = 0;
    bool vis[100][100] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (!vis[i][j] && adj[i][j] == 1)
            {
                cnt++;
                pair<int, int> p = {i, j};
                check(p, adj, n, m, vis);
            }
        }
    }
    return cnt;
}