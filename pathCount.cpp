// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    // } Driver Code Ends

    //User function Template for C++

    // you are required to complete this function
    // the function should return the total possible paths possible from s to d
    //This function is a member of the Graph class.Expand the driver code to see other members.
    bool vis[105];

    void dfs(int s, int d, int &cnt)
    {
        if (s == d)
        {
            vis[d] = 0;
            cnt++;
            return;
        }
        else
        {
            vis[s] = 1;
            for (int i : adj[s])
            {
                if (!vis[i])
                {
                    dfs(i, d, cnt);
                }
            }
            vis[s] = 0;
        }
    }

    int countPaths(int s, int d)
    {
        // Code here
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        dfs(s, d, cnt);
        return cnt;
    }

    // { Driver Code Starts.
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e, x, y, s, d;
        cin >> n >> e;
        Graph g(n);
        while (e--)
        {
            cin >> x >> y;
            g.addEdge(x, y);
        }
        cin >> s >> d;
        cout << g.countPaths(s, d) << "\n";
    }
    return 0;
}
// } Driver Code Ends