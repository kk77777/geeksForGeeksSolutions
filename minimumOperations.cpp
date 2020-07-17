#include <bits/stdc++.h>
using namespace std;

int solve(int n, int cnt)
{
    if (n == 2)
    {
        return cnt;
    }
    if (n % 2 == 0)
    {
        cnt++;
        solve(n / 2, cnt);
    }
    else
    {
        cnt++;
        solve(n - 1, cnt);
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
        int cnt = 0;
        cout << solve(n, cnt) + 2 << "\n";
    }
}