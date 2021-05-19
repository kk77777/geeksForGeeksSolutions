// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

public:
    //Function to find the number of islands.

    void dfs(pair<int, int> p, vector<vector<char>> &grid, int n, int m, vector<vector<bool>> &vis)
    {
        vis[p.first][p.second] = 1;
        for (int i = 0; i < 8; i++)
        {
            int x = p.first + dr[i];
            int y = p.second + dc[i];

            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (vis[x][y])
                continue;
            if (grid[x][y] == '1')
                dfs({x, y}, grid, n, m, vis);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    dfs({i, j}, grid, n, m, vis);
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends