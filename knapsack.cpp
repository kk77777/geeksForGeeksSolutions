#include <bits/stdc++.h>
using namespace std;
int t[1005][1005];

int knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (t[n][w] != -1)
        return t[n][w];

    if (wt[n - 1] <= w)
    {
        return t[n][w] = max((val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1)), knapsack(wt, val, w, n - 1));
    }
    else if (wt[n - 1] > w)
        return t[n][w] = knapsack(wt, val, w, n - 1);
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