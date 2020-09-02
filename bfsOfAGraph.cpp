// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<int> g[], int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> res = bfs(adj, N);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends

/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/

bool vis[10005];
vector<int> bfs(vector<int> g[], int N)
{
    // Your code here
    memset(vis, 0, sizeof(vis));
    vector<int> v;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int temp = q.front();
        v.push_back(temp);
        q.pop();

        for (auto i : g[temp])
        {
            if (!vis[i])
            {
                vis[i] = true;
                q.push(i);
            }
        }
    }
    return v;
}