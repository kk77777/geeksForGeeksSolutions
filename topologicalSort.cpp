void topsrt(int i, bool vis[], vector<int> adj[], stack<int> &s)
{
    vis[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (!vis[adj[i][j]])
        {
            topsrt(adj[i][j], vis, adj, s);
        }
    }
    s.push(i);
}

int *topoSort(int n, vector<int> adj[])
{

    bool vis[n] = {0};
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topsrt(i, vis, adj, s);
        }
    }
    int *a = new int[n];
    int k = 0;
    while (!s.empty())
    {
        a[k] = s.top();
        s.pop();
        k++;
    }
    return a;
}