#include <bits/stdc++.h>
using namespace std;
int t[1005][1005];

int knapsack(int wt[], int val[], int w, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), (t[i - 1][j]));
            }
        }
    }
    return t[n][w];
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(t, -1, sizeof t);
        int n, w;
        cin >> n;
        cin >> w;
        int val[n + 5], wt[n + 5];
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        cout << knapsack(wt, val, w, n) << "\n";
    }
}