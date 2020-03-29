#include <bits/stdc++.h>
using namespace std;
int t[105][100005];

bool isSubsetSum(int a[], int n, int sum)
{

    for (int i = 0; i <= n; i++)
    {
        t[i][0] = true;
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

        memset(t, 0, sizeof t);

        int n;
        cin >> n;
        int a[n + 4];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 2 != 0)
        {
            cout << "NO\n";
        }
        else
        {
            isSubsetSum(a, n, sum / 2) ? cout << "YES\n" : cout << "NO\n";
        }
    }
}