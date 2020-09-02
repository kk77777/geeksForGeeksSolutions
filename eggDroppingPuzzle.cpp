#include <bits/stdc++.h>
using namespace std;

int dp[50][50];

int solve(int n, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (n <= 1)
        return f;

    if (dp[n][f] != -1)
        return dp[n][f];

    int mn = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(solve(n - 1, k - 1), solve(n, f - k));
        mn = min(mn, temp);
    }

    return dp[n][f] = mn;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(dp, -1, sizeof(dp));
        int n, f;
        cin >> n >> f;
        cout << solve(n, f) << "\n";
    }
}