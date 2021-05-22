// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

    struct node
    {
        int u, v, wt;
        node(int x, int y, int weight)
        {
            u = x;
            v = y;
            wt = weight;
        }
    };

    int findParent(int x, vector<int> &parent)
    {
        if (x == parent[x])
            return x;
        return parent[x] = findParent(parent[x], parent);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(u, parent);
        v = findParent(v, parent);
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    static bool comp(node a, node b)
    {
        return a.wt < b.wt;
    }
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<node> graph;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                int u, v, wt;
                u = i;
                v = adj[i][j][0];
                wt = adj[i][j][1];
                graph.push_back(node(u, v, wt));
            }
        }

        sort(graph.begin(), graph.end(), comp);

        vector<int> rank(n, 0);
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int cost = 0;
        // vector<pair<int,int>>mst;
        for (auto it : graph)
        {
            if (findParent(it.u, parent) != findParent(it.v, parent))
            {
                cost += it.wt;
                unionSet(it.u, it.v, parent, rank);
            }
        }
        return cost;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends