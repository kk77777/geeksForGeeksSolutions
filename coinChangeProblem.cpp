#include <bits/stdc++.h>
using namespace std;

int t[305][305];

int coinChange(int n, int a[], int csum)
{

    for (int i = 0; i <= csum; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= csum; j++)
        {
            if (a[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] + t[i][j - a[i - 1]];
            }
            else if (a[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][csum];
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(t, -1, sizeof t);
        int n, csum;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> csum;

        cout << coinChange(n, a, csum) << "\n";
    }
}