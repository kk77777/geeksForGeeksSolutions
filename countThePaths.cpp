#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int cnt = 0;
void dfs(int s, int d, vector<int> adj[], vector<bool> &vis)
{
    if (s == d)
    {
        cnt++;
        return;
    }
    vis[s] = 1;
    for (int i : adj[s])
    {
        if (!vis[i])
        {
            dfs(i, d, adj, vis);
        }
    }
    vis[s] = 0;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        cnt = 0;
        int n, e;
        cin >> n >> e;
        vector<int> adj[n];
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        int s, d;
        cin >> s >> d;
        vector<bool> vis(n, 0);
        dfs(s, d, adj, vis);
        cout << cnt << "\n";
    }
    // #ifndef ONLINE_JUDGE
    //     cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}