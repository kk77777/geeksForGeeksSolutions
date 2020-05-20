#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if (n <= 6)
        return n;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= 6; i++)
    {
        v[i - 1] = i;
    }
    for (int i = 7; i <= n; i++)
    {
        v[i - 1] = max(2 * v[i - 4], max(3 * v[i - 5], 4 * v[i - 6]));
    }

    return v[n - 1];
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}