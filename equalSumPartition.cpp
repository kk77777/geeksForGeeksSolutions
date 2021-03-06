#include <bits/stdc++.h>
using namespace std;
int t[105][100005];

bool isSubsetSum(int a[], int n, int sum)
{

    if (sum == 0)
        return true;

    if (n == 0 && sum != 0)
        return false;

    if (t[n][sum] != 0)
        return t[n][sum];

    if (a[n - 1] > sum)
        return isSubsetSum(a, n - 1, sum);

    else if (a[n - 1] <= sum)
    {
        return t[n][sum] = (isSubsetSum(a, n - 1, sum - a[n - 1])) || (isSubsetSum(a, n - 1, sum));
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