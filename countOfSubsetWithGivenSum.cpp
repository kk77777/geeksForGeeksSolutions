#include <bits/stdc++.h>
using namespace std;

int t[105][100005];

int noOfSubset(int a[], int n, int sum)
{

    if (sum == 0)
        return t[n][sum] + 1;
    if (sum != 0 && n == 0)
        return t[n][sum];

    if (a[n - 1] > sum)
        return t[n][sum] = noOfSubset(a, n - 1, sum);
    else if (a[n - 1] <= sum)
    {
        return t[n][sum] = noOfSubset(a, n - 1, sum) + noOfSubset(a, n - 1, sum - a[n - 1]);
    }
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