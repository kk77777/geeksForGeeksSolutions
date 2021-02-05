// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool isSafe(bool graph[101][101], int n, int m, vector<int> &col, int v, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && col[i] == c)
        {
            return false;
        }
    }
}

bool isPossible(bool graph[101][101], int n, int m, vector<int> &col, int v)
{
    if (v == n)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(graph, n, m, col, v, c))
        {
            col[v] = c;
            if (isPossible(graph, n, m, col, v + 1))
            {
                return true;
            }
            col[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> col(V + 1, 0);
    return isPossible(graph, V, m, col, 0);
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends