#include <bits/stdc++.h>
using namespace std;

int t[105][100005];

int noOfSubset(int a[], int n, int sum)
{

    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[n - 1] > sum)
                t[i][j] = t[i - 1][j];
            else if (a[n - 1] <= sum)
            {
                t[i][j] = t[i - 1][j] + t[i - 1][j - a[i - 1]];
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
        int a[n + 5];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum;
        cin >> sum;
        cout << noOfSubset(a, n, sum);
    }
}