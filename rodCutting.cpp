#include <bits/stdc++.h>
using namespace std;

int t[105][105];

int rodCutting(int n, int length[], int price[])
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (length[i - 1] <= j)
            {
                t[i][j] = max(t[i - 1][j], price[i - 1] + t[i][j - length[i - 1]]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][n];
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
        int length[n + 5], price[n + 5];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        for (int i = 0; i < n; i++)
        {
            length[i] = i + 1;
        }
        cout << rodCutting(n, length, price) << "\n";
    }
}