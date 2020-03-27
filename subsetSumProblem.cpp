#include <bits/stdc++.h>
using namespace std;

bool partition(int a[], int n)
{

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum % 2 != 0)
        return false;

    bool p[sum / 2 + 1][n + 1];

    for (int i = 0; i <= n; i++)
        p[0][i] = true;

    for (int i = 0; i <= sum / 2; i++)
        p[i][0] = false;

    for (int i = 1; i <= sum / 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = p[i][j - 1];
            if (i >= a[j - 1])
                p[i][j] = p[i][j - 1] || p[i - a[j - 1]][j - 1];
        }
    }
    return p[sum / 2][n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (partition(a, n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}