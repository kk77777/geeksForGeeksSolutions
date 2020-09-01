#include <bits/stdc++.h>
using namespace std;

int a[100];
int dp[100][100], x[100][100];

void print(int i, int j)
{
    if (i == j)
    {
        cout << char(i + 'A' - 1);
        return;
    }
    cout << "(";
    print(i, x[i][j]);
    print(x[i][j] + 1, j);
    cout << ")";
}

int solve(int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(i, k) + solve(k + 1, j) + (a[i - 1] * a[k] * a[j]);
        if (temp < mn)
        {
            mn = temp;
            x[i][j] = k;
        }
    }

    return dp[i][j] = mn;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        // int a[n+1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(1, n - 1);
        print(1, n - 1);
        cout << "\n";
    }
}