#include <bits/stdc++.h>
using namespace std;

bool t[100][100];

bool isSubsetSum(int a[], int n, int sum)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else if (a[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - a[i - 1]]) || (t[i - 1][j]);
            }
        }
    }
    return t[n][sum];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {

        memset(t, false, sizeof t);

        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum;
        cin >> sum;
        isSubsetSum(a, n, sum) ? cout << "YES\n" : cout << "NO\n";
    }
}