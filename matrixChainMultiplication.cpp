#include <bits/stdc++.h>
using namespace std;
int t[105][105];

int solve(int a[], int i, int j)
{
    if (i >= j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(a, i, k) + solve(a, k + 1, j) + (a[i - 1] * a[k] * a[j]);
        if (mn > temp)
            mn = temp;
    }

    return t[i][j] = mn;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(t, -1, sizeof t);
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a, 1, n - 1) << "\n";
    }
}