// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in an undirected graph.

    bool checkCycle(int x, int parent, vector<int> adj[], vector<bool> &vis)
    {
        vis[x] = true;
        for (auto i : adj[x])
        {
            if (!vis[i])
            {
                if (checkCycle(i, x, adj, vis))
                    return true;
            }
            else if (i != parent)
                return true;
        }
        return false;
    }

    bool isCycle(int n, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends