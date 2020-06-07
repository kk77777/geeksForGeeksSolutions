bool check(vector<int> adj[], bool visited[], bool inStack[], int i)
{
    visited[i] = true;
    inStack[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (!visited[adj[i][j]] && check(adj, visited, inStack, adj[i][j]))
        {
            return true;
        }
        else
        {
            if (inStack[adj[i][j]])
                return true;
        }
    }
    inStack[i] = false;
    return false;
}

bool isCyclic(int n, vector<int> adj[])
{
    bool visited[n];
    bool inStack[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        inStack[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (check(adj, visited, inStack, i))
            {
                return true;
            }
        }
    }
    return false;
}