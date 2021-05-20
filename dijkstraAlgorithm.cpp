#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, source;
        cin >> n >> m >> source;
        vector<pair<int, int>> adj[n + 1];
        int a, b, wt;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> wt;
            adj[a].push_back({b, wt});
            adj[b].push_back({a, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(n + 1, INT_MAX);
        distTo[source] = 0;
        pq.push({0, source});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for (auto it : adj[prev])
            {
                int next = it.first;
                int ndist = it.second;
                if (distTo[next] > (distTo[prev] + ndist))
                {
                    distTo[next] = distTo[prev] + ndist;
                    pq.push({distTo[next], next});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << distTo[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}