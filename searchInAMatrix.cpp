#include <bits/stdc++.h>
using namespace std;

int solve(int a[][35], int m, int n, int x)
{
    int i = 0, j = m - 1;
    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (a[i][j] == x)
        {
            return 1;
        }
        else if (a[i][j] < x)
        {
            i++;
        }
        else if (a[i][j] > x)
        {
            j--;
        }
    }
    return -1;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        int a[35][35];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        int x;
        cin >> x;
        if (solve(a, m, n, x) == -1)
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
}