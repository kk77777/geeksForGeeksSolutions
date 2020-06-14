void dfs(int x, vector<int> rg[], bool vis[])
{
    vis[x] = 1;
    for (auto i = rg[x].begin(); i != rg[x].end(); i++)
    {
        if (!vis[*i])
        {
            dfs(*i, rg, vis);
        }
    }
}

void tsort(vector<int> adj[], bool vis[], stack<int> &s, int x)
{
    vis[x] = 1;
    for (auto i = adj[x].begin(); i < adj[x].end(); i++)
    {
        if (vis[*i] == 0)
        {
            tsort(adj, vis, s, *i);
        }
    }
    s.push(x);
}

int kosaraju(int V, vector<int> adj[])
{
    bool vis[V] = {0};
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            tsort(adj, vis, s, i);
        }
    }
    vector<int> rg[V];
    for (int i = 0; i < V; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            rg[*j].push_back(i);
        }
    }
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
    }
    int scc = 0;
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if (!vis[t])
        {
            dfs(t, rg, vis);
            scc++;
        }
    }
    return