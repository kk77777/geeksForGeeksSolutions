// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int cnt = 0, res = INT_MAX;
    int dfs(int s, vector<int> adj[], vector<bool> &vis, int n)
    {
        // cout << "s = " << s << "\n";
        vis[s] = 1;
        for (int i : adj[s])
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis, n);
            }
        }
        if (cnt == n - 1)
        {
            res = min(res, s);
        }
    }

    int findMotherVertex(int n, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            vis.assign(n, 0);
            dfs(i, adj, vis, n);
        }

        if (res == INT_MAX)
            res = -1;
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        int ans = obj.findMotherVertex(V, adj);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends