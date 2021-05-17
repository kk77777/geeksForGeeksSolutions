// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    bool checkCycle(int x, vector<int> adj[], vector<bool> &vis, vector<bool> &dvis)
    {
        vis[x] = true;
        dvis[x] = true;
        for (auto i : adj[x])
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dvis))
                {
                    return true;
                }
            }
            else if (dvis[i])
            {
                return true;
            }
        }
        dvis[x] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> vis(V + 1, 0);
        vector<bool> dvis(V + 1, 0);
        vis.assign(V, 0);
        dvis.assign(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (checkCycle(i, adj, vis, dvis))
            {
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends