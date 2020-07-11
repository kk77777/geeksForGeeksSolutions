#include <bits/stdc++.h>
using namespace std;
#define ll long int
#define inf 10000000

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<ll>> v(n, vector<ll>(n, inf));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (v[i][j] > (v[i][k] + v[k][j]))
                    {
                        v[i][j] = v[i][k] + v[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 10000000)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << v[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
}