#include <bits/stdc++.h>
using namespace std;

bool vis[31];

int minThrow(vector<int> &v)
{

    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[0] = true;

    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        if (x == 30)
        {
            return y;
        }
        for (int i = x + 1; i <= x + 6 && i <= 30; i++)
        {
            if (!vis[i])
            {
                if (v[i] != -1)
                {
                    q.push({v[i], y + 1});
                }
                else
                {
                    q.push({i, y + 1});
                }
                vis[i] = true;
            }
        }
    }
    return 0;
}

int main()
{

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v(31, -1);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x] = y;
        }
        cout << minThrow(v) << "\n";
    }
}