// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

    void toposort(int x, stack<int> &s, vector<bool> &vis, vector<int> adj[])
    {
        vis[x] = 1;
        for (auto it : adj[x])
        {
            if (!vis[it])
                toposort(it, s, vis, adj);
        }
        s.push(x);
    }

    void revDfs(int x, vector<bool> &vis, vector<int> transpose[])
    {
        vis[x] = 1;
        for (auto it : transpose[x])
        {
            if (!vis[it])
                revDfs(it, vis, transpose);
        }
    }

public:
    //Function to find number of strongly connected components in the graph.

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> s;
        vector<bool> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                toposort(i, s, vis, adj);
            }
        }
        vector<int> transpose[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }

        int cnt = 0;
        while (!s.empty())
        {
            int temp = s.top();
            s.pop();
            if (!vis[temp])
            {
                cnt++;
                revDfs(temp, vis, transpose);
            }
        }
        return cnt;
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
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends