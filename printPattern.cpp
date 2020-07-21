#include <bits/stdc++.h>
using namespace std;

int solve(int x, int n)
{
    if (x <= 0)
    {
        return x;
    }
    else
    {
        cout << x - 5 << " ";
        solve(x - 5, n);
    }
}

int solve2(int x, int n)
{
    if (x == n)
    {
        return 0;
    }
    else
    {
        cout << x + 5 << " ";
        solve2(x + 5, n);
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << n << " ";
        int x = solve(n, n);
        solve2(x, n);
        cout << "\n";
    }
}