#include <bits/stdc++.h>
using namespace std;

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

bool isValid(int x, int y, int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
        return true;
    return false;
}

int dijkstra(vector<vector<int>> v, int n)
{

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({v[0][0], {0, 0}});

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = v[0][0];

    while (!pq.empty())
    {
        pair<int, pair<int, int>> t = pq.top();
        pq.pop();
        int a, b;
        for (int i = 0; i < 4; i++)
        {
            a = t.second.first + dr[i];
            b = t.second.second + dc[i];
            if (isValid(a, b, n))
            {
                if (dist[a][b] > (dist[t.second.first][t.second.second] + v[a][b]))
                {
                    dist[a][b] = dist[t.second.first][t.second.second] + v[a][b];
                    pq.push({dist[a][b], {a, b}});
                }
            }
        }
    }
    cout << dist[n - 1][n - 1] << "\n";
    return 0;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        dijkstra(v, n);
    }
}