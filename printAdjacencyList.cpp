#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, e;
        cin >> n >> e;
        vector<int> adj[n];
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cout << i;
            for (auto j = adj[i].begin(); j != adj[i].end(); j++)
            {
                cout << "-> " << *j;
            }
            cout << "\n";
        }
    }
}