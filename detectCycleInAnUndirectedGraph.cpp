// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfs(vector<int> g[], vector<bool> &vis, int src)
{
    vis[src] = true;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (auto i : g[temp.first])
        {
            // cout<<"i = "<<i<<"\n";
            if (vis[i] && i != temp.second)
                return true;
            else if (!vis[i])
            {
                q.push({i, temp.first});
                vis[i] = true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
    // Your code here
    vector<bool> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(g, vis, i))
                return true;
        }
    }
    return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int V, E;
        cin >> V >> E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V) << endl;
    }
}
// } Driver Code Ends